#include "SynthesizerControl.h"

SynthesizerControl::SynthesizerControl(QQuickItem *parent)
    : QQuickItem(parent) {
  synthesizer = std::make_unique<BasicSynthesizer>();

  synthesizer->leftDataCallback =
      std::bind(&SynthesizerControl::dataReceiveLeft,
                this,
                std::placeholders::_1,
                std::placeholders::_2,
                std::placeholders::_3);
  synthesizer->rightDataCallback =
      std::bind(&SynthesizerControl::dataReceiveRight,
                this,
                std::placeholders::_1,
                std::placeholders::_2,
                std::placeholders::_3);
  synthesizer->mixedDataCallback =
      std::bind(&SynthesizerControl::dataReceiveMixed,
                this,
                std::placeholders::_1,
                std::placeholders::_2,
                std::placeholders::_3);
  synthesizer->channelDataCallback = std::bind(
      &SynthesizerControl::dataReceiveChannel, this, std::placeholders::_1);
  synthesizer->lastPlayedNoteCallback = std::bind(
      &SynthesizerControl::lastNoteReceived, this, std::placeholders::_1);
  gain.setParameter(synthesizer.get(),
                    &BasicSynthesizer::setMasterVolume,
                    {0.0f, 1.41254f, 1.0f});
}

void SynthesizerControl::noteOn(unsigned int note, unsigned int velocity) {
  synthesizer->noteOn(note, velocity);
  emit noteActivated(note, velocity);
}

void SynthesizerControl::noteOff(unsigned int note) {
  synthesizer->noteOff(note);
  emit noteDisabled(note);
}

void SynthesizerControl::allNoteOff() {
  synthesizer->allNoteOff();
  emit allNoteDisabled();
}

void SynthesizerControl::keyPressEvent(QKeyEvent *event) {
  if (event->isAutoRepeat()) {
    return;
  }

  if (!keys[(Qt::Key)event->key()].second) {
    noteOn(keys[(Qt::Key)event->key()].first, 128);
    keys[(Qt::Key)event->key()].second = true;
  }
}

void SynthesizerControl::keyReleaseEvent(QKeyEvent *event) {
  if (event->isAutoRepeat()) {
    return;
  }
  noteOff(keys[(Qt::Key)event->key()].first);
  keys[(Qt::Key)event->key()].second = false;
}

void SynthesizerControl::attachEffect(Effect *effect) {
  synthesizer->attachEffect(effect);
}

void SynthesizerControl::dataReceiveLeft(
    const std::vector<float> &data,
    std::vector<float>::const_iterator from,
    std::vector<float>::const_iterator to) {
  emit dataGeneratedLeft(data, from, to);
}

void SynthesizerControl::dataReceiveRight(
    const std::vector<float> &data,
    std::vector<float>::const_iterator from,
    std::vector<float>::const_iterator to) {
  emit dataGeneratedRight(data, from, to);
}

void SynthesizerControl::dataReceiveMixed(
    const std::vector<float> &data,
    std::vector<float>::const_iterator from,
    std::vector<float>::const_iterator to) {
  emit dataGeneratedMixed(data, from, to);
}

void SynthesizerControl::dataReceiveChannel(AudioChannel *channel) {
  emit dataGeneratedChannel(channel);
  emit extremaLeftReceived(channel->getExtrema(0));
  emit extremaRightReceived(channel->getExtrema(1));
  emit extremaMixedReceived(channel->getExtrema(2));
}

void SynthesizerControl::lastNoteReceived(const Note<3> &note) {
  emit lastPlayedNote(note);
}

void SynthesizerControl::connectToOutput(ADataReceiver *receiver) {
  connectToOutput(receiver->receiver.get(),
                  &ADataReceiverSlots::dataUpdateChannel);
}

void SynthesizerControl::connectToOutputLeft(ADataReceiver *receiver) {
  connectToOutputLeft(receiver->receiver.get(),
                      &ADataReceiverSlots::dataUpdate);
}

void SynthesizerControl::connectToOutputRight(ADataReceiver *receiver) {
  connectToOutputRight(receiver->receiver.get(),
                       &ADataReceiverSlots::dataUpdate);
}

void SynthesizerControl::connectToOutputMixed(ADataReceiver *receiver) {
  connectToOutputMixed(receiver->receiver.get(),
                       &ADataReceiverSlots::dataUpdate);
}

void SynthesizerControl::connectToOutputNote(ADataReceiver *receiver) {
  connectToOutputNote(receiver->receiver.get(),
                       &ADataReceiverSlots::lastNoteReceived);
}

BasicSynthesizer *SynthesizerControl::getSynthesizer() {
  return synthesizer.get();
}

void SynthesizerControl::attachGeneratorControl(
    AGeneratorControl *generatorControl) {
  generatorControl->setGenerator(
      (synthesizer->generators[generatorControl->getGeneratorID()]).get());
}

void SynthesizerControl::setGeneratorControls(const QVariant &generators) {
  QList<QVariant> list = generators.toList();
  for (const auto &item : list) {
    auto generator = item.value<AGeneratorControl *>();
    attachGeneratorControl(generator);
  }
}
