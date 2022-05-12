#include "ChorusUIWrapper.h"

ChorusUIWrapper::ChorusUIWrapper() {
  effect = std::make_unique<Chorus>(AudioSettings::BUFFER_SIZE,
                                    MinMax<float>(0.f, 0.1f, 0.1f),
                                    MinMax<float>(0.f, 0.1f, 0.1f));

  auto chorus = static_cast<Chorus *>(effect.get());
  voices.setParameter(chorus, &Chorus::setVoices, MinMax<uint8_t>(2, 7, 2));
  delay.setParameter(
      chorus, &Chorus::setDelay, MinMax<float>(0.f, 0.1f, 0.01f));
  sweepWidth.setParameter(
      chorus, &Chorus::setWidth, MinMax<float>(0.f, 0.1f, 0.01f));
  depth.setParameter(chorus, &Chorus::setDepth, MinMax<float>(0.f, 1.f, 1.f));
  rate.setParameter(chorus, &Chorus::setRate, MinMax<float>(0.01f, 2.f, 0.1f));
  phase.setParameter(
      chorus, &Chorus::setStereoPhase, MinMax<float>(0.f, M_PIf, M_PI_2f));
}

ChorusUIWrapper::~ChorusUIWrapper() {}
