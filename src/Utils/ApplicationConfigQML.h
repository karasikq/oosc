//===-------------------- ApplicationConfigQML.h -----------------*- C++-*-===//
//===----------- ApplicationConfigQML class definition --------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ApplicationConfigQML class, which
/// is the Singleton Qt Quick wrapper for @see ApplicationConfig.
///
//===----------------------------------------------------------------------===//

#ifndef APPLICATIONCONFIGQML_H
#define APPLICATIONCONFIGQML_H

#include "src/ApplicationConfig.h"
#include <QQuickItem>
#include <mutex>

class ApplicationConfigQML : public QQuickItem {
  Q_OBJECT
public:
  static ApplicationConfigQML *Instance();
  ~ApplicationConfigQML(){};
  Q_INVOKABLE QString getConfigParametr(const QString &key);
  static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine);

protected:
  ApplicationConfigQML();
  static ApplicationConfigQML *instance;

private:
  static std::mutex initMutex;
};

#endif // APPLICATIONCONFIGQML_H
