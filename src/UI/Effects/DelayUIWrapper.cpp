#include "DelayUIWrapper.h"

DelayUIWrapper::DelayUIWrapper() {
  effect = std::make_unique<Delay>(AudioSettings::BUFFER_SIZE,
                                   MinMax<float>(0.f, 2.f, 0.01f));
  auto delay = static_cast<Delay *>(effect.get());
  time.setParameter(delay, &Delay::setTime, MinMax<float>(0.f, 2.f, 0.01f));
  mix.setParameter(delay, &Delay::setMix, MinMax<float>(0.f, 1.f, 0.7f));
  feedback.setParameter(
      delay, &Delay::setFeedback, MinMax<float>(0.f, 1.f, 0.5f));
}

DelayUIWrapper::~DelayUIWrapper() {}
