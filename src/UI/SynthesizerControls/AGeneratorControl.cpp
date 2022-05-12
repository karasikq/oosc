#include "AGeneratorControl.h"

AGeneratorControl::AGeneratorControl(QQuickItem *parent) : QQuickItem(parent) {
  generatorID = 0;
}

AGeneratorControl::~AGeneratorControl() {}

void AGeneratorControl::setGeneratorID(unsigned int generatorID) {
  this->generatorID = generatorID;
}

unsigned int AGeneratorControl::getGeneratorID() const { return generatorID; }

void AGeneratorControl::setGenerator(AGenerator *generator) {
  this->generator = generator;
}

void AGeneratorControl::setAdsr(ADSRController *controller) {
  this->adsr = controller;
  emit adsrChanged(adsr);
}

void AGeneratorControl::setBypass(bool value) { generator->setBypass(value); }

ADSRController *AGeneratorControl::getAdsr() const { return adsr; }

bool AGeneratorControl::getBypass() const {
  return (generator) ? generator->isBypass() : true;
}
