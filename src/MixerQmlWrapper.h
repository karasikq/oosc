//===-------------------- MixerQmlWrapper.h ----------------------*- C++-*-===//
//===------------ MixerQmlWrapper class definition ------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the MixerQmlWrapper class.
/// It's a @see MixerOutput Qt Quick wrapper.
///
//===----------------------------------------------------------------------===//

#ifndef MIXERQMLWRAPPER_H
#define MIXERQMLWRAPPER_H

#include "src/Generator/BasicSynthesizer.h"
#include "src/MixerOutput.h"
#include <QQuickItem>
#include <qquickitem.h>

class MixerQmlWrapper : public QQuickItem {
  Q_OBJECT
public:
  MixerQmlWrapper(QQuickItem *parent = nullptr);
  ~MixerQmlWrapper();

  Q_INVOKABLE void attachSynthesizer(BasicSynthesizer *synthesizer);
  Q_INVOKABLE void attachTimeReceiver(ITimeReceiver *receiver);

private:
  std::unique_ptr<MixerOutput> mixer;
};

#endif // !MIXERQMLWRAPPER_H
