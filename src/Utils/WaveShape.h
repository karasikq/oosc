//===------------------------ WaveShape.h ------------------------*- C++-*-===//
//===---------------- WaveShape struct definition -------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the WaveShape struct
///
//===----------------------------------------------------------------------===//

#ifndef WAVESHAPE_H
#define WAVESHAPE_H

#define M_PI_2M 6.28318530717958647692

struct WaveShape {
public:
  enum Shape { SIN, SQUARE, SAW, SAW2 };
  Shape shape;

  /// Returns shaped value at @param time
  virtual float Value(float time);
  /// Returns shaped with @param shape value at @param time
  virtual float Value(float time, Shape shape);
};

#endif // WAVESHAPE_H
