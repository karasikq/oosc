#include "IIRCoefficients.h"

IIRCoefficients::IIRCoefficients() {}

IIRCoefficients::IIRCoefficients(float b0, float b1, float a0, float a1) {
  coefficients.clear();
  float a0inv = 1.0f / a0;
  coefficients.insert(coefficients.begin(),
                      {b0 * a0inv, b0 * a0inv, b1 * a0inv, a1 * a0inv});
}

IIRCoefficients::IIRCoefficients(float b0,
                                 float b1,
                                 float b2,
                                 float a0,
                                 float a1,
                                 float a2) {
  coefficients.clear();
  float a0inv = 1.0f / a0;
  coefficients.insert(
      coefficients.begin(),
      {b0 * a0inv, b1 * a0inv, b2 * a0inv, a1 * a0inv, a2 * a0inv});
}

IIRCoefficients::IIRCoefficients(float b0,
                                 float b1,
                                 float b2,
                                 float b3,
                                 float a0,
                                 float a1,
                                 float a2,
                                 float a3) {
  coefficients.clear();
  float a0inv = 1.0f / a0;
  coefficients.insert(coefficients.begin(),
                      {b0 * a0inv,
                       b1 * a0inv,
                       b2 * a0inv,
                       b3 * a0inv,
                       a1 * a0inv,
                       a2 * a0inv,
                       a3 * a0inv});
}

IIRCoefficients::IIRCoefficients(const IIRCoefficients &iir) {
  coefficients = iir.coefficients;
}

IIRCoefficients &IIRCoefficients::operator=(const IIRCoefficients &iir) {
  coefficients = iir.coefficients;
  return *this;
}

IIRCoefficients IIRCoefficients::makeFirstOrderLowPass(float sampleRate,
                                                       float frequency) {
  float n = std::tan(M_PIf32 * frequency / sampleRate);
  return IIRCoefficients(n, n, n + 1, n - 1);
}

IIRCoefficients IIRCoefficients::makeFirstOrderHighPass(float sampleRate,
                                                        float frequency) {
  float n = std::tan(M_PIf32 * frequency / sampleRate);
  return IIRCoefficients(1, -1, n + 1, n - 1);
}

IIRCoefficients IIRCoefficients::makeFirstOrderAllPass(float sampleRate,
                                                       float frequency) {
  float n = std::tan(M_PIf32 * frequency / sampleRate);
  return IIRCoefficients(n - 1, n + 1, n + 1, n - 1);
}

IIRCoefficients IIRCoefficients::makeLowPass(float sampleRate,
                                             float frequency) {
  return makeLowPass(sampleRate, frequency, M_SQRT1_2f32);
}

IIRCoefficients
IIRCoefficients::makeLowPass(float sampleRate, float frequency, float Q) {
  float n = 1 / std::tan(M_PIf32 * frequency / sampleRate);
  float nSquared = n * n;
  float invQ = 1 / Q;
  float c1 = 1 / (1 + invQ * n + nSquared);

  return IIRCoefficients(c1,
                         c1 * 2,
                         c1,
                         1,
                         c1 * 2 * (1 - nSquared),
                         c1 * (1 - invQ * n + nSquared));
}

IIRCoefficients IIRCoefficients::makeHighPass(float sampleRate,
                                              float frequency) {
  return makeHighPass(sampleRate, frequency, M_SQRT1_2f32);
}

IIRCoefficients
IIRCoefficients::makeHighPass(float sampleRate, float frequency, float Q) {

  float n = std::tan(M_PIf32 * frequency / sampleRate);
  float nSquared = n * n;
  float invQ = 1 / Q;
  float c1 = 1 / (1 + invQ * n + nSquared);

  return IIRCoefficients(c1,
                         c1 * -2,
                         c1,
                         1,
                         c1 * 2 * (nSquared - 1),
                         c1 * (1 - invQ * n + nSquared));
}

IIRCoefficients IIRCoefficients::makeBandPass(float sampleRate,
                                              float frequency) {
  return makeBandPass(sampleRate, frequency, M_SQRT1_2f32);
}

IIRCoefficients
IIRCoefficients::makeBandPass(float sampleRate, float frequency, float Q) {
  float n = 1 / std::tan(M_PIf32 * frequency / sampleRate);
  float nSquared = n * n;
  float invQ = 1 / Q;
  float c1 = 1 / (1 + invQ * n + nSquared);

  return IIRCoefficients(c1 * n * invQ,
                         0,
                         -c1 * n * invQ,
                         1,
                         c1 * 2 * (1 - nSquared),
                         c1 * (1 - invQ * n + nSquared));
}

