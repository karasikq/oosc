#include "ChangeableParameter.h"

IChangeableParameter *IChangeableParameter::getLink() {
  return static_cast<IChangeableParameter *>(this);
}
