//===-- Chorus.h - Chorus effect class definition ---------------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Chorus class, which is
/// used for chorus effect.
///
//===----------------------------------------------------------------------===//

#ifndef CHORUS_H
#define CHORUS_H

#include <memory>

#include "Effect.h"
#include "src/Utils/LFO.h"

/// Chorus effect
class Chorus : public Effect {
public:
  /// Constructor that create Chorus class with delay and depth
  /// buffers, lenght of buffers depends on max attribute of
  /// delay and depth
  Chorus(unsigned int _numSamples,
         const MinMax<float> &_delay,
         const MinMax<float> &_depth);

  /// Default destructor
  ~Chorus() override;

  /// Function that apply Chorus effect to AudioChannel
  void Apply(AudioChannel &audioChannel) override;

  /// Voices property
  protectedProperty(uint8_t, voices, Voices, 2);
  /// Depth property
  protectedProperty(float, depth, Depth, 1.0f);
  /// Rate property
  protectedProperty(float, rate, Rate, 2.0f);
  /// Stereo property
  protectedProperty(bool, stereo, Stereo, false);
  /// Stereo phase property
  protectedProperty(float, stereoPhase, StereoPhase, M_PI_2);

  /// Sets current delay, @param value should be in seconds
  void setDelay(float value);
  /// Sets current width, @param value should be in seconds
  void setWidth(float value);

private:
  /// Audio buffer for chorus effect
  std::unique_ptr<AudioChannel> chorusBuffer;
  /// Delay time range
  MinMax<float> delay;
  /// Width time range
  MinMax<float> sweepWidth;

  /// LFO for chorus effect processing
  LFO lfo;
  /// Sampled chorus time
  float chorusTimeSampled;
  /// Current position in chorus buffer
  unsigned int bufferPosition;
  /// Number of samples per block
  unsigned int numSamples;
};

#endif // CHORUS_H
