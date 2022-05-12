//===------------------- ChangeableParameter.h -------------------*- C++-*-===//
//===------------ ChangeableParameter class definition --------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ChangeableParameter class, which
/// use to define user-contolled properties.
///
//===----------------------------------------------------------------------===//

#ifndef CHANGEABLEPARAMETER_H
#define CHANGEABLEPARAMETER_H

#include "src/Utils/MinMax.h"
#include <QObject>
#include <QVariant>
#include <functional>

/// IChangeableParameter class
class IChangeableParameter : public QObject {
  Q_OBJECT;
public:
  /// Default constructor
  IChangeableParameter(QObject *parent = 0) : QObject(parent) {}
  /// Pure-virtual function for set current value
  virtual void setValue(QVariant value) = 0;
  /// Returns min value
  virtual QVariant getMin() = 0;
  /// Returns max value
  virtual QVariant getMax() = 0;
  /// Returns current value
  virtual QVariant getCurrent() = 0;
  /// Returns IChangeableParameter* with cast
  virtual IChangeableParameter *getLink();

  /// Returns true if parameter is connected
  inline bool isAutomated() { return automated; }
  /// Set connection state
  inline void setAutomated(bool state) { automated = state; }
signals:
  void parameterChanged();
  /// Called when current value is changed
  void valueChanged();

protected:
  /// Automated state
  bool automated = false;
};

/// ChangeableParameter class
/// Used for control only one property from setter function
template <typename T>
class ChangeableParameter : public IChangeableParameter {
public:
  /// Default constructor
  ChangeableParameter();

  /// Make property changeable, i.e. user-controlled
  /// @param object is a pointer to object, that have setter function
  /// @param setter is a setter function
  /// @param range is a value range
  template <typename Y>
  void setParameter(Y *object, void (Y::*setter)(T), const MinMax<T> &range);
  /// Set currect value
  void setValue(QVariant value) override;
  QVariant getMin() override;
  QVariant getMax() override;
  QVariant getCurrent() override;

protected:
  /// Value range
  MinMax<T> valueRange;
  /// Stores controlled property setter function
  std::function<void(T)> setter;
};

#include "ChangeableParameter.tpp"

#endif // CHANGEABLEPARAMETER_H
