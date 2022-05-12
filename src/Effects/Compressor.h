//===-- Compressor.h - Compressor effect class definition --------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Compressor class, which is
/// used for compressor effect.
///
//===----------------------------------------------------------------------===//

#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include "Effect.h"
#include <math.h>

/// Compressor effect
class Compressor : public Effect {
public:
  /// Default constructor 
  Compressor();
  /// Constructor for Compressor effect
  /// @param attack and @param release should be in secodns
  Compressor(float threshold,
             float ratio,
             float attack,
             float release,
             float gain);
  /// Default destructor
  ~Compressor() override;

  /// Function that apply Compressor effect to AudioChannel
  void Apply(AudioChannel &audioChannel) override;

  protectedProperty(float, threshold, Threshold, -12.0f);
  protectedProperty(float, ratio, Ratio, 50.0f);
  protectedProperty(float, attack, Attack, 0.002f);
  protectedProperty(float, release, Release, 0.2f);
  protectedProperty(float, gain, Gain, 0.0f);

private:
  /// Gain of previous sample 
  float previousGain;

  /// Returns scaled time
  inline float expTime(float value) {
    return value == 0.0f ? 0.0f
                         : powf(INVERSE_E, value / AudioSettings::SAMPLE_RATE);
  }
  /// Inverse E-number
  const float INVERSE_E = 1.0f / M_E;
};

#endif // COMPRESSOR_H
