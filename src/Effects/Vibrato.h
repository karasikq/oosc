//===-- Vibrato.h - Vibrato effect class definition -------------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Vibrato class, which is
/// used for Vibrato effect.
///
//===----------------------------------------------------------------------===//

#ifndef VIBRATO_H
#define VIBRATO_H

#include "src/Utils/LFO.h"
#include "Effect.h"
#include <memory>

/// Vibrato effect
class Vibrato : public Effect {
public:
  /// Construct vibrato effect, create delay buffer, which length
  /// depends on max property of @param timeRange
  Vibrato(const MinMax<float> &timeRange);
  /// Default constructor
  ~Vibrato() override;

  /// Apply vibrato effect to @param audioChannel
  void Apply(AudioChannel &audioChannel) override;

  protectedProperty(WaveShape::Shape, lfoShape, LfoShape,
                    WaveShape::Shape::SIN);
  protectedProperty(float, width, Width, 0.005f);
  protectedProperty(float, lfoFrequency, LfoFrequency, 1.0f);
  protectedProperty(InterpolationType, interpolation, Interpolation,
                    InterpolationType::NearestNeighbour);

private:
  /// Delay buffer for vibrato effect
  std::unique_ptr<AudioChannel> delayBuffer;
  /// Delay time range
  MinMax<float> timeRange;
  /// Sampled delay time
  float delayTimeSampled;
  /// Current buffer position
  unsigned int bufferPosition;

  /// LFO for Vibrato effect
  LFO lfo;
  /// LFO phase
  float lfoPhase;
  /// Audio buffer size
  unsigned int bufferSize;
};

#endif // VIBRATO_H
