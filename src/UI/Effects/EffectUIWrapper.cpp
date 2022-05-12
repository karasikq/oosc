#include "EffectUIWrapper.h"

EffectUIWrapper::EffectUIWrapper() {}

EffectUIWrapper::~EffectUIWrapper() {}

Effect *EffectUIWrapper::getEffect() { return effect.get(); }

QString EffectUIWrapper::interpolationToString(int value) {
  return interpolationStrings.at(static_cast<InterpolationType>(value));
}

QString EffectUIWrapper::lfoShapeToString(int value) {
  return lfoShapeStrings.at(static_cast<WaveShape::Shape>(value));
}