// ??? Recalculate coeffs ???

IIRCoefficients IIRCoefficients::makeBandStop(float sampleRate,
                                              float frequency) {
  return makeBandPass(sampleRate, frequency, M_SQRT1_2f32);
}

IIRCoefficients
IIRCoefficients::makeBandStop(float sampleRate, float frequency, float Q) {
  float n = 1 / std::tan(M_PIf32 * frequency / sampleRate);
  float nSquared = n * n;
  float invQ = 1 / Q;
  float c1 = 1 / (1 + invQ * n + nSquared);

  return IIRCoefficients(c1 * n * invQ,
                         0,
                         -c1 * n * invQ,
                         1,
                         c1 * 2 * (nSquared - 1),
                         c1 * (1 - invQ * n + nSquared));
}

IIRCoefficients IIRCoefficients::makeNotch(float sampleRate, float frequency) {
  return makeNotch(sampleRate, frequency, M_SQRT1_2f32);
}

IIRCoefficients
IIRCoefficients::makeNotch(float sampleRate, float frequency, float Q) {
  float n = 1 / std::tan(M_PIf32 * frequency / sampleRate);
  float nSquared = n * n;
  float invQ = 1 / Q;
  float c1 = 1 / (1 + n * invQ + nSquared);
  float b0 = c1 * (1 + nSquared);
  float b1 = 2 * c1 * (1 - nSquared);

  return IIRCoefficients(b0, b1, b0, 1, b1, c1 * (1 - n * invQ + nSquared));
}

IIRCoefficients IIRCoefficients::makeAllPass(float sampleRate,
                                             float frequency) {
  return makeAllPass(sampleRate, frequency, M_SQRT1_2f32);
}

IIRCoefficients
IIRCoefficients::makeAllPass(float sampleRate, float frequency, float Q) {
  float n = 1 / std::tan(M_PIf32 * frequency / sampleRate);
  float nSquared = n * n;
  float invQ = 1 / Q;
  float c1 = 1 / (1 + invQ * n + nSquared);
  float b0 = c1 * (1 - n * invQ + nSquared);
  float b1 = c1 * 2 * (1 - nSquared);

  return IIRCoefficients(b0, b1, 1, 1, b1, b0);
}

IIRCoefficients IIRCoefficients::makeLowShelf(float sampleRate,
                                              float cutOffFrequency,
                                              float Q,
                                              float gainFactor) {
  float A = std::max(0.0f, std::sqrt(gainFactor));
  float aminus1 = A - 1;
  float aplus1 = A + 1;
  float omega = (2 * M_PIf32 * std::max(cutOffFrequency, 2.0f)) / sampleRate;
  float coso = std::cos(omega);
  float beta = std::sin(omega) * std::sqrt(A) / Q;
  float aminus1TimesCoso = aminus1 * coso;

  return IIRCoefficients(A * (aplus1 - aminus1TimesCoso + beta),
                         A * 2 * (aminus1 - aplus1 * coso),
                         A * (aplus1 - aminus1TimesCoso - beta),
                         aplus1 + aminus1TimesCoso + beta,
                         -2 * (aminus1 + aplus1 * coso),
                         aplus1 + aminus1TimesCoso - beta);
}

IIRCoefficients IIRCoefficients::makeHighShelf(float sampleRate,
                                               float cutOffFrequency,
                                               float Q,
                                               float gainFactor) {
  float A = std::max(0.0f, std::sqrt(gainFactor));
  float aminus1 = A - 1;
  float aplus1 = A + 1;
  float omega = (2 * M_PIf32 * std::max(cutOffFrequency, 2.0f)) / sampleRate;
  float coso = std::cos(omega);
  float beta = std::sin(omega) * std::sqrt(A) / Q;
  float aminus1TimesCoso = aminus1 * coso;

  return IIRCoefficients(A * (aplus1 + aminus1TimesCoso + beta),
                         A * -2 * (aminus1 + aplus1 * coso),
                         A * (aplus1 + aminus1TimesCoso - beta),
                         aplus1 - aminus1TimesCoso + beta,
                         2 * (aminus1 - aplus1 * coso),
                         aplus1 - aminus1TimesCoso - beta);
}

