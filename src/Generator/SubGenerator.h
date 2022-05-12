//===---------------------- SubGenerator.h -----------------------*- C++-*-===//
//===------------- SubGenerator class definition---------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the SubGenerator class, which is
/// a suboscillator.
///
//===----------------------------------------------------------------------===//

#ifndef SUBGENERATOR_H
#define SUBGENERATOR_H

#include "src/Generator/AGenerator.h"
#include "src/Utils/AudioChannel.h"
#include "src/Utils/LFO.h"
#include "src/Utils/WaveShape.h"
#include <math.h>
#include <random>
#include <vector>

/// Sub oscillator
class SubGenerator : public AGenerator {
public:
  explicit SubGenerator(unsigned int generatorID);
  ~SubGenerator() override;

  /// Returns shape of this oscillator
  inline WaveShape::Shape getShape() const { return shape; }

  void setPan(float value);
  void setLevel(float value);
  void setOctaveOffset(int value);
  void setShape(int value);

  /// Return an output pair of left and right channels
  std::pair<float, float> Value(GeneratorNote &note) override;

private:
  /// Pan
  /// 0.f - Left, 1.f - Right
  float pan = 0.0f;
  /// Linear gain
  float level = 1.0f;
  /// Octave offset
  int octaveOffset = 0;
  /// Current shape
  WaveShape::Shape shape = WaveShape::Shape::SIN;

  LFO lfo;
};

#endif // SUBGENERATOR_H
