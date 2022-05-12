//===-- Phaser.h - Phaser effect class definition ---------------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Phaser class, which is
/// used for phaser effect.
///
//===----------------------------------------------------------------------===//

#ifndef PHASER_H
#define PHASER_H

#include "Effect.h"
#include "src/Utils/IIR/IIR.h"
#include "src/Utils/LFO.h"
#include <memory>
#include <vector>

/// Phaser effect
class Phaser : public Effect {
public:
  /// Default constructor
  Phaser(unsigned int sampleRate);
  /// Default destructor
  ~Phaser() override;

  /// Apply phaser effect for @param audioChannel
  void Apply(AudioChannel &audioChannel) override;
  protectedProperty(WaveShape::Shape,
                    lfoShape,
                    LfoShape,
                    WaveShape::Shape::SIN);
  protectedProperty(float, width, Width, 1000.0f);
  protectedProperty(float, depth, Depth, 1.0f);
  protectedReadProperty(int, numberOfFilters, NumberOfFilters, 4);
  protectedProperty(float, lfoFrequency, LfoFrequency, 0.1f);
  protectedProperty(float, filterFrequency, FilterFrequency, 1000.0f);
  protectedProperty(float, feedback, Feedback, 0.7f);

  /// Set number of filters. Creates new IIR Filters
  void setNumberOfFilters(int value);

private:
  /// Filters
  std::vector<IIRFilter> filters;
  /// Filtered outputs 
  std::vector<float> outputs;

  /// LFO for phaser effect
  LFO lfo;
  /// LFO phase
  float lfoPhase;
  /// Sample rate
  unsigned int sampleRate;
  /// Filter update interval(in samples)
  unsigned int updateInterval;
  /// Filter update counter(in samples)
  unsigned int updateCounter;

  /// Update filter coefficients. @param freq in Hz
  void updateFilters(float freq);
  /// Returns coefficients for IIR Filter, @param freq in Hz
  IIRCoefficients phaserCoefficients(float freq);
};

#endif // PHASER_H
