//===-- AGenerator.h - AGenerator class definition ---------------*- C++-*-===//
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

#ifndef AGENERATOR_H
#define AGENERATOR_H

#include "Note.h"
#include "WaveTable.h"
#include "src/ADSR/ADSREnvelope.h"
#include "src/Utils/AudioChannel.h"
#include "src/Utils/MinMax.h"
#include <memory>
#include <vector>

/// Base class for all generators
class AGenerator {
public:
  /// Default constructor
  AGenerator(unsigned int generatorID);
  /// Default destructor
  virtual ~AGenerator();

  /// Return pair of amplitudes for left(first) and right(second) channels
  virtual std::pair<float, float> Value(GeneratorNote &note);

  /// Set wavetable for generator
  void setWavetable(const std::shared_ptr<WaveTable> &waveTable);
  /// Set envelope for generator
  void setEnvelope(const std::shared_ptr<ADSREnvelope> &envelope);
  /// Set bypass
  /// if @param value false generator return (0, 0)
  void setBypass(bool value);

  /// Returns generator Id
  unsigned int getId();
  /// Return wavetable
  WaveTable *getWaveTable();
  /// Return enveloper
  ADSREnvelope *getEnvelope();
  inline bool isBypass() const { return bypass; }

  /// Clear generator buffer
  virtual void clear();
  /// Add sample to generator buffer
  virtual void addSample(const std::pair<float, float> &data, uint32_t sample);
  /// Returns audio channel
  const AudioChannel *getChannel() const { return &audioChannel; }

protected:
  /// Generator buffer
  AudioChannel audioChannel;
  /// Generator ID
  unsigned int generatorID;

  std::shared_ptr<WaveTable> waveTable;
  std::shared_ptr<ADSREnvelope> envelope;

  bool bypass;
};

#endif // AGENERATOR_H
