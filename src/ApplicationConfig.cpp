#include "ApplicationConfig.h"

QHash<QString, QString> ApplicationConfig::configMap =
    QHash<QString, QString>();

ApplicationConfig::ApplicationConfig() {}

QString ApplicationConfig::getAppName() { return "oosc"; }

QString ApplicationConfig::getLocalDataPath() {
  return QStandardPaths::writableLocation(
             QStandardPaths::StandardLocation::GenericDataLocation) +
         "/" + getAppName();
}

QString ApplicationConfig::getMidiDataPath() {
  return getLocalDataPath() + "/Midi";
}

QString ApplicationConfig::getWavetablesDataPath() {
  return getLocalDataPath() + "/Wavetables";
}

QString ApplicationConfig::getByKey(const QString &key) {
  return configMap.value(key, "");
}

void ApplicationConfig::addToConfig(const QPair<QString, QString> &data) {
  configMap.insert(data.first, data.second);
}

void ApplicationConfig::createConfigMap() {
  configMap.insert("AppName", getAppName());
  configMap.insert("LocalDataPath", getLocalDataPath());
  configMap.insert("MidiDataPath", getMidiDataPath());
  configMap.insert("WavetablesDataPath", getWavetablesDataPath());
}
