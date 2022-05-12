#include "IIR.h"

IIRFilter::IIRFilter() : coefficients(IIRCoefficients(1, 0, 1, 0)) { reset(); }

IIRFilter::IIRFilter(IIRCoefficients &_coefficients)
    : coefficients(_coefficients) {
  reset();
}

void IIRFilter::setCoefficients(IIRCoefficients _coefficients) {
  coefficients = _coefficients;
  reset();
}

void IIRFilter::reset(float resetToValue) {
  uint32_t newOrder = coefficients.getFilterOrder();

  if (newOrder != order) {
    if (state != nullptr)
      delete[] state;
    uint32_t memorySize =
        std::max(std::max(order, newOrder), static_cast<uint32_t>(3)) + 1;
    state = new float[memorySize];
    for (uint32_t i = 0; i < memorySize; i++)
      state[i] = 0.0f;
    order = newOrder;
  }

  for (uint32_t i = 0; i < order; ++i)
    state[i] = resetToValue;
}

void IIRFilter::process(std::vector<float> &inputBuffer) noexcept {
  for (float &sample : inputBuffer) {
    sample = process(sample);
  }
  snapToZero();
}

float IIRFilter::process(float sample) noexcept {
  check();
  float *c = coefficients.getRawCoefficients();

  float output = (c[0] * sample) + state[0];

  for (uint32_t j = 0; j < order - 1; ++j)
    state[j] = (c[j + 1] * sample) - (c[order + j + 1] * output) + state[j + 1];

  state[order - 1] = (c[order] * sample) - (c[order * 2] * output);

  return output;
}

void IIRFilter::snapToZero() noexcept {
  for (uint32_t i = 0; i < order; ++i)
    snapToZero(state[i]);
}

void IIRFilter::check() {
  if (order != coefficients.getFilterOrder())
    reset();
}
