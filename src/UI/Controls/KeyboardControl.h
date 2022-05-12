//===------------------- KeyboardControl.h -----------------------*- C++-*-===//
//===----------- KeyboardControl class definition -------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the KeyboardControl class, which
/// is used to draw keyboard and display active notes.
///
//===----------------------------------------------------------------------===//

#ifndef KEYBOARDCONTROL_H
#define KEYBOARDCONTROL_H

#include "src/UI/SynthesizerControls/SynthesizerControl.h"
#include <QQuickPaintedItem>

/// Keyboard control
/// Draws keyboard
class KeyboardControl : public QQuickPaintedItem {
  Q_OBJECT
  Q_PROPERTY(SynthesizerControl *synthesizer WRITE attachSynthesizer)
  Q_PROPERTY(
      QColor keyColor READ getKeyColor WRITE setKeyColor NOTIFY keyColorChanged)
  Q_PROPERTY(QColor sharpColor READ getSharpColor WRITE setSharpColor NOTIFY
                 sharpColorChanged)
  Q_PROPERTY(QColor keyActiveColor READ getActiveKeyColor WRITE
                 setActiveKeyColor NOTIFY activeKeyColorChanged)
  Q_PROPERTY(QColor sharpActiveColor READ getActiveSharpColor WRITE
                 setActiveSharpColor NOTIFY activeSharpColorChanged)
public:
  KeyboardControl(QQuickItem *parent = 0);
  ~KeyboardControl();

  /// Draws keyboard & active notes
  void paint(QPainter *painter) override;
  /// Connects Keyboard signals to note events at @param synthesizer
  void attachSynthesizer(SynthesizerControl *synthesizer);

  QColor getKeyColor();
  QColor getSharpColor();
  QColor getActiveKeyColor();
  QColor getActiveSharpColor();

  void setKeyColor(QColor color);
  void setSharpColor(QColor color);
  void setActiveKeyColor(QColor color);
  void setActiveSharpColor(QColor color);

public slots:
  void noteOn(unsigned int note, unsigned int velocity);
  void noteOff(unsigned int note);
  void allNoteOff();

signals:
  void keyColorChanged(QColor color);
  void sharpColorChanged(QColor color);
  void activeKeyColorChanged(QColor color);
  void activeSharpColorChanged(QColor color);

private:
  /// Min MIDI-note value from which keyboard start to drawn
  uint32_t minNote;
  /// Max MIDI-note value from which keyboard start to drawn
  uint32_t maxNote;
  /// C, D, E, F, G, A, B notes color
  QColor keyColor;
  /// F♯, C♯, G♯, D♯, A♯, E♯, B♯ notes color
  QColor sharpColor;
  /// Color when note highlighted
  QColor activeKeyColor;
  /// Color when sharp note highlighted
  QColor activeSharpColor;

  /// Map of notes. bool indicates active state of note
  std::map<unsigned int, bool> keyboardNotes;
};

#endif // !KEYBOARDCONTROL_H
