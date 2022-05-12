//===--------------------- GeneratorControl.h --------------------*- C++-*-===//
//===------------- GeneratorControl class definition ----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the GeneratorControl class, which is
/// the QtQuick wrapper for Generator.
///
//===----------------------------------------------------------------------===//

#ifndef GENERATORCONTROL_H
#define GENERATORCONTROL_H

#include <QQuickItem>

#include "src/Generator/Generator.h"
#include "src/Parametrs/ChangeableParameter.h"
#include "src/Utils/AudioFile.h"
#include "src/UI/Charts/ArrayDrawer.h"
#include "src/UI/SynthesizerControls/AGeneratorControl.h"

/// GeneratorControl class
/// The QtQuick wrapper for Generator.
class GeneratorControl : public AGeneratorControl {
  Q_OBJECT
  Q_PROPERTY(IChangeableParameter *pan READ getPan CONSTANT)
  Q_PROPERTY(IChangeableParameter *gain READ getGain CONSTANT)
  Q_PROPERTY(IChangeableParameter *tablePosition READ getTablePosition CONSTANT)
  Q_PROPERTY(IChangeableParameter *phase READ getPhase CONSTANT)
  Q_PROPERTY(IChangeableParameter *cents READ getCents CONSTANT)
  Q_PROPERTY(IChangeableParameter *octaveOffset READ getOctaveOffset CONSTANT)
  Q_PROPERTY(
      IChangeableParameter *semitoneOffset READ getSemitoneOffset CONSTANT)
  Q_PROPERTY(IChangeableParameter *unisonVoices READ getUnisonVoices CONSTANT)
  Q_PROPERTY(IChangeableParameter *unisonLevel READ getUnisonLevel CONSTANT)
  Q_PROPERTY(IChangeableParameter *unisonFine READ getUnisonFine CONSTANT)
  Q_PROPERTY(ArrayDrawer *wavetableDrawer READ getWavetableDrawer WRITE
                 setWavetableDrawer NOTIFY wavetableDrawerChanged)
public:
  GeneratorControl(QQuickItem *parent = nullptr);
  ~GeneratorControl();

  void setWavetable(std::vector<float> &computedTable, unsigned int chunkSize);
  void setWavetable(WaveShape::Shape shape, unsigned int chunkSize);
  void setWavetableDrawer(ArrayDrawer *wavetable);
  void setGenerator(AGenerator *generator) override;

  ArrayDrawer *getWavetableDrawer();
  IChangeableParameter *getPan() { return &pan; }
  IChangeableParameter *getGain() { return &gain; }
  IChangeableParameter *getOctaveOffset() { return &octaveOffset; }
  IChangeableParameter *getSemitoneOffset() { return &semitoneOffset; }
  IChangeableParameter *getPhase() { return &phase; }
  IChangeableParameter *getCents() { return &cents; }
  IChangeableParameter *getUnisonVoices() { return &unisonVoices; }
  IChangeableParameter *getUnisonPan() { return &unisonPan; }
  IChangeableParameter *getUnisonLevel() { return &unisonLevel; }
  IChangeableParameter *getUnisonFine() { return &unisonFine; }
  IChangeableParameter *getTablePosition() { return &tablePosition; }

  /// Load wavetable from system file
  Q_INVOKABLE void loadWavetableFromFile(const QVariant &fileName);
  /// Load wavetable from Qt url
  Q_INVOKABLE void loadWavetableFromFileUrl(const QVariant &fileName);

signals:
  void wavetableChanged(const std::vector<float> &data,
                        std::vector<float>::const_iterator from,
                        std::vector<float>::const_iterator to);
  void wavetableDrawerChanged();
public slots:
  void wavetablePositionChanged();
  void updateWavetableDrawer();

private:
  ArrayDrawer *wavetableDrawer = nullptr;
  ChangeableParameter<float> pan;
  ChangeableParameter<float> gain;
  ChangeableParameter<int> octaveOffset;
  ChangeableParameter<int> semitoneOffset;
  ChangeableParameter<float> phase;
  ChangeableParameter<int> cents;
  ChangeableParameter<unsigned int> unisonVoices;
  ChangeableParameter<float> unisonPan;
  ChangeableParameter<float> unisonLevel;
  ChangeableParameter<float> unisonFine;
  ChangeableParameter<unsigned int> tablePosition;
};

#endif // GENERATORCONTROL_H
