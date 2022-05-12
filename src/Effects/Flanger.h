//===-- Flanger.h - Flanger effect class definition -------------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Flanger class, which is
/// used for flanger effect.
///
//===----------------------------------------------------------------------===//

#ifndef FLANGER_H
#define FLANGER_H

#include "Effect.h"
#include "src/Utils/LFO.h"
#include "src/Utils/WaveShape.h"
#include <memory>

/// Flanger effect
class Flanger : public Effect {
public:
  /// Default constructor, creates delay buffer, which length depens on
  /// max property of @param delay
  Flanger(unsigned int numSamples, const MinMax<float> &delay);
  /// Default destructor
  ~Flanger() override;
  /// Apply Flanger effect to @param audioChannel
  void Apply(AudioChannel &audioChannel) override;

  protectedProperty(float, width, Width, 0.01f);
  protectedProperty(float, depth, Depth, 2.0f);
  protectedProperty(float, feedback, Feedback, 0.02f);
  protectedProperty(bool, invertedMode, InvertedMode, false);
  protectedProperty(float, lfoFrequency, LfoFrequency, 0.1f);
  protectedProperty(InterpolationType,
                    interpolation,
                    Interpolation,
                    InterpolationType::Linear);
  protectedProperty(WaveShape::Shape,
                    lfoShape,
                    LfoShape,
                    WaveShape::Shape::SIN);

  /// Set delay time, @param value should be in seconds
  void setDelay(float value);

private:
  /// Flanger buffer
  std::unique_ptr<AudioChannel> flangerBuffer;
  /// Delay range of flanger
  MinMax<float> delay;
  /// Buffer size
  unsigned int bufferSize;
  /// Number of samples
  unsigned int numSamples;

  /// LFO that used for flanger effect
  LFO lfo;
  /// LFO phase
  float lfoPhase;
  /// Sampled flanger time
  float flangerTimeSampled;
  /// Current position in flanger buffer
  unsigned int bufferPosition;
};

#endif // FLANGER_H
