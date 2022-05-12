#include "EqUIWrapper.h"
#include "src/Effects/ParametricEQ.h"

EqUIWrapper::EqUIWrapper() {
  effect = std::make_unique<ParametricEQ>();
  auto eq = static_cast<ParametricEQ *>(effect.get());
  frequency.setParameter(
      eq, &ParametricEQ::setFrequency, MinMax<float>(5.f, 20000.f, 1000.f));
  filterType.setParameter(this,
                          &EqUIWrapper::setFilterType,
                          MinMax<int>((int)ParametricEQ::FilterType::LowPass,
                                      (int)ParametricEQ::FilterType::Peak,
                                      0));
  qFactor.setParameter(
      eq, &ParametricEQ::setQ, MinMax<float>(0.05f, 30.f, M_SQRT1_2f32));
  gain.setParameter(
      eq, &ParametricEQ::setGain, MinMax<float>(-12.f, 12.f, 0.0f));
}

EqUIWrapper::~EqUIWrapper() {}

void EqUIWrapper::setFilterType(int value) {
  static_cast<ParametricEQ *>(effect.get())
      ->setFilterType(static_cast<ParametricEQ::FilterType>(value));
}
