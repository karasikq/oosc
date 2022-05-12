//===-------------------- SynthesizerControl.h -------------------*- C++-*-===//
//===------------ SynthesizerControl class definition ---------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the SynthesizerControl class, which
/// is the Qt Quick wrapper for BasicSynthesizer
///
//===----------------------------------------------------------------------===//

#ifndef SYNTHESIZERCONTROL_H
#define SYNTHESIZERCONTROL_H

#include "src/Generator/Synthesizer.h"
#include "src/UI/SynthesizerControls/AGeneratorControl.h"
#include "src/Generator/BasicSynthesizer.h"
#include <QQuickItem>
#include <QVariant>
#include <map>
#include <memory>

/// SynthesizerControl class
/// The Qt Quick wrapper for BasicSynthesizer
class SynthesizerControl : public QQuickItem {
  Q_OBJECT
  Q_PROPERTY(QVariant generatorControls WRITE setGeneratorControls)
  Q_PROPERTY(IChangeableParameter *gain READ getGain CONSTANT)
  Q_PROPERTY(BasicSynthesizer *synthesizer READ getSynthesizer CONSTANT)
public:
  SynthesizerControl(QQuickItem *parent = 0);

  /// Connects effect to synthesizer
  Q_INVOKABLE void attachEffect(Effect *effect);
  void keyPressEvent(QKeyEvent *event) override;
  void keyReleaseEvent(QKeyEvent *event) override;

  IChangeableParameter *getGain() { return &gain; }

  Q_INVOKABLE void attachGeneratorControl(AGeneratorControl *generatorControl);
  void setGeneratorControls(const QVariant &genators);

  BasicSynthesizer *getSynthesizer();
  Q_INVOKABLE void connectToOutput(ADataReceiver *receiver);
  Q_INVOKABLE void connectToOutputLeft(ADataReceiver *receiver);
  Q_INVOKABLE void connectToOutputRight(ADataReceiver *receiver);
  Q_INVOKABLE void connectToOutputMixed(ADataReceiver *receiver);
  Q_INVOKABLE void connectToOutputNote(ADataReceiver *receiver);

  template <typename T>
  void connectToOutput(T *object, void (T::*slot)(AudioChannel *)) {
    connect(this, &SynthesizerControl::dataGeneratedChannel, object, slot);
  }
  template <typename T>
  void
  connectToOutputLeft(T *object,
                      void (T::*slot)(const std::vector<float> &,
                                      std::vector<float>::const_iterator,
                                      std::vector<float>::const_iterator)) {
    connect(this, &SynthesizerControl::dataGeneratedLeft, object, slot);
  }
  template <typename T>
  void
  connectToOutputRight(T *object,
                       void (T::*slot)(const std::vector<float> &,
                                       std::vector<float>::const_iterator,
                                       std::vector<float>::const_iterator)) {
    connect(this, &SynthesizerControl::dataGeneratedRight, object, slot);
  }
  template <typename T>
  void
  connectToOutputMixed(T *object,
                       void (T::*slot)(const std::vector<float> &,
                                       std::vector<float>::const_iterator,
                                       std::vector<float>::const_iterator)) {
    connect(this, &SynthesizerControl::dataGeneratedMixed, object, slot);
  }
  template <typename T>
  void connectToOutputNote(T *object, void (T::*slot)(const Note<3> &note)) {
    connect(this, &SynthesizerControl::lastPlayedNote, object, slot);
  }

  void dataReceiveLeft(const std::vector<float> &data,
                       std::vector<float>::const_iterator from,
                       std::vector<float>::const_iterator to);
  void dataReceiveRight(const std::vector<float> &data,
                        std::vector<float>::const_iterator from,
                        std::vector<float>::const_iterator to);
  void dataReceiveMixed(const std::vector<float> &data,
                        std::vector<float>::const_iterator from,
                        std::vector<float>::const_iterator to);
  void dataReceiveChannel(AudioChannel *channel);
  void lastNoteReceived(const Note<3> &note);

public slots:
  void noteOn(unsigned int note, unsigned int velocity);
  void noteOff(unsigned int note);
  void allNoteOff();
signals:
  void noteActivated(unsigned int note, unsigned int velocity);
  void noteDisabled(unsigned int note);
  void allNoteDisabled();
  void dataGeneratedLeft(const std::vector<float> &data,
                         std::vector<float>::const_iterator from,
                         std::vector<float>::const_iterator to);
  void dataGeneratedRight(const std::vector<float> &data,
                          std::vector<float>::const_iterator from,
                          std::vector<float>::const_iterator to);
  void dataGeneratedMixed(const std::vector<float> &data,
                          std::vector<float>::const_iterator from,
                          std::vector<float>::const_iterator to);
  void dataGeneratedChannel(AudioChannel *channel);
  void lastPlayedNote(const Note<3> &note);
  void extremaLeftReceived(MinMax<float> extrema);
  void extremaRightReceived(MinMax<float> extrema);
  void extremaMixedReceived(MinMax<float> extrema);

private:
  ChangeableParameter<float> gain;

  std::unique_ptr<BasicSynthesizer> synthesizer;

  std::map<Qt::Key, std::pair<int, bool>> keys = {{Qt::Key_Q, {48, false}},
                                                  {Qt::Key_W, {49, false}},
                                                  {Qt::Key_E, {50, false}},
                                                  {Qt::Key_R, {51, false}},
                                                  {Qt::Key_T, {52, false}},
                                                  {Qt::Key_Y, {53, false}},
                                                  {Qt::Key_U, {54, false}}};
};

#endif // SYNTHESIZERCONTROL_H
