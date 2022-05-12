//===------------------ DistortionUIWrapper.h --------------------*- C++-*-===//
//===--------- DistortionUIWrapper class definition------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the DistortionUIWrapper class,
/// which is contains changeable parameters for effect and ready to connect
/// to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef DISTORTIONUIWRAPPER_H
#define DISTORTIONUIWRAPPER_H

#include "EffectUIWrapper.h"
#include "src/Parametrs/ChangeableParameter.h"

/// DistortionUIWrapper class
/// Contains changeable parameters for effect and ready to connect to knobs
class DistortionUIWrapper : public EffectUIWrapper {
  Q_OBJECT
public:
  DistortionUIWrapper();
  ~DistortionUIWrapper();

  registerChangeableParameter(int, distortionType, DistortionType);
  registerChangeableParameter(float, inputGain, InputGain);
  registerChangeableParameter(float, outputGain, OutputGain);
  registerChangeableParameter(float, tone, Tone);

private:
  /// Casts @param value to DistortionType and sets distrotionType
  void setDistortionType(int value);
};

#endif // DISTORTIONUIWRAPPER_H
