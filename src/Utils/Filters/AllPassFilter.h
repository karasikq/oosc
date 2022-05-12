//===----------------------- AllPassFilter.h ---------------------*- C++-*-===//
//===--------------- AllPassFilter class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the AllPassFilter class
///
//===----------------------------------------------------------------------===//

#ifndef ALLPASSFILTER_H
#define ALLPASSFILTER_H

#include <iostream>
#include <vector>

/// AllPassFilter class
class AllPassFilter {
public:
  AllPassFilter(unsigned int bufferSize);
  /// Fills buffer with zeros
  void clear();
  /// Returns filtered value
  float process(float input);

private:
  std::vector<float> buffer;
  int bufferIndex = 0;
};

#endif // ALLPASSFILTER_H
