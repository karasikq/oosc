//===------------------------ ADSRDrawer.h -----------------------*- C++-*-===//
//===----------------- ADSRDrawer class definition ------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ADSRDrawer class, which
/// is used to draw ADSR Envelope.
///
//===----------------------------------------------------------------------===//

#ifndef ADSRDRAWER_H
#define ADSRDRAWER_H

#include "ArrayDrawer.h"
#include "src/ADSR/ADSREnvelope.h"

/// ADSR Envelope drawer class
class ADSRDrawer : public ArrayDrawer {
  Q_PROPERTY(int samplesCount READ getSamplesCount WRITE setSamplesCount NOTIFY
                 samplesCountChanged)
public:
  /// Default constructor
  ADSRDrawer(QQuickItem *parent = 0);
  /// Default destrcutor
  virtual ~ADSRDrawer();
  /// Draw envelope
  void paint(QPainter *painter) override;

  /// Set background color, i.e. shadow color
  virtual void setBackgroundColor(QColor backgroundColor) override;
  /// Set envelope to draw and update
  void setEnvelope(ADSREnvelope *env);
  /// Set drawing samples count
  void setSamplesCount(int value);

  /// Returns drawing samples count
  int getSamplesCount();
signals:
  /// Called when samples count changed
  void samplesCountChanged();
public slots:
  void envelopeChanges();

private:
  /// Drawing samples
  int samplesCount;
  /// Pointer to envelope which should be painted
  ADSREnvelope *envelope;
  /// Buffer that contains enveloped data
  std::vector<float> envelopeData;

  void allocateRawData();
};

#endif // ADSRDRAWER_H
