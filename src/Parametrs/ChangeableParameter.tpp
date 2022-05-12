#include "ChangeableParameter.h"

template <typename T>
ChangeableParameter<T>::ChangeableParameter() : IChangeableParameter(0) {}

template <typename T>
template <typename Y>
void ChangeableParameter<T>::setParameter(Y *object,
                                          void (Y::*setter)(T),
                                          const MinMax<T> &range) {
  this->setter = std::bind(setter, object, std::placeholders::_1);
  this->valueRange = range;
  this->setter(this->valueRange.getCurrent());
  emit parameterChanged();
}

template <typename T>
void ChangeableParameter<T>::setValue(QVariant value) {
  T newValue = value.value<T>();
  valueRange.setCurrent(newValue);
  setter(newValue);
  emit valueChanged();
}

template <typename T>
QVariant ChangeableParameter<T>::getMin() {
  return QVariant(valueRange.min);
}

template <typename T>
QVariant ChangeableParameter<T>::getMax() {
  return QVariant(valueRange.max);
}

template <typename T>
QVariant ChangeableParameter<T>::getCurrent() {
  return QVariant(valueRange.getCurrent());
}

