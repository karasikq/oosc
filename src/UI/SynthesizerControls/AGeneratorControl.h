//===-------------------- AGeneratorControl.h --------------------*- C++-*-===//
//===------------ AGeneratorControl class definition ----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the AGeneratorControl class, which is
/// the QtQuick wrapper for AGenerator and the base class for all
/// GeneratorControl's
///
//===----------------------------------------------------------------------===//

#ifndef AGENERATORCONTROL_H
#define AGENERATORCONTROL_H

#include <QObject>
#include <QQuickItem>

#include "src/Generator/AGenerator.h"
#include "src/UI/SynthesizerControls/ADSRController.h"

/// AGeneratorControl class
/// The QtQuick wrapper for AGenerator
class AGeneratorControl : public QQuickItem {
  Q_OBJECT
  Q_PROPERTY(unsigned int generatorID READ getGeneratorID WRITE setGeneratorID
                 NOTIFY generatorIDChanged)
  Q_PROPERTY(bool bypass READ getBypass WRITE setBypass NOTIFY bypassChanged)
  Q_PROPERTY(ADSRController *adsrController READ getAdsr WRITE setAdsr NOTIFY
                 adsrChanged)
public:
  AGeneratorControl(QQuickItem *parent = nullptr);
  virtual ~AGeneratorControl();

  void setGeneratorID(unsigned int generatorID);
  void setAdsr(ADSRController *controller);
  void setBypass(bool value);

  unsigned int getGeneratorID() const;
  ADSRController *getAdsr() const;
  bool getBypass() const;
  virtual void setGenerator(AGenerator *generator);
signals:
  void generatorIDChanged(AGeneratorControl *generatorControl);
  void adsrChanged(ADSRController *controller);
  void bypassChanged(bool bypass);

protected:
  AGenerator *generator = nullptr;
  unsigned int generatorID;
  ADSRController *adsr;
};

#endif // AGENERATORCONTROL_H
