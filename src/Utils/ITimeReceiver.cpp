#include "ITimeReceiver.h"

ITimeReceiver* ITimeReceiver::getTimeReceiver() {
  return static_cast<ITimeReceiver*>(this);
}
