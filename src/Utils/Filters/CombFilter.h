//===-------------------------- CombFilter.h ---------------------*- C++-*-===//
//===------------------ CombFilter class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the CombFilter class
///
//===----------------------------------------------------------------------===//

#ifndef COMBFILTER_H
#define COMBFILTER_H

#include <iostream>
#include <vector>

/// CombFilter class
class CombFilter {
public:
  CombFilter(unsigned int bufferSize);
  ~CombFilter();
  /// Fills buffer with zeros
  void clear();
  /// Returns filtered value
  float process(const float &input, const float &damp, const float &feedback);

private:
  std::vector<float> buffer;
  int bufferIndex;
  float last;
};

#endif // COMBFILTER_H
