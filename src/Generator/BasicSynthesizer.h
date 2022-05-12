//===------------------------ BasicSynthesizer.h -----------------*- C++-*-===//
//===---------------- BasicSynthesizer class definition--------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the AGenerator class, which is
/// a base class for all generators(oscillators).
///
//===----------------------------------------------------------------------===//

#ifndef BASICSYNTHESIZER_H
#define BASICSYNTHESIZER_H

#include "src/Generator/Synthesizer.h"

/// Basic Synthesizer
/// Contains 3 oscillators
class BasicSynthesizer : public Synthesizer<3> {
public:
  BasicSynthesizer();
  /// Configure generators
  void setupGenerators() override;
  /// Set master volume
  /// @param value should be linear
  void setMasterVolume(float value) override;
};

#endif // BASICSYNTHESIZER_H
