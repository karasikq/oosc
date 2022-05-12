//===----------------------- WaveTable.h -------------------------*- C++-*-===//
//===-------------- WaveTable class definition ----------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the WaveTable class.
/// WaveTable used for store samples in chunk.
///
//===----------------------------------------------------------------------===//

#ifndef WAVETABLE_H
#define WAVETABLE_H

#include "src/AudioSettings.h"
#include "src/Utils/WaveShape.h"
#include <cinttypes>
#include <math.h>
#include <vector>

/// WaveTable class
class WaveTable {
public:
  /// WaveTable constructor
  /// @param size is a length of chunk
  WaveTable(unsigned int size = 2048);
  /// WaveTable constructor
  /// @param shape used for compute table by shape
  /// @param size is a length of chunk
  WaveTable(WaveShape::Shape shape, unsigned int size = 2048);
  /// WaveTable constructor
  /// Size of chunk should be a @param computedTable length
  WaveTable(std::vector<float> &computedTable);
  /// Default destructor
  virtual ~WaveTable();

  /// Set wavetable postion
  /// @param position define chunk offset
  void setPosition(unsigned int position);
  /// Returns wavetable position, i.e. chunk offset
  unsigned int getPosition() const;
  /// Returns max wavetable position, i.e. max chunk offset
  unsigned int getMaxPosition() const;
  /// Unsafe. Returns pointer to wavetable positioned sample
  float *getPositionedRaw();
  /// Unsafe. Returns pointer to wavetable
  float *getRaw();
  /// Returns pointer to wavetable data
  std::vector<float> *getData();
  /// Returns positioned start iterator
  std::vector<float>::const_iterator getStartPosition();
  /// Returns positioned end iterator
  std::vector<float>::const_iterator getEndPosition();
  /// Returns chunk size
  unsigned int getChunkSize() const;
  /// Returns wavetalbe size
  unsigned int tableSize() const;
  /// Returns unpositioned sample at index
  float getSample(unsigned int index) const;
  /// Set precomputed wavetable
  void SetTable(std::vector<float> &computedTable,
                unsigned int chunkSize = 2048);
  /// Set wavetable from shape
  void SetTable(WaveShape::Shape shape = WaveShape::SIN,
                unsigned int chunkSize = 2048);
  /// Returns wavetable sample at time
  virtual float Value(float time);

protected:
  /// Current waveshape
  WaveShape::Shape shape;
  /// Store wavetable samples
  std::vector<float> table;
  /// Size of wavetable
  unsigned int size;
  /// Wavetable position, i.e. chunk offset
  unsigned int position;
  /// Maximum wavetable position, i.e. chunk offset
  unsigned int maxPosition;
  /// Size of a chunk
  unsigned int chunkSize;
};

#endif // WAVETABLE_H
