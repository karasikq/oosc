//===--------------------------- MinMax.h ------------------------*- C++-*-===//
//===--------------------- MinMax struct definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the MinMax struct
///
//===----------------------------------------------------------------------===//

#ifndef MINMAX_H
#define MINMAX_H

#include <math.h>

template <typename T>
struct MinMax {
public:
  MinMax() : min(0), max(0), current(0) {}
  MinMax(T _min, T _max, T _current)
      : min(_min), max(_max), current(_current) {}
  /// Returns T = max - min
  inline T difference() { return max - min; }
  /// Returns progress @param value to min
  inline float percentToMin(T value) {
    return fabs(static_cast<float>((value - max)) /
                static_cast<float>((max - min)));
  }
  /// Returns progress @param value to max
  inline float percentToMax(T value) { return 1.0f - percentToMin(value); }
  /// Return value at @param time E [0, 1]
  inline T value(float time) { return min + (max - min) * time; }
  /// Return current value
  const inline T getCurrent() const { return current; };
  /// Clamps @param value and sets to current
  void setCurrent(T value) {
    if (value < min) {
      current = min;
      return;
    }
    if (value > max) {
      current = max;
      return;
    }
    current = value;
  }
  T min;
  T max;

private:
  T current;
};

#endif // MINMAX_H
