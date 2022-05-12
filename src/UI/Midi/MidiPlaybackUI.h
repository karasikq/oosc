//===---------------------- MidiPlaybackUI.h ---------------------*- C++-*-===//
//===-------------- MidiPlaybackUI class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the MidiPlaybackUI class, which is
/// the QtQuick wrapper for MidiPlayback
///
//===----------------------------------------------------------------------===//

#ifndef MIDIPLAYBACKUI_H
#define MIDIPLAYBACKUI_H

#include "ThirdParty/midifile/include/MidiFile.h"
#include "src/MixerOutput.h"
#include <QQuickPaintedItem>

/// MidiPlaybackUI class
/// The QtQuick wrapper for MidiPlayback
class MidiPlaybackUI : public QQuickItem {
  Q_OBJECT
  Q_PROPERTY(float playbackTime READ getPlaybackTime CONSTANT)
  Q_PROPERTY(SynthesizerControl *synthesizer WRITE setSynthesizer NOTIFY
                 synthesizerChanged)
public:
  MidiPlaybackUI();
  ~MidiPlaybackUI();

  /// Connects MidiPlayback to MixerOutput
  Q_INVOKABLE void attachPlayback();
  /// Disconnects MidiPlayback to MixerOutput
  Q_INVOKABLE void detachPlayback();
  /// Starts play midi-file
  Q_INVOKABLE void play();
  /// Stops playing midi-file
  Q_INVOKABLE void stop();
  /// Pause playing midi-file
  Q_INVOKABLE void pause();
  /// Load midi from system file
  Q_INVOKABLE void loadFromFile(const QVariant &fileName);
  /// Load midi from Qt file url
  Q_INVOKABLE void loadFromFileUrl(const QVariant &fileName);

  /// Returns current playback time in seconds
  float getPlaybackTime();

  /// Returns synthesizer that uses for playback
  SynthesizerControl *getSynthesizer();
  void setSynthesizer(SynthesizerControl *synthesizer);
signals:
  void synthesizerChanged();
  void playbackTimeChanged();
public slots:
  void timeChange();
  void loadMidi(const QVariant &fileName);

private:
  std::unique_ptr<MidiPlayback> midiPlayback;
};

#endif // MIDIPLAYBACKUI_H
