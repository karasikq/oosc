//===-- Delay.h - Delay effect class definition -----------------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Delay class, which is
/// used for delay effect.
///
//===----------------------------------------------------------------------===//

#ifndef DELAY_H
#define DELAY_H

#include "Effect.h"
#include <memory>

/// Delay effect
class Delay : public Effect {
public:
  /// Delay constructor that create delay buffer, lenght of that depends
  /// on max property of @param timeRange
  Delay(unsigned int numSamples, const MinMax<float> &timeRange);
  /// Default destructor
  ~Delay() override;
  /// Function that apply Delay effect to AudioChannel
  void Apply(AudioChannel &audioChannel) override;

  protectedProperty(float, mix, Mix, 1.0f);
  protectedProperty(float, feedback, Feedback, 0.7f);
  protectedReadProperty(float, time, Time, 0.0f);

  /// Set delay time, @param value should be in seconds
  void setTime(float value);

private:
  /// Delay buffer
  std::unique_ptr<AudioChannel> delayBuffer;
  /// Delay time range
  MinMax<float> timeRange;
  /// Buffer size
  unsigned int bufferSize;
  /// Number of samples
  unsigned int numSamples;

  /// Sampled delay time
  float delayTimeSampled;

  /// Current position at delay buffer
  unsigned int bufferPosition;
};

#endif // DELAY_H
