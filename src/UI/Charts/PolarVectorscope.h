//===--------------------- PolarVectorscope.h ---------------------*- C++-*-===//
//===--------------- PolarVectorscope class definition ---------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the PolarVectorscope class, which
/// is used to draw Vectorscope in polar coordinates.
///
//===----------------------------------------------------------------------===//

#ifndef POLARVECTORSCOPE_H
#define POLARVECTORSCOPE_H

#include "src/UI/Charts/ADataReceiver.h"
#include "src/Utils/AudioChannel.h"
#include "src/Utils/MinMax.h"
#include <QPainter>
#include <QQuickPaintedItem>

/// Forward declaration of PolarVectorscope slots
class VectorscopeDrawerSlots;

/// Polar Vectorscope class
class PolarVectorscope : public QQuickPaintedItem, public ADataReceiver {
  Q_OBJECT
  Q_PROPERTY(ADataReceiver *dataReceiver READ getDataReceiver CONSTANT)
public:
  friend class VectroscopeDrawerSlots;
  PolarVectorscope();
  ~PolarVectorscope() override;
  /// Paints vectorscope
  virtual void paint(QPainter *painter) override;

public slots:
  void drawVectorscope(AudioChannel *channel);

private:
  /// Contains polar points in linear space 
  std::vector<QPointF> polyline;
  /// Audio channel from which the data is read
  AudioChannel *channel;
};

class VectroscopeDrawerSlots : public ADataReceiverSlots {
  Q_OBJECT
public:
  VectroscopeDrawerSlots(QObject *object) : ADataReceiverSlots(object){};
public slots:
  void dataUpdateChannel(AudioChannel *channel) override;
};

#endif // POLARVECTORSCOPE_H
