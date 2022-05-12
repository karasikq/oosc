//===------------------ SubGeneratorControl.h --------------------*- C++-*-===//
//===------------ SubGeneratorControl class definition --------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the SubGeneratorControl class, which
/// is the Qt Quick wrapper for SubGenerator.
///
//===----------------------------------------------------------------------===//

#ifndef SUBGENERATORCONTROL_H
#define SUBGENERATORCONTROL_H

#include <QObject>
#include <QQuickItem>

#include "src/Generator/Generator.h"
#include "src/Parametrs/ChangeableParameter.h"
#include "src/Utils/AudioFile.h"
#include "src/UI/Charts/ArrayDrawer.h"
#include "src/UI/SynthesizerControls/AGeneratorControl.h"

/// SubGeneratorControl class
/// The Qt Quick wrapper for SubGenerator
class SubGeneratorControl : public AGeneratorControl {
  Q_OBJECT
  Q_PROPERTY(IChangeableParameter *pan READ getPan CONSTANT)
  Q_PROPERTY(IChangeableParameter *gain READ getGain CONSTANT)
  Q_PROPERTY(IChangeableParameter *octaveOffset READ getOctaveOffset CONSTANT)
  Q_PROPERTY(IChangeableParameter *shape READ getShape CONSTANT)
  Q_PROPERTY(ArrayDrawer *wavetableDrawer READ getWavetableDrawer WRITE
                 setWavetableDrawer NOTIFY wavetableDrawerChanged)
public:
  SubGeneratorControl(QQuickItem *parent = nullptr);
  ~SubGeneratorControl();

  void setWavetable(std::vector<float> &computedTable, unsigned int chunkSize);
  void setWavetable(WaveShape::Shape shape, unsigned int chunkSize);
  void setGenerator(AGenerator *generator) override;
  void setWavetableDrawer(ArrayDrawer *wavetable);

  ArrayDrawer *getWavetableDrawer();
  IChangeableParameter *getPan() { return &pan; }
  IChangeableParameter *getGain() { return &gain; }
  IChangeableParameter *getOctaveOffset() { return &octaveOffset; }
  IChangeableParameter *getShape() { return &shape; }

  // Q_INVOKABLE void loadWavetableFromFile(const QVariant &fileName);
  // Q_INVOKABLE void loadWavetableFromFileUrl(const QVariant &fileName);

signals:
  void wavetableChanged(const std::vector<float> &data,
                        std::vector<float>::const_iterator from,
                        std::vector<float>::const_iterator to);
  void wavetableDrawerChanged();
public slots:
  void updateWavetableDrawer();

private:
  ArrayDrawer *wavetableDrawer = nullptr;
  ChangeableParameter<float> pan;
  ChangeableParameter<float> gain;
  ChangeableParameter<int> octaveOffset;
  ChangeableParameter<int> shape;

  void setShapeValue(int shape);
};

#endif // SUBGENERATORCONTROL_H
