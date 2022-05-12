//===-------------------------- LFO.h ----------------------------*- C++-*-===//
//===------------------- LFO struct definition ----------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the LFO struct.
///
//===----------------------------------------------------------------------===//

#ifndef LFO_H
#define LFO_H

#include "WaveShape.h"

struct LFO : WaveShape {
  /// Returns lfo output at @param time
  float Value(float time) override;
  /// Returns shaped with @param shape lfo output at @param time
  float Value(float time, Shape shape) override;
};

#endif // LFO_H
