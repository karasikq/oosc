#include "SubGeneratorKnobs.h"

SubGeneratorKnobs::SubGeneratorKnobs(QQuickItem *parent) : QQuickItem(parent) {}

SubGeneratorKnobs::~SubGeneratorKnobs() {}

void SubGeneratorKnobs::attachKnobs() {
  if (generatorControl == nullptr)
    return;
  pan->setChangeableParametr(generatorControl->getPan());
  gain->setChangeableParametr(generatorControl->getGain());
  shape->setChangeableParametr(generatorControl->getShape());
}

void SubGeneratorKnobs::setGeneratorControl(SubGeneratorControl *control) {
  generatorControl = control;
}

void SubGeneratorKnobs::setPanKnob(Knob *knob) { this->pan = knob; }

void SubGeneratorKnobs::setGainKnob(Knob *knob) { this->gain = knob; }

void SubGeneratorKnobs::setShapeKnob(Knob *knob) { this->shape = knob; }

Knob *SubGeneratorKnobs::getPanKnob() { return pan; }

Knob *SubGeneratorKnobs::getGainKnob() { return gain; }

Knob *SubGeneratorKnobs::getShapeKnob() { return shape; }
