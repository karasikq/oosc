#include "VibratoUIWrapper.h"
#include "src/Effects/Vibrato.h"

VibratoUIWrapper::VibratoUIWrapper() {
  effect = std::make_unique<Vibrato>(MinMax<float>(0.001f, 0.1f, 0.01f));
  auto vibrato = static_cast<Vibrato *>(effect.get());
  vibratoWidth.setParameter(
      vibrato, &Vibrato::setWidth, MinMax<float>(0.001f, 0.1f, 0.01f));
  lfoFrequency.setParameter(
      vibrato, &Vibrato::setLfoFrequency, MinMax<float>(0.01f, 3.f, 0.2f));
  interpolation.setParameter(
      this, &VibratoUIWrapper::setInterpolationType, MinMax<int>(0, 2, 1));
  lfoShape.setParameter(
      this, &VibratoUIWrapper::setLfoShape, MinMax<int>(0, 3, 0));
}

VibratoUIWrapper::~VibratoUIWrapper() {}

void VibratoUIWrapper::setInterpolationType(int value) {
  static_cast<Vibrato *>(effect.get())
      ->setInterpolation(static_cast<InterpolationType>(value));
}

void VibratoUIWrapper::setLfoShape(int value) {
  static_cast<Vibrato *>(effect.get())
      ->setLfoShape(static_cast<WaveShape::Shape>(value));
}
