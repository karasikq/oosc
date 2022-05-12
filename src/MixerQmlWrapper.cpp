#include "MixerQmlWrapper.h"
#include "src/MixerQmlWrapper.h"

MixerQmlWrapper::MixerQmlWrapper(QQuickItem *parent) : QQuickItem(parent) {
  mixer = std::unique_ptr<MixerOutput>(MixerOutput::Instance());
  mixer->Initialize();
}

MixerQmlWrapper::~MixerQmlWrapper() {
}

void MixerQmlWrapper::attachSynthesizer(BasicSynthesizer *synthesizer) {
  mixer->addSynthesizer(synthesizer);
}

void MixerQmlWrapper::attachTimeReceiver(ITimeReceiver *receiver) {
  mixer->addTimeReceiver(receiver);
}
