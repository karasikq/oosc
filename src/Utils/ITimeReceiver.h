//===----------------------- ITimeReceiver.h ---------------------*- C++-*-===//
//===--------------- ITimeReceiver class definition -----------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the ITimeReceiver class, which
/// is the used for receive time from @see MixerOutput.
///
//===----------------------------------------------------------------------===//

#ifndef ITIMERECEIVER_H
#define ITIMERECEIVER_H

class ITimeReceiver {
public:
  ITimeReceiver() = default;
  /// Called when MixerOutput starts processing new block
  virtual void UpdateTime(float time) = 0;
  /// Returns this casted to ITimeReceiver *
  ITimeReceiver *getTimeReceiver();
};

#endif // ITIMERECEIVER_H
