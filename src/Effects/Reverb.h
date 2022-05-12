//===-- Reverb.h - Reverb effect class definition ---------------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Reverb class, which is
/// used for reverb effect.
///
//===----------------------------------------------------------------------===//

#ifndef REVERB_H
#define REVERB_H

#include "Effect.h"
#include "src/Utils/Filters/AllPassFilter.h"
#include "src/Utils/Filters/CombFilter.h"
#include <memory>
#include <vector>

/// Reverb effect
class Reverb : public Effect {
public:
  /// Default constructor
  Reverb(unsigned int sampleRate);
  /// Default destructor
  ~Reverb() override;
  /// Apply Reverb effect to @param audioChannel
  void Apply(AudioChannel &audioChannel) override;

  protectedReadProperty(float, width, Width, 1.0f);
  protectedReadProperty(float, roomSize, RoomSize, 0.5f);
  protectedReadProperty(float, damping, Damping, 0.5f);
  protectedReadProperty(float, wet, Wet, 0.5f);
  protectedReadProperty(float, dry, Dry, 0.5f);
  protectedReadProperty(int, freeze, Freeze, 0);

  /// Set reverb width
  void setWidth(float value);
  /// Set reverb damping
  void setDamping(float value);
  /// Set reverb room size 
  void setRoomSize(float value);
  /// Set reverb wet-factor
  void setWet(float value);
  /// Set reverb dry-factor
  void setDry(float value);
  /// Set reverb freeze, @param value should be 0 or 1
  void setFreeze(int value);

private:
  /// Comb filter count
  const size_t combsCount = 8;
  /// All-pass filter count
  const size_t allPassCount = 4;
  /// Vector of all-pass filters
  std::vector<std::vector<AllPassFilter>> allPassFilters;
  /// Vector of comb filters
  std::vector<std::vector<CombFilter>> combFilters;

  float gain, dryGain, wetGainL, wetGainR;
  float currentDamping, feedback;

  void updateScale();
};

#endif // REVERB_H
