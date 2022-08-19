//===------------------------ ADataReceiver.h --------------------*- C++-*-===//
//===------------------ ADataReceiver class definition --------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ADataReceiver class, which
/// contains ADataReceiverSlots class.
/// ADataReceiverSlots class contains the declaration of basic slots that used
/// for receiving audio data.
///
//===----------------------------------------------------------------------===//

#ifndef ADRAWER_H
#define ADRAWER_H

#include "src/Generator/Note.h"
#include "src/Utils/AudioChannel.h"
#include <QObject>
#include <memory>

/// ADataReceiverSlots class
/// Contains basic slots for receiving audio data
class ADataReceiverSlots : public QObject {
  Q_OBJECT
public:
  /// Default constructor
  ADataReceiverSlots(QObject *object);
public slots:
  /// Receive data
  /// @param data is a adress of a data
  /// @param from is a iterator which from data should be start to read
  /// @param to is a iterator until which data should be read
  virtual void dataUpdate(const std::vector<float> &data,
                          std::vector<float>::const_iterator from,
                          std::vector<float>::const_iterator to);
  /// Receive audio channel data
  virtual void dataUpdateChannel(AudioChannel *channel);
  /// Receive last played note
  virtual void lastNoteReceived(const Note<3> &note);

protected:
  /// Pointer to object that inherited from @see ADataReceiver
  QObject *object = nullptr;
};

/// ADataReceiver class
/// Could be used in cases when derived class should receive audio-data
class ADataReceiver {
public:
  /// Default constructor
  ADataReceiver();
  /// Pointer to ADataReceiverSlots
  std::unique_ptr<ADataReceiverSlots> receiver;
  /// Pointer to this with cast to ADataReceiver *
  ADataReceiver *getDataReceiver();
};

#endif // !ADRAWE_H
