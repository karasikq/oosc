#include "ADataReceiver.h"

ADataReceiverSlots::ADataReceiverSlots(QObject *object) {
  this->object = object;
}

ADataReceiver::ADataReceiver() {}

void ADataReceiverSlots::dataUpdate(const std::vector<float> &data,
                                    std::vector<float>::const_iterator from,
                                    std::vector<float>::const_iterator to) {
  Q_UNUSED(data);
  Q_UNUSED(from);
  Q_UNUSED(to);
}

void ADataReceiverSlots::dataUpdateChannel(AudioChannel *channel) {
  Q_UNUSED(channel);
}

void ADataReceiverSlots::lastNoteReceived(const Note<3> &note) {
  Q_UNUSED(note);
}

ADataReceiver *ADataReceiver::getDataReceiver() {
  return static_cast<ADataReceiver *>(this);
}
