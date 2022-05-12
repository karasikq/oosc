//===------------------- ApplicationConfig.h ---------------------*- C++-*-===//
//===----------- ApplicationConfig class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ApplicationConfig class
///
//===----------------------------------------------------------------------===//

#ifndef APPLICATIONCONFIG_H
#define APPLICATIONCONFIG_H

#include <QHash>
#include <QStandardPaths>
#include <QString>
#include <QVariant>

/// ApplicationConfig static class
class ApplicationConfig {
public:
  static QString getAppName();
  static QString getLocalDataPath();
  static QString getMidiDataPath();
  static QString getWavetablesDataPath();
  static QString getByKey(const QString &key);
  static void addToConfig(const QPair<QString, QString> &data);
  static void createConfigMap();

private:
  static QHash<QString, QString> configMap;
  ApplicationConfig();
};

#endif // APPLICATIONCONFIG_H
