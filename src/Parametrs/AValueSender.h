//===------------------------ AValueSender.h ---------------------*- C++-*-===//
//===------------------ AValueSender class definition ---------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the AValueSender abstract class, which
/// define abstract methods, that send values to IChangeableParameter * 
///
//===----------------------------------------------------------------------===//

#ifndef AVALUESENDER_H
#define AVALUESENDER_H

#include "src/Parametrs/ChangeableParameter.h"

/// ValueSender class
class AValueSender {
public:
  /// Send @param value to connected parameters
  virtual void processValue(float value);
  /// Connect changeable parameter to sender
  virtual void addAutomatedParameter(IChangeableParameter *parameter);

protected:
  /// Vector of connected parameters
  std::vector<IChangeableParameter *> connectedParameters;
};

#endif /* !AVALUESENDER_H */
