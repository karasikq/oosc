#include "DistortionUIWrapper.h"
#include "src/Effects/Distortion.h"

DistortionUIWrapper::DistortionUIWrapper() {
  effect = std::make_unique<Distortion>();
  auto distortion = static_cast<Distortion *>(effect.get());
  distortionType.setParameter(
      this, &DistortionUIWrapper::setDistortionType, MinMax<int>(0, 4, 3));
  inputGain.setParameter(distortion,
                         &Distortion::setInputGain,
                         MinMax<float>(0.0631f, 15.8489f, 1.f));
  outputGain.setParameter(distortion,
                          &Distortion::setOutputGain,
                          MinMax<float>(0.0631f, 15.8489f, 1.f));
  tone.setParameter(
      distortion, &Distortion::setTone, MinMax<float>(0.f, 1.f, 1.f));
}

DistortionUIWrapper::~DistortionUIWrapper() {}

void DistortionUIWrapper::setDistortionType(int value) {
  static_cast<Distortion *>(effect.get())
      ->setDistortionType(static_cast<Distortion::DistortionType>(value));
}
