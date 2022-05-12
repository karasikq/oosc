//===----------------------- Synthesizer.h -----------------------*- C++-*-===//
//===----------- Synthesizer template class definition---------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the Synthesizer template class.
///
//===----------------------------------------------------------------------===//

#ifndef SYNTHESIZER_H
#define SYNTHESIZER_H

#include <functional>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <vector>

#include "src/AudioSettings.h"
#include "src/Effects/Delay.h"
#include "src/Generator/AGenerator.h"
#include "src/Generator/Generator.h"
#include "src/Generator/GeneratorsThreadPool.h"
#include "src/Utils/AudioChannel.h"
#include "src/Utils/IIR/IIR.h"

/// Synthesizer
/// @param T defines count of AGenerator's
template <size_t T>
class Synthesizer {
public:
  enum SoundMethod { Mono, Stereo };

  /// Default construtor
  Synthesizer();
  /// Default destructor
  virtual ~Synthesizer();
  /// Virtual function for generator configuration
  virtual void setupGenerators();

  /// Not Thread-safe function, that add note to processing map
  /// @param note is a MIDI-note
  /// @param velocity is a MIDI-velocity
  void addNote(unsigned char note, unsigned char velocity);
  /// Thread-safe function, that start note processing
  /// @param note is a MIDI-note
  /// @param velocity is a MIDI-velocity
  void noteOn(unsigned char note, unsigned char velocity);
  /// Thread-safe function, that stop note processing
  /// @param note is a MIDI-note
  void noteOff(unsigned char note);
  /// Thread-safe function, that stop all notes processing
  void allNoteOff();

  /// Stores Generators
  std::array<std::unique_ptr<AGenerator>, T> generators;
  /// Synthesizer buffer
  std::unique_ptr<AudioChannel> audioChannel;
  /// Returns c-style array of synthesizer output
  float *getRawOutput();

  /// Attach effect to Synthesizer
  void attachEffect(Effect *effect);
  /// Remove effect from Synthesizer
  void detachEffect(Effect *effect);

  /// Set master volume 
  /// @param value is linear
  virtual void setMasterVolume(float value);

  /// Called when data processed
  /// @param data is a left channel data
  /// @param from is a iterator from which data should be read
  /// @param to is a iterator to which data should be read
  std::function<void(const std::vector<float> &data,
                     std::vector<float>::const_iterator from,
                     std::vector<float>::const_iterator to)>
      leftDataCallback;
  /// Called when data processed
  /// @param data is a right channel data
  /// @param from is a iterator from which data should be read
  /// @param to is a iterator to which data should be read
  std::function<void(const std::vector<float> &data,
                     std::vector<float>::const_iterator from,
                     std::vector<float>::const_iterator to)>
      rightDataCallback;
  /// Called when data processed
  /// @param data is a mixed channel data
  /// @param from is a iterator from which data should be read
  /// @param to is a iterator to which data should be read
  std::function<void(const std::vector<float> &data,
                     std::vector<float>::const_iterator from,
                     std::vector<float>::const_iterator to)>
      mixedDataCallback;
  /// Called when data processed
  /// @param channel is a audio channel pointer
  std::function<void(AudioChannel *channel)> channelDataCallback;
  /// Called when note is start playing
  /// @param note is a last started note
  std::function<void(const Note<T> &note)> lastPlayedNoteCallback;

protected:
  SoundMethod soundMethod;
  float masterVolume = 1.0f;

  const uint32_t bufferSize = AudioSettings::BUFFER_SIZE * 2;
  float *rawData;

  /// Store notes
  /// Key is a MIDI-note value
  /// Value is a vector of notes that MIDI-note value equals to Key
  std::map<uint8_t, std::vector<Note<T>>> noteMap;
  /// Mutex to thread-safe noteMap manipulations
  std::mutex noteMutex;
  /// Iterator to last started note
  typename std::vector<Note<T>>::iterator lastNote;
  /// Iterator to end of note vector at noteMap[key]
  typename std::vector<Note<T>>::iterator notesEndIterator;

  /// Generator Thread Pool
  /// Manage threads and generator tasks
  std::unique_ptr<GeneratorsThreadPool> generatorsThreadPool;
  /// Current processing note
  /// Need for @see generatorThread
  Note<T> currentNote;
  /// Define generator task
  /// Should be executing at @see generatorsThreadPool
  void generatorThread(unsigned int gID);

  /// List of audio-effects
  std::list<Effect *> effects;
};

#include "Synthesizer.tpp"

#endif // SYNTHESIZER_H
