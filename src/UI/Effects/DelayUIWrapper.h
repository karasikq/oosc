//===--------------------- DelayUIWrapper.h ----------------------*- C++-*-===//
//===------------- DelayUIWrapper class definition-------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the DelayUIWrapper class,
/// which is contains changeable parameters for effect and ready to connect
/// to knobs.
///
//===----------------------------------------------------------------------===//

#ifndef DELAYUIWRAPPER_H
#define DELAYUIWRAPPER_H

#include "EffectUIWrapper.h"
#include "src/AudioSettings.h"
#include "src/Effects/Delay.h"
#include "src/Parametrs/ChangeableParameter.h"
#include <QQuickItem>
#include <memory>

/// DelayUIWrapper class
/// Contains changeable parameters for effect and ready to connect to knobs
class DelayUIWrapper : public EffectUIWrapper {
  Q_OBJECT
public:
  DelayUIWrapper();
  ~DelayUIWrapper();

  registerChangeableParameter(float, time, Time);
  registerChangeableParameter(float, mix, Mix);
  registerChangeableParameter(float, feedback, Feedback);
};

#endif // DELAYUIWRAPPER_H
