#include "Chorus.h"
#include <math.h>

Chorus::Chorus(unsigned int numSamples,
               const MinMax<float> &delay,
               const MinMax<float> &sweepWidth) {
  this->delay = delay;
  this->sweepWidth = sweepWidth;
  this->numSamples = numSamples;
  bufferPosition = 0;
  chorusTimeSampled = (delay.max + sweepWidth.max) * AudioSettings::SAMPLE_RATE;
  unsigned int bufferSize = round(chorusTimeSampled);
  chorusBuffer = std::unique_ptr<AudioChannel>(new AudioChannel(2, bufferSize));
}

Chorus::~Chorus() = default;

void Chorus::Apply(AudioChannel &audioChannel) {
  if (bypass) {
    return;
  }

  unsigned int localWritePosition = 0;
  float localRate;

  for (uint32_t channelIndex = 0;
       channelIndex < audioChannel.getNumberOfChannels();
       channelIndex++) {
    localWritePosition = bufferPosition;
    localRate = rate;
    unsigned int bufferSize = audioChannel.getSamplesPerChannel();

    for (uint32_t sample = 0; sample < numSamples; ++sample) {
      const float in = audioChannel.getChannelBuffer(channelIndex)->at(sample);
      float out = 0.0f;
      float phase = -2.0f / voices;
      if (channelIndex == 1) {
        phase -= stereoPhase;
      }
      float phaseStep = -phase;
      float voiceWeight = 1.0f / voices;

      for (int voice = 0; voice < voices; ++voice) {
        float localDelayTime =
            audioChannel.getSampleRate() *
            (delay.getCurrent() +
             sweepWidth.getCurrent() *
                 lfo.Value(localRate + phase, WaveShape::SQUARE));
        float readPosition = fmodf((float)localWritePosition - localDelayTime +
                                       (float)bufferSize,
                                   bufferSize);

        unsigned int localReadPosition = floorf(readPosition);

        if (localReadPosition != localWritePosition) {
          float fraction = readPosition - (float)localReadPosition;
          float delayed0 = chorusBuffer->getChannelBuffer(channelIndex)
                               ->at(localReadPosition + 0);
          float delayed1 = chorusBuffer->getChannelBuffer(channelIndex)
                               ->at((localReadPosition + 1) % bufferSize);
          out = delayed0 + fraction * (delayed1 - delayed0);
          audioChannel.getChannelBuffer(channelIndex)->at(sample) =
              in + depth * out * voiceWeight;
        }

        phase += phaseStep;
      }

      chorusBuffer->getChannelBuffer(channelIndex)->at(localWritePosition) = in;

      if (++localWritePosition >= bufferSize)
        localWritePosition -= bufferSize;

      localRate += rate / audioChannel.getSampleRate();
      if (localRate >= 1.0f)
        localRate -= 1.0f;
    }
  }
  bufferPosition = localWritePosition;
}

void Chorus::setDelay(float value) { delay.setCurrent(value); }

void Chorus::setWidth(float value) { sweepWidth.setCurrent(value); }
