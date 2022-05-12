//===--------------------------- FileIO.h ------------------------*- C++-*-===//
//===------------------- FileIO class definition --------------------------===//
//
// Part of OOSC project.
// Author: Stepaniuk Roman(romastepanuik@gmail.com)
// See LICENSE.txt for license information.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the declaration of the FileIO class, which is the
/// Qt Quick wrapper for operate files from QML.
///
//===----------------------------------------------------------------------===//

#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>

class FileIO : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
public:
  explicit FileIO(QObject *parent = 0);

  /// Reads data from file
  Q_INVOKABLE QString read();
  /// Writes data to file
  Q_INVOKABLE bool write(const QString &data);

  /// Returns path
  QString source() { return mSource; };

public slots:
  void setSource(const QString &source) { mSource = source; };

signals:
  void sourceChanged(const QString &source);
  void error(const QString &msg);

private:
  /// Path
  QString mSource;
};

#endif // FILEIO_H
