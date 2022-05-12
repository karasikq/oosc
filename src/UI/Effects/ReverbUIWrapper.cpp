#include "ReverbUIWrapper.h"

ReverbUIWrapper::ReverbUIWrapper() {
  effect = std::make_unique<Reverb>(AudioSettings::SAMPLE_RATE);

  auto reverb = static_cast<Reverb *>(effect.get());
  reverbWidth.setParameter(
      reverb, &Reverb::setWidth, MinMax<float>(0.f, 1.f, 1.f));
  damping.setParameter(
      reverb, &Reverb::setDamping, MinMax<float>(0.f, 1.f, 0.5f));
  roomSize.setParameter(
      reverb, &Reverb::setRoomSize, MinMax<float>(0.f, 1.f, 0.5f));
  wet.setParameter(reverb, &Reverb::setWet, MinMax<float>(0.f, 1.f, 0.5f));
  dry.setParameter(reverb, &Reverb::setDry, MinMax<float>(0.f, 1.f, 0.5f));
}

ReverbUIWrapper::~ReverbUIWrapper() {}
