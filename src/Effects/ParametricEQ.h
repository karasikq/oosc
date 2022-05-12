//===-- ParametricEQ.h - Eq effect class definition -------------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ParametricEQ class, which is
/// used for Eq effect.
///
//===----------------------------------------------------------------------===//

#ifndef PARAMETRICEQ_H
#define PARAMETRICEQ_H

#include "Effect.h"
#include "src/AudioSettings.h"
#include "src/Utils/IIR/IIR.h"
#include <memory>

/// Eq effect
class ParametricEQ : public Effect {
public:
  /// Filter type
  enum FilterType {
    LowPass,
    HighPass,
    LowShelf,
    HighShelf,
    BandPass,
    BandStop,
    AllPass,
    Notch,
    Peak
  };
  /// Construct Eq depends only at @param type
  ParametricEQ(FilterType type,
               uint32_t numSamples = AudioSettings::BUFFER_SIZE);
  /// Construct Eq
  /// @param gain should be in dB
  /// @param cutoff should be in Hz
  ParametricEQ(FilterType type,
               float cutoff,
               float q = M_SQRT1_2f32,
               float gain = 12.0f,
               uint32_t numSamples = AudioSettings::BUFFER_SIZE);
  /// Default constructor
  ParametricEQ(uint32_t numSamples = AudioSettings::BUFFER_SIZE);
  /// Default destructor
  ~ParametricEQ() override;

  /// Set @param frequency, should be in Hz
  void setFrequency(float frequency);
  /// Set filter type
  void setFilterType(FilterType type);
  /// Set Q-Factor
  void setQ(float q);
  /// Set Gain, should be in dB
  void setGain(float gain);

  /// Apply Eq effect to AudioChannel
  void Apply(AudioChannel &audioChannel) override;

private:
  /// IIR Filter for left channel
  std::unique_ptr<IIRFilter> iirLeft;
  /// IIR Filter for right channel
  std::unique_ptr<IIRFilter> iirRight;

  /// Number of samples
  uint32_t numSamples = AudioSettings::BUFFER_SIZE;
  /// Sample rate
  float sampleRate;
  /// Filter type
  FilterType type;
  /// Cutoff frequency in Hz
  float cutoffFrequency;
  /// Q-Factor
  float QFactor;
  /// Gain in dB
  float gain;

  /// Update filter coefficients
  void updateCoefficients();
  /// Create default filter
  void createFilter();

  /// dB to voltage(linear)
  inline static float FtoD(float dB) { return powf(10, dB * 0.05f); }
};

#endif // PARAMETRICEQ_H
