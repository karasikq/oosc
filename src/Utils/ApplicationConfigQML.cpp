#include "ApplicationConfigQML.h"

ApplicationConfigQML *ApplicationConfigQML::instance = nullptr;
std::mutex ApplicationConfigQML::initMutex;

ApplicationConfigQML::ApplicationConfigQML() {}

ApplicationConfigQML *ApplicationConfigQML::Instance() {
  std::lock_guard<std::mutex> lock(initMutex);
  if (instance == nullptr) {
    instance = new ApplicationConfigQML();
  }
  return instance;
}

QObject *ApplicationConfigQML::provider(QQmlEngine *engine,
                                        QJSEngine *scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)
  return Instance();
}

QString ApplicationConfigQML::getConfigParametr(const QString &key) {
  return ApplicationConfig::getByKey(key);
}
