#include "AValueSender.h"

void AValueSender::processValue(float value) {
  for (auto i = connectedParameters.begin(); i != connectedParameters.end();) {
    if (*i == nullptr) {
      i = connectedParameters.erase(i);
      continue;
    }
    if ((*i)->isAutomated()) {
      (*i)->setValue(value);
    } else {
      i = connectedParameters.erase(i);
      continue;
    }
    i++;
  }
}

void AValueSender::addAutomatedParameter(IChangeableParameter *parameter) {
  connectedParameters.push_back(parameter);
  parameter->setAutomated(true);
}
