//===------------------------- ArrayDrawer.h ---------------------*- C++-*-===//
//===------------------- ArrayDrawer class definition ---------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ArrayDrawer class, which
/// is a base class for polyline painting.
///
//===----------------------------------------------------------------------===//

#ifndef ARRAYDRAWER_H
#define ARRAYDRAWER_H

#include <QQuickPaintedItem>
#include <vector>

#include "ADataReceiver.h"
#include "ArrayGradientDrawer.h"
#include "src/Utils/MinMax.h"

/// Forward declaration of slots for ArrayDrawer
class ArrayDrawerSlots;

/// Array Drawer class
/// Used for draw polyline
class ArrayDrawer : public QQuickPaintedItem, public ADataReceiver {
  Q_OBJECT
  Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor NOTIFY
                 lineColorChanged)
  Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE
                 setBackgroundColor NOTIFY backgroundColorChanged)
  Q_PROPERTY(QColor centerLineColor READ getCenterLineColor WRITE
                 setCenterLineColor NOTIFY centerLineColorChanged)
  Q_PROPERTY(bool drawGradient WRITE setDrawGradient)
  Q_PROPERTY(ADataReceiver *dataReceiver READ getDataReceiver CONSTANT)
public:
  /// Declare ArrayDrawerSlots as friend
  /// ArrayDrawerSlota should have access to protected members
  friend class ArrayDrawerSlots;
  /// Default constructor
  ArrayDrawer(QQuickItem *parent = 0);
  /// Default destructor
  ~ArrayDrawer();
  /// Prepare data and paint array
  virtual void paint(QPainter *painter);

  virtual void setLineColor(QColor lineColor);
  Q_INVOKABLE virtual void setLineGradient(const QVariantList &lineGradient);
  virtual void setBackgroundColor(QColor backgroundColor);
  Q_INVOKABLE virtual void
  setBackgroundGradient(const QVariantList &backgroundGradient);
  virtual void setCenterLineColor(QColor lineColor);
  void setDrawGradient(bool state);

  QColor getLineColor();
  QColor getBackgroundColor();
  QColor getCenterLineColor();
  ArrayGradientDrawer::GradientDirection gradientDirection;

signals:
  void lineColorChanged();
  void lineGradientChanged();
  void backgroundColorChanged();
  void backgroundGradientChanged();
  void centerLineColorChanged();
  void rawDataChanged();

protected:
  /// Contains range in which the data should be
  MinMax<float> valueRange;

  /// Pointer to the data which should be painted
  const std::vector<float> *data = nullptr;
  /// Iterator which from data should be start to read
  std::vector<float>::const_iterator dataStart;
  /// Iterator until which data should be read
  std::vector<float>::const_iterator dataEnd;

  /// Lenght of data sequence
  uint32_t dataSize;
  /// Result polyline
  std::vector<QPointF> polyline;

  /// Rectange field
  QRectF rect;
  /// Padding for left-right(x) and top-bottom(y)
  QPointF padding;
  /// Rectange field in which the array should be drawn
  QRectF drawableRect;
  /// Width of a one sample
  float partWidth;
  /// If true background drawn as a gradiend, i.e. shadow
  bool drawGradient;

  QColor lineColor;
  QLinearGradient lineGradient;
  QColor backgroundColor;
  ArrayGradientDrawer gradientDrawer;
  QColor centerLineColor;
  QPen linePen;

  /// Sets data to draw
  /// @param data is a adress of a data
  /// @param from is a iterator which from data should be start to read
  /// @param to is a iterator until which data should be read
  void setRawData(const std::vector<float> &data,
                  std::vector<float>::const_iterator from,
                  std::vector<float>::const_iterator to);
  /// Initialize drawable rect and set render hints 
  virtual void painterInitialization(QPainter *painter);
  /// Calculates size of one sample
  void calculateDrawData();
  /// Draws a line in the middle of the data range 
  virtual void drawCenterLine(QPainter *painter);
  /// Fills polyline data from raw data
  virtual void updatePolylineData();
  /// Paints polyline
  virtual void drawPolyline(QPainter *painter);
  /// Paints gradient
  virtual void drawArrayGradient(QPainter *painter);
};

/// Array Drawer Slots class
/// Contains slot for receive data
class ArrayDrawerSlots : public ADataReceiverSlots {
  Q_OBJECT
public:
  ArrayDrawerSlots(QObject *object) : ADataReceiverSlots(object){};
public slots:
  /// Receive data
  /// @param data is a adress of a data
  /// @param from is a iterator which from data should be start to read
  /// @param to is a iterator until which data should be read
  void dataUpdate(const std::vector<float> &data,
                  std::vector<float>::const_iterator from,
                  std::vector<float>::const_iterator to) override;
};

#endif // ARRAYDRAWER_H
