//===-- Effect.h - Base effect class definition -----------------*- C++ -*-===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Effect class, which is
/// a base class for all effects.
///
//===----------------------------------------------------------------------===//

#ifndef EFFECT_H
#define EFFECT_H

/// Macros that generate property with type @param type and get-set for it
/// @param name means name of property, @param Name used for camelCase
/// @param value it's a default value
/// This macros should be used only for describe effects properties!
#define protectedProperty(type, name, Name, value)                             \
protected:                                                                     \
  type name = value;                                                           \
                                                                               \
public:                                                                        \
  type get##Name() { return name; }                                            \
  void set##Name(type val) { name = val; }

/// Macros that generate property with type @param type and get-set for it
/// @param name means name of property, @param Name used for camelCase
/// @param value it's a default value
/// This macros should be used only for describe effects properties!
#define protectedReadProperty(type, name, Name, value)                         \
protected:                                                                     \
  type name = value;                                                           \
                                                                               \
public:                                                                        \
  type get##Name() { return name; }

#include "src/Utils/AudioChannel.h"
#include "src/Utils/MinMax.h"

/// Interpolation enum
enum InterpolationType { NearestNeighbour, Linear, Cubic };

/// Base class for all effects
class Effect {
public:
  /// Default constructor
  Effect() = default;
  /// Default destructor
  virtual ~Effect() = default;
  /// Pure virtual function for apply effect to AudioChannel
  virtual void Apply(AudioChannel &audioChannel) = 0;
  /// Bypass property
  protectedProperty(bool, bypass, Bypass, false);
};

#endif // EFFECT_H
