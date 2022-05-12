//===------------------ CompressorUIWrapper.h --------------------*- C++-*-===//
//===-------- CompressorUIWrapper class definition-------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the CompressorUIWrapper class,
/// which is contains changeable parameters for effect and ready to connect
/// to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef COMPRESSORUIWRAPPER_H
#define COMPRESSORUIWRAPPER_H

#include "EffectUIWrapper.h"
#include "src/Parametrs/ChangeableParameter.h"

/// CompressorUIWrapper class
/// Contains changeable parameters for effect and ready to connect to knobs
class CompressorUIWrapper : public EffectUIWrapper {
  Q_OBJECT
public:
  CompressorUIWrapper();
  ~CompressorUIWrapper();

  registerChangeableParameter(float, threshold, Threshold);
  registerChangeableParameter(float, ratio, Ratio);
  registerChangeableParameter(float, attack, Attack);
  registerChangeableParameter(float, release, Release);
  registerChangeableParameter(float, gain, Gain);
};

#endif // COMPRESSORUIWRAPPER_H
