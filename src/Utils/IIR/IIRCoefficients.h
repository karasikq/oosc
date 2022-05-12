//===---------------------- IIRCoefficients.h --------------------*- C++-*-===//
//===------------- IIRCoefficients class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the IIRCoefficients class, which is
/// the coefficients for Infinite Impulse Response filter.
///
//===----------------------------------------------------------------------===//

#ifndef IIRCOEFFICIENTS_H
#define IIRCOEFFICIENTS_H 

#include <complex>
#include <math.h>
#include <vector>

struct IIRCoefficients {
  IIRCoefficients();
  /// First-order filter
  IIRCoefficients(float b0, float b1, float a0, float a1);
  /// Second-order filter
  IIRCoefficients(float b0, float b1, float b2, float a0, float a1, float a2);
  /// Third-order filter
  IIRCoefficients(float b0,
                  float b1,
                  float b2,
                  float b3,
                  float a0,
                  float a1,
                  float a2,
                  float a3);
  IIRCoefficients(const IIRCoefficients &iir);

  IIRCoefficients &operator=(const IIRCoefficients &iir);

  static IIRCoefficients makeFirstOrderLowPass(float sampleRate,
                                               float frequency);
  static IIRCoefficients makeFirstOrderHighPass(float sampleRate,
                                                float frequency);
  static IIRCoefficients makeFirstOrderAllPass(float sampleRate,
                                               float frequency);

  static IIRCoefficients makeLowPass(float sampleRate, float frequency);
  static IIRCoefficients
  makeLowPass(float sampleRate, float frequency, float Q);

  static IIRCoefficients makeHighPass(float sampleRate, float frequency);
  static IIRCoefficients
  makeHighPass(float sampleRate, float frequency, float Q);

  static IIRCoefficients makeBandPass(float sampleRate, float frequency);
  static IIRCoefficients
  makeBandPass(float sampleRate, float frequency, float Q);

  static IIRCoefficients makeBandStop(float sampleRate, float frequency);
  static IIRCoefficients
  makeBandStop(float sampleRate, float frequency, float Q);

  static IIRCoefficients makeNotch(float sampleRate, float frequency);
  static IIRCoefficients makeNotch(float sampleRate, float frequency, float Q);

  static IIRCoefficients makeAllPass(float sampleRate, float frequency);
  static IIRCoefficients
  makeAllPass(float sampleRate, float frequency, float Q);

  static IIRCoefficients makeLowShelf(float sampleRate,
                                      float cutOffFrequency,
                                      float Q,
                                      float gainFactor);

  static IIRCoefficients makeHighShelf(float sampleRate,
                                       float cutOffFrequency,
                                       float Q,
                                       float gainFactor);

  static IIRCoefficients makePeakFilter(float sampleRate,
                                        float centreFrequency,
                                        float Q,
                                        float gainFactor);

  uint32_t getFilterOrder() const noexcept;

  float getMagnitudeForFrequency(float frequency,
                                 float sampleRate) const noexcept;

  void getMagnitudeForFrequencyArray(const float *frequencies,
                                     float *magnitudes,
                                     uint32_t numSamples,
                                     float sampleRate) const noexcept;

  float getPhaseForFrequency(float frequency, float sampleRate) const noexcept;

  void getPhaseForFrequencyArray(float *frequencies,
                                 float *phases,
                                 uint32_t numSamples,
                                 float sampleRate) const noexcept;

  float *getRawCoefficients();

  std::vector<float> coefficients;
};

#endif // IIRCOEFFICIENTS_H 
