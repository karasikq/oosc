//===---------------------- EqUIWrapper.h ------------------------*- C++-*-===//
//===--------------- EqUIWrapper class definition -------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the EqUIWrapper class, which is
/// contains changeable parameters for effect and ready to connect to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef EQUIWRAPPER_H
#define EQUIWRAPPER_H

#include "EffectUIWrapper.h"
#include "src/Parametrs/ChangeableParameter.h"

/// EqUIWrapper class
/// Contains changeable parameters for effect and ready to connect to knobs
class EqUIWrapper : public EffectUIWrapper {
  Q_OBJECT
public:
  EqUIWrapper();
  ~EqUIWrapper();

  registerChangeableParameter(float, frequency, Frequency);
  registerChangeableParameter(int, filterType, FilterType);
  registerChangeableParameter(float, qFactor, QFactor);
  registerChangeableParameter(float, gain, Gain);

private:
  /// Casts @param value to FilterType and sets filterType
  void setFilterType(int value);
};

#endif // EQUIWRAPPER_H
