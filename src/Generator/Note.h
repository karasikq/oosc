//===----------------------------- Note.h ------------------------*- C++-*-===//
//===---------------------- Note class definition--------------------------===//
//===----------------- GeneratorNote struct definition---------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Note template class, which is
/// define note like a midi for Synthesizer.
///
/// This class is bad-designed and should be rewrited to avoid duplications.
///
//===----------------------------------------------------------------------===//

#ifndef NOTE_H
#define NOTE_H

#include "src/ADSR/ADSREnvelope.h"
#include "src/Utils/WaveShape.h"
#include <array>

/// Note Utilities
namespace NoteUtils {
/// Returns frequency of MIDI-note
constexpr float NoteToFreq(unsigned int note) {
  return 8 * powf(1.05946309436f, note);
}
} // namespace NoteUtils

/// Synthesizer note
template <size_t T>
class Note {
public:
  /// Default constructor
  Note() = default;
  /// Note constructor
  /// @param note is a MIDI-note
  /// @param velocity is a MIDI-velocity
  Note(unsigned int note, unsigned int velocity);
  /// MIDI-note
  unsigned int note;
  /// Frequency of note
  float freq;
  /// MIDI-velocity
  float velocity;
  /// Freeze state of note, that means envelope stops at peak time of this state
  ADSREnvelope::State freezeState;
  /// Note time
  float time;
  /// Envelope for each generator
  std::array<float, T> envelopeTime;
  /// State for each generator
  std::array<ADSREnvelope::State, T> state;

  /// Returns true if midi-note value equal
  friend inline bool operator==(const Note &lhs, const Note &rhs) {
    return lhs.note == rhs.note;
  }
};

template <size_t T>
Note<T>::Note(unsigned int note, unsigned int velocity) {
  this->note = note;
  freq = NoteUtils::NoteToFreq(note);
  this->velocity = (float)velocity / 256;
  freezeState = ADSREnvelope::State::DECAY;
  std::fill(envelopeTime.begin(), envelopeTime.end(), 0.0f);
  std::fill(state.begin(), state.end(), ADSREnvelope::State::ATTACK);
}

/// Additional struct that define note only for one generator
struct GeneratorNote {
  unsigned int note;
  float freq;
  float velocity;
  ADSREnvelope::State freezeState;
  float time;
  float envelopeTime;
  ADSREnvelope::State state;

  /// Returns GeneratorNote from Note<T>
  template <size_t T>
  static GeneratorNote fromNote(const Note<T> &note, uint32_t generatorId) {
    GeneratorNote gNote;
    gNote.note = note.note;
    gNote.freq = note.freq;
    gNote.velocity = note.velocity;
    gNote.freezeState = note.freezeState;
    gNote.time = note.time;
    gNote.envelopeTime = note.envelopeTime[generatorId];
    gNote.state = note.state[generatorId];
    return gNote;
  }
};

#endif // NOTE_H
