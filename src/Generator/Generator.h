//===------------------------- Generator.h -----------------------*- C++-*-===//
//===------------------ Generator class definition-------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Generator class, which is
/// a default oscillator.
///
//===----------------------------------------------------------------------===//

#ifndef GENERATOR_H
#define GENERATOR_H

#include "src/Utils/AudioChannel.h"
#include "AGenerator.h"
#include <math.h>
#include <random>
#include <vector>

/// Oscillator
class Generator : public AGenerator {
public:
  explicit Generator(unsigned int generatorID);
  ~Generator() override;

  const unsigned int maxUnisonVoices = 16;
  const unsigned long unisonSeed = 1337;

  void setPan(float value);
  void setLevel(float value);
  void setOctaveOffset(int value);
  void setSemitoneOffset(int value);
  void setPhase(float value);
  void setCents(int value);
  void setUnisonVoices(unsigned int value);
  void setUnisonPan(float value);
  void setUnisonLevel(float value);
  void setUnisonFine(float value);

  std::pair<float, float> Value(GeneratorNote &note) override;

private:
  float pan = 0.0f;
  float level = 1.0f;
  int octaveOffset = 0;
  int semitone = 0.0f;
  float phase = 0.0f;
  float cents = 0;
  unsigned int unisonVoices = 3;
  float unisonPan = 0.5f;
  float unisonLevel = 0.5f;
  float unisonFine = 0.5f;

  /// Struct for unison ranges
  template <typename T>
  struct UnisonVoice {
    UnisonVoice(T p, T l, T f) : pan(p), level(l), fine(f) {}
    T pan;
    T level;
    T fine;
  };

  /// Generator for randomize unison
  std::mt19937 gen;
  /// Unison cents range
  std::uniform_int_distribution<> fineRange;
  /// Unison pan range
  std::uniform_int_distribution<> panRange;
  /// Unison level range
  std::uniform_int_distribution<> levelRange;
  /// Computed unison 
  /// Used for get ranged unison data
  std::vector<UnisonVoice<float>> computedUnison;
  /// Vector of ranges
  std::vector<UnisonVoice<MinMax<float>>> unisonRange;
  /// Calculate unison and push result to @computedUnison
  void calculateUnison();
};

#endif // GENERATOR_H
