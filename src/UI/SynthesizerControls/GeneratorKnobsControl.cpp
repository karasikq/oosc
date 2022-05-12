#include "GeneratorKnobsControl.h"

GeneratorKnobsControl::GeneratorKnobsControl(QQuickItem *parent)
    : QQuickItem(parent) {}

GeneratorKnobsControl::~GeneratorKnobsControl() {}

void GeneratorKnobsControl::attachKnobs() {
  if (generatorControl == nullptr)
    return;
  pos->setChangeableParametr(generatorControl->getTablePosition());
  pan->setChangeableParametr(generatorControl->getPan());
  gain->setChangeableParametr(generatorControl->getGain());
  phase->setChangeableParametr(generatorControl->getPhase());
  unisonVoices->setChangeableParametr(generatorControl->getUnisonVoices());
  unisonPan->setChangeableParametr(generatorControl->getUnisonPan());
  unisonLevel->setChangeableParametr(generatorControl->getUnisonLevel());
  unisonFine->setChangeableParametr(generatorControl->getUnisonFine());
}

void GeneratorKnobsControl::setGeneratorControl(GeneratorControl *control) {
  generatorControl = control;
}

void GeneratorKnobsControl::setPosKnob(Knob *knob) { this->pos = knob; }

void GeneratorKnobsControl::setPanKnob(Knob *knob) { this->pan = knob; }

void GeneratorKnobsControl::setGainKnob(Knob *knob) { this->gain = knob; }

void GeneratorKnobsControl::setPhaseKnob(Knob *knob) { this->phase = knob; }

void GeneratorKnobsControl::setUnisonVoicesKnob(Knob *knob) {
  this->unisonVoices = knob;
}

void GeneratorKnobsControl::setUnisonPanKnob(Knob *knob) {
  this->unisonPan = knob;
}

void GeneratorKnobsControl::setUnisonLevelKnob(Knob *knob) {
  this->unisonLevel = knob;
}

void GeneratorKnobsControl::setUnisonFineKnob(Knob *knob) {
  this->unisonFine = knob;
}

Knob *GeneratorKnobsControl::getPosKnob() { return pos; }

Knob *GeneratorKnobsControl::getPanKnob() { return pan; }

Knob *GeneratorKnobsControl::getGainKnob() { return gain; }

Knob *GeneratorKnobsControl::getPhaseKnob() { return phase; }

Knob *GeneratorKnobsControl::getUnisonVoicesKnob() { return unisonVoices; }

Knob *GeneratorKnobsControl::getUnisonPanKnob() { return unisonPan; }

Knob *GeneratorKnobsControl::getUnisonLevelKnob() { return unisonLevel; }

Knob *GeneratorKnobsControl::getUnisonFineKnob() { return unisonFine; }
