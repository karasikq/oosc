#include "FlangerUIWrapper.h"

FlangerUIWrapper::FlangerUIWrapper() {
  effect = std::make_unique<Flanger>(AudioSettings::BUFFER_SIZE,
                                     MinMax<float>(0.f, 2.f, 1.f));
  auto flanger = static_cast<Flanger *>(effect.get());
  delay.setParameter(
      flanger, &Flanger::setDelay, MinMax<float>(0.001f, 0.1f, 0.01f));
  flangerWidth.setParameter(
      flanger, &Flanger::setWidth, MinMax<float>(0.001f, 0.1f, 0.01f));
  depth.setParameter(flanger, &Flanger::setDepth, MinMax<float>(0.f, 1.f, 1.f));
  feedback.setParameter(
      flanger, &Flanger::setFeedback, MinMax<float>(0.f, 0.5f, 0.5f));
  lfoFrequency.setParameter(
      flanger, &Flanger::setLfoFrequency, MinMax<float>(0.01f, 3.f, 0.2f));
  invertedMode.setParameter(
      flanger, &Flanger::setInvertedMode, MinMax<bool>(false, true, false));
  interpolation.setParameter(
      this, &FlangerUIWrapper::setInterpolationType, MinMax<int>(0, 2, 1));
  lfoShape.setParameter(
      this, &FlangerUIWrapper::setLfoShape, MinMax<int>(0, 3, 0));
}

FlangerUIWrapper::~FlangerUIWrapper() {}

void FlangerUIWrapper::setInterpolationType(int value) {
  static_cast<Flanger *>(effect.get())
      ->setInterpolation(static_cast<InterpolationType>(value));
}

void FlangerUIWrapper::setLfoShape(int value) {
  static_cast<Flanger *>(effect.get())
      ->setLfoShape(static_cast<WaveShape::Shape>(value));
}
