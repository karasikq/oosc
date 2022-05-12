//===-- Distortion.h - Distortion effect class definition -------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Distortion class, which is
/// used for distortion effect.
///
//===----------------------------------------------------------------------===//

#ifndef DISTORTION_H
#define DISTORTION_H

#include "src/Utils/IIR/IIR.h"
#include "Effect.h"
#include <memory>

/// Distortion effect
class Distortion : public Effect {
public:
  /// Distortion constructor
  explicit Distortion(uint8_t channelsCount = 2);
  /// Default destructor
  ~Distortion() override;

  /// Distortion type
  enum DistortionType {
    FullWave,
    HalfWave,
    HardClipping,
    SoftClipping,
    Exponential
  };

  /// Function that apply Distortion effect to AudioChannel
  void Apply(AudioChannel &audioChannel) override;

  protectedProperty(DistortionType,
                    distortionType,
                    DistortionType,
                    DistortionType::HardClipping);
  protectedProperty(float, inputGain, InputGain, 1.0f);
  protectedProperty(float, outputGain, OutputGain, 1.0f);
  protectedProperty(float, tone, Tone, 1.0f);

private:
  /// Vector of filters
  std::vector<IIRFilter> filters;
  /// Update filters coefficients
  void updateFilters();
  /// Returns distortion coefficients, that depends on 
  /// @param freq - frequency and @param gain
  IIRCoefficients distortionCoefficients(float freq, float gain);
};

#endif // DISTORTION_H
