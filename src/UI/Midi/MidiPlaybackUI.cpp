#include "MidiPlaybackUI.h"

MidiPlaybackUI::MidiPlaybackUI() {
  midiPlayback = std::make_unique<MidiPlayback>();
  connect(midiPlayback.get(),
          &MidiPlayback::checked,
          this,
          &MidiPlaybackUI::timeChange);
  connect(midiPlayback.get(),
          &MidiPlayback::started,
          this,
          &MidiPlaybackUI::timeChange);
  connect(midiPlayback.get(),
          &MidiPlayback::stoped,
          this,
          &MidiPlaybackUI::timeChange);
  attachPlayback();
}

MidiPlaybackUI::~MidiPlaybackUI() {}

void MidiPlaybackUI::attachPlayback() {
  MixerOutput::Instance()->addMidiPlayback(midiPlayback.get());
}

void MidiPlaybackUI::detachPlayback() {
  MixerOutput::Instance()->removeMidiPlayback(midiPlayback.get());
}

void MidiPlaybackUI::play() { midiPlayback->play(); }

void MidiPlaybackUI::stop() { midiPlayback->stop(); }

void MidiPlaybackUI::pause() { midiPlayback->pause(); }

float MidiPlaybackUI::getPlaybackTime() {
  return midiPlayback->getPlaybackTime();
}

void MidiPlaybackUI::loadFromFile(const QVariant &fileName) {
  auto midiFile = std::unique_ptr<smf::MidiFile>(new smf::MidiFile());
  midiFile->read(fileName.toString().toStdString());
  midiFile->doTimeAnalysis();
  midiPlayback->attachMidiFile(std::move(midiFile));
}

void MidiPlaybackUI::loadFromFileUrl(const QVariant &fileName) {
  QString file = fileName.toString();
  QVariant fileVariant = file.mid(7, file.length() - 7);
  loadFromFile(fileVariant);
}

void MidiPlaybackUI::loadMidi(const QVariant &fileName) {
  loadFromFileUrl(fileName);
}

void MidiPlaybackUI::setSynthesizer(SynthesizerControl *synthesizer) {
  midiPlayback->attachSynthesizer(synthesizer);
}

void MidiPlaybackUI::timeChange() { emit playbackTimeChanged(); }
