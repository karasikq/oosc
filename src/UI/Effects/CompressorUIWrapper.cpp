#include "CompressorUIWrapper.h"
#include "src/Effects/Compressor.h"

CompressorUIWrapper::CompressorUIWrapper() {
  effect = std::make_unique<Compressor>();
  auto compressor = static_cast<Compressor *>(effect.get());
  threshold.setParameter(
      compressor, &Compressor::setThreshold, MinMax<float>(-60.f, 12.f, -12.f));
  ratio.setParameter(
      compressor, &Compressor::setRatio, MinMax<float>(1.f, 100.f, 50.f));
  attack.setParameter(
      compressor, &Compressor::setAttack, MinMax<float>(0.001f, 0.2f, 0.01f));
  release.setParameter(
      compressor, &Compressor::setRelease, MinMax<float>(0.001f, 1.0f, 0.1f));
  gain.setParameter(
      compressor, &Compressor::setGain, MinMax<float>(-12.f, 12.f, 0.f));
}

CompressorUIWrapper::~CompressorUIWrapper() {}
