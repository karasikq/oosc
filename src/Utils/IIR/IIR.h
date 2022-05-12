//===----------------------------- IIR.h -------------------------*- C++-*-===//
//===---------------------- IIR class definition --------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the IIR class, which is the Infinite
/// Impulse Response filter.
///
//===----------------------------------------------------------------------===//

#ifndef IIR_H
#define IIR_H

#include <array>

#include "IIRCoefficients.h"

/// Infinite impulse response
class IIRFilter {
public:
  IIRFilter();
  IIRFilter(IIRCoefficients &_coefficients);

  /// Filter coefficients
  IIRCoefficients coefficients;
  void setCoefficients(IIRCoefficients _coefficients);

  /// Reset filter states and sets its to @param resetToValue 
  void reset(float resetToValue);
  inline void reset() { reset(0.0f); }

  void prepare() noexcept;

  /// Returns filtered @param sample
  float process(float sample) noexcept;
  /// Filters @param inputBuffer
  void process(std::vector<float> &inputBuffer) noexcept;
  /// Snap buffer to zero
  void snapToZero() noexcept;

private:
  void check();

  float *memory = nullptr;
  float *state = nullptr;
  uint32_t order = 0;

  /// Snaps float to zero to avoid overflow
  static float snapToZero(float n) {
    return (!(n < -1.0e-8f || n > 1.0e-8f)) ? n = 0.0f : n;
  }
};

#endif // IIR_H