IIRCoefficients IIRCoefficients::makePeakFilter(float sampleRate,
                                                float frequency,
                                                float Q,
                                                float gainFactor) {
  float A = std::max(0.0f, std::sqrt(gainFactor));
  float omega = (2 * M_PIf32 * std::max(frequency, 2.0f)) / sampleRate;
  float alpha = std::sin(omega) / (Q * 2);
  float c2 = -2 * std::cos(omega);
  float alphaTimesA = alpha * A;
  float alphaOverA = alpha / A;

  return IIRCoefficients(
      1 + alphaTimesA, c2, 1 - alphaTimesA, 1 + alphaOverA, c2, 1 - alphaOverA);
}

uint32_t IIRCoefficients::getFilterOrder() const noexcept {
  return (static_cast<uint32_t>(coefficients.size()) - 1) / 2;
}

float IIRCoefficients::getMagnitudeForFrequency(
    float frequency,
    float sampleRate) const noexcept {
  constexpr std::complex<float> j(0, 1);
  const float order = getFilterOrder();

  std::complex<float> numerator = 0.0, denominator = 0.0, factor = 1.0;
  std::complex<float> jw =
      std::exp(-(2 * M_PIf32) * frequency * j / sampleRate);

  for (uint32_t n = 0; n <= order; ++n) {
    numerator += static_cast<float>(coefficients[n]) * factor;
    factor *= jw;
  }

  denominator = 1.0;
  factor = jw;

  for (uint32_t n = order + 1; n <= 2 * order; ++n) {
    denominator += static_cast<float>(coefficients[n]) * factor;
    factor *= jw;
  }

  return std::abs(numerator / denominator);
}

void IIRCoefficients::getMagnitudeForFrequencyArray(
    const float *frequencies,
    float *magnitudes,
    uint32_t numSamples,
    float sampleRate) const noexcept {
  constexpr std::complex<float> j(0, 1);
  const float order = getFilterOrder();

  for (uint32_t i = 0; i < numSamples; ++i) {
    std::complex<float> numerator = 0.0, denominator = 0.0, factor = 1.0;
    std::complex<float> jw =
        std::exp(-(2 * M_PIf32) * frequencies[i] * j / sampleRate);

    for (uint32_t n = 0; n <= order; ++n) {
      numerator += static_cast<float>(coefficients[n]) * factor;
      factor *= jw;
    }

    denominator = 1.0;
    factor = jw;

    for (uint32_t n = order + 1; n <= 2 * order; ++n) {
      denominator += static_cast<float>(coefficients[n]) * factor;
      factor *= jw;
    }

    magnitudes[i] = std::abs(numerator / denominator);
  }
}

float IIRCoefficients::getPhaseForFrequency(float frequency,
                                            float sampleRate) const noexcept {
  constexpr std::complex<float> j(0, 1);
  const float order = getFilterOrder();

  std::complex<float> numerator = 0.0, denominator = 0.0, factor = 1.0;
  std::complex<float> jw =
      std::exp(-(2 * M_PIf32) * frequency * j / sampleRate);

  for (uint32_t n = 0; n <= order; ++n) {
    numerator += static_cast<float>(coefficients[n]) * factor;
    factor *= jw;
  }

  denominator = 1.0;
  factor = jw;

  for (uint32_t n = order + 1; n <= 2 * order; ++n) {
    denominator += static_cast<float>(coefficients[n]) * factor;
    factor *= jw;
  }

  return std::arg(numerator / denominator);
}

void IIRCoefficients::getPhaseForFrequencyArray(
    float *frequencies,
    float *phases,
    uint32_t numSamples,
    float sampleRate) const noexcept {
  constexpr std::complex<float> j(0, 1);
  const float order = getFilterOrder();
  float invSampleRate = 1 / sampleRate;

  for (uint32_t i = 0; i < numSamples; ++i) {
    std::complex<float> numerator = 0.0, denominator = 0.0, factor = 1.0;
    std::complex<float> jw =
        std::exp(-(2 * M_PIf32) * frequencies[i] * j * invSampleRate);

    for (uint32_t n = 0; n <= order; ++n) {
      numerator += static_cast<float>(coefficients[n]) * factor;
      factor *= jw;
    }

    denominator = 1.0;
    factor = jw;

    for (uint32_t n = order + 1; n <= 2 * order; ++n) {
      denominator += static_cast<float>(coefficients[n]) * factor;
      factor *= jw;
    }

    phases[i] = std::arg(numerator / denominator);
  }
}

float *IIRCoefficients::getRawCoefficients() { return coefficients.data(); }
