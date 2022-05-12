#include "MixerOutput.h"
#include <math.h>
#include <thread>

#include "AudioSettings.h"

MixerOutput *MixerOutput::instance = nullptr;
std::mutex MixerOutput::initMutex;

MixerOutput::MixerOutput() { wvTime = 0.0f; }

MixerOutput::~MixerOutput() {
  Pa_CloseStream(stream);
  Pa_Terminate();
}

void MixerOutput::addMidiPlayback(MidiPlayback *playback) {
  if (std::none_of(midiPlaybacks.begin(),
                   midiPlaybacks.end(),
                   [&](MidiPlayback *pl) { return pl == playback; })) {
    midiPlaybacks.push_back(playback);
  }
}

void MixerOutput::removeMidiPlayback(MidiPlayback *playback) {
  midiPlaybacks.remove(playback);
}

void MixerOutput::addSynthesizer(BasicSynthesizer *synthesizer) {
  if (std::none_of(
          synthesizers.begin(),
          synthesizers.end(),
          [&](BasicSynthesizer *synth) { return synth == synthesizer; })) {
    synthesizers.push_back(synthesizer);
  }
}

void MixerOutput::removeSynthesizer(BasicSynthesizer *synthesizer) {
  synthesizers.remove(synthesizer);
}

void MixerOutput::addTimeReceiver(ITimeReceiver *receiver) {
  if (std::none_of(timeReceivers.begin(),
                   timeReceivers.end(),
                   [&](ITimeReceiver *rec) { return rec == receiver; })) {
    timeReceivers.push_back(receiver);
  }
}

void MixerOutput::removeTimeReceiver(ITimeReceiver *receiver) {
  timeReceivers.remove(receiver);
}

void MixerOutput::Initialize() {
  PaError err;

  err = Pa_Initialize();
  if (err != paNoError)
    qDebug() << "Init error";
  else
    qDebug() << "Init success";

  MixerOutput::outputParameters.device = Pa_GetDefaultOutputDevice();
  if (outputParameters.device == paNoDevice) {
    qDebug() << "Error: No default output device.\n";
  } else
    qDebug() << "Ouput device success";
  outputParameters.channelCount = 2;
  outputParameters.sampleFormat = paFloat32;
  outputParameters.suggestedLatency =
      Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
  outputParameters.hostApiSpecificStreamInfo = NULL;

  err = Pa_OpenStream(&stream,
                      NULL,
                      &outputParameters,
                      AudioSettings::SAMPLE_RATE,
                      AudioSettings::BUFFER_SIZE,
                      paClipOff,
                      OutputCallback,
                      NULL);
  qDebug() << "Open stream success";
  err = Pa_StartStream(stream);
  if (err != paNoError)
    qDebug() << "Start error";
  else
    qDebug() << "Start success";
}

MixerOutput *MixerOutput::Instance() {
  std::lock_guard<std::mutex> lock(initMutex);
  if (instance == nullptr) {
    instance = new MixerOutput();
  }
  return instance;
}

int MixerOutput::OutputCallback(const void *inputBuffer,
                                void *outputBuffer,
                                unsigned long framesPerBuffer,
                                const PaStreamCallbackTimeInfo *timeInfo,
                                PaStreamCallbackFlags statusFlags,
                                void *userData) {
  if (statusFlags == paOutputUnderflow) {
    return paContinue;
  }

  for (auto receiver : MixerOutput::Instance()->timeReceivers) {
    receiver->UpdateTime(MixerOutput::Instance()->wvTime);
  }

  for (const auto &midi : MixerOutput::Instance()->midiPlaybacks) {
    midi->check((float)framesPerBuffer / AudioSettings::SAMPLE_RATE);
    MixerOutput::Instance()->bpm = midi->BPM;
  }

  float *out = (float *)outputBuffer;
  memset(out, 0, framesPerBuffer * 2);
  int ind = 0;
  for (unsigned long sample = 0; sample < framesPerBuffer; sample++) {
    out[ind] = 0;
    out[ind + 1] = 0;
    ind += 2;
  }
  float synthGain = (1.0f / MixerOutput::Instance()->synthesizers.size());
  for (auto synth : MixerOutput::Instance()->synthesizers) {
    float *synthOutput = synth->getRawOutput();
    int ind = 0;
    for (unsigned long sample = 0; sample < framesPerBuffer; sample++) {
      out[ind] += synthOutput[ind] * synthGain;
      out[ind + 1] += synthOutput[ind + 1] * synthGain;
      ind += 2;
    }
  }
  Q_UNUSED(inputBuffer);
  Q_UNUSED(timeInfo);
  Q_UNUSED(statusFlags);
  Q_UNUSED(userData);
  MixerOutput::Instance()->wvTime +=
      (float)framesPerBuffer / AudioSettings::SAMPLE_RATE;
  return paContinue;
}
