#include "src/UI/Controls/KeyboardControl.h"
#include "src/UI/SynthesizerControls/SynthesizerControl.h"
#include <QPainterPath>
#include <qbrush.h>
#include <qpainter.h>
#include <qpainterpath.h>

KeyboardControl::KeyboardControl(QQuickItem *parent)
    : QQuickPaintedItem(parent) {
  minNote = 37;
  maxNote = 96;
  for (uint32_t i = minNote; i < maxNote; i++) {
    keyboardNotes[i] = false;
  }
}

KeyboardControl::~KeyboardControl() {}

void KeyboardControl::paint(QPainter *painter) {
  painter->setRenderHint(QPainter::Antialiasing);
  QRectF boundingRect = this->boundingRect();
  unsigned int nkeys = maxNote - minNote + 1;
  unsigned int noctaves = (nkeys + 11) / 12;

  unsigned int minNote12 = minNote % 12;
  double startOffset = 0;
  switch (minNote12) {
  case 0:
    startOffset = 0;
    break;
  case 1:
    startOffset = 0;
    break;
  case 2:
    startOffset = 1;
    break;
  case 3:
    startOffset = 1;
    break;
  case 4:
    startOffset = 2;
    break;
  case 5:
    startOffset = 3;
    break;
  case 6:
    startOffset = 3;
    break;
  case 7:
    startOffset = 4;
    break;
  case 8:
    startOffset = 4;
    break;
  case 9:
    startOffset = 5;
    break;
  case 10:
    startOffset = 5;
    break;
  case 11:
    startOffset = 6;
    break;
  }

  float notePadding = 5.f;
  float noteWidth =
      boundingRect.width() / (noctaves * 7 + startOffset) - notePadding;

  QBrush brush = {"#de5d68"};
  int globalNoteOffset = startOffset;
  for (unsigned int note = minNote; note <= maxNote; note++) {
    unsigned int note12 = (note + 60) % 12;
    QRectF rect;
    bool isKey = false;
    switch (note12) {
    case 0:
      isKey = true;
      break;
    case 2:
      isKey = true;
      break;
    case 4:
      isKey = true;
      break;
    case 5:
      isKey = true;
      break;
    case 7:
      isKey = true;
      break;
    case 9:
      isKey = true;
      break;
    case 11:
      isKey = true;
      break;
    }
    QPainterPath path;
    brush.setColor(keyColor);
    if (isKey) {
      if (keyboardNotes[note]) {
        brush.setColor(activeKeyColor);
      }
      rect = QRectF(
          globalNoteOffset * (noteWidth + notePadding), 0, noteWidth, height());
      path.addRoundedRect(rect, noteWidth / 4, noteWidth / 4);
      globalNoteOffset++;
    }
    painter->fillPath(path, brush);
  }
  globalNoteOffset = startOffset;
  for (unsigned int note = minNote; note <= maxNote; note++) {
    unsigned int note12 = (note + 60) % 12;
    QRectF rect;
    float currentOffset = 0.0f;
    bool isSharp = false;
    switch (note12) {
    case 1:
      isSharp = true;
      currentOffset = noteWidth / 2 + notePadding;
      break;
    case 3:
      isSharp = true;
      currentOffset = noteWidth;
      break;
    case 6:
      isSharp = true;
      currentOffset = noteWidth / 2 + notePadding;
      break;
    case 8:
      isSharp = true;
      currentOffset = 0.75f * noteWidth + notePadding / 2;
      break;
    case 10:
      isSharp = true;
      currentOffset = noteWidth;
      break;
    }
    QPainterPath path;
    brush.setColor(sharpColor);
    if (isSharp) {
      if (keyboardNotes[note]) {
        brush.setColor(activeSharpColor);
      }
      rect =
          QRectF(globalNoteOffset * (noteWidth + notePadding) + currentOffset,
                 noteWidth / 4,
                 noteWidth / 2,
                 height() * 0.6);
      path.addRoundedRect(rect, noteWidth / 4, noteWidth / 4);
    } else {
      globalNoteOffset++;
    }
    painter->fillPath(path, brush);
  }
}

void KeyboardControl::noteOn(unsigned int note, unsigned int velocity) {
  Q_UNUSED(velocity);
  keyboardNotes[note] = true;
  this->update();
}

void KeyboardControl::noteOff(unsigned int note) {
  keyboardNotes[note] = false;
  this->update();
}

void KeyboardControl::allNoteOff() {
  for (auto &note : keyboardNotes) {
    note.second = false;
  }
  this->update();
}

void KeyboardControl::attachSynthesizer(SynthesizerControl *synthesizer) {
  connect(synthesizer,
          &SynthesizerControl::noteActivated,
          this,
          &KeyboardControl::noteOn);
  connect(synthesizer,
          &SynthesizerControl::noteDisabled,
          this,
          &KeyboardControl::noteOff);
  connect(synthesizer,
          &SynthesizerControl::allNoteDisabled,
          this,
          &KeyboardControl::allNoteOff);
}

void KeyboardControl::setKeyColor(QColor color) {
  keyColor = color;
  emit keyColorChanged(color);
}

void KeyboardControl::setSharpColor(QColor color) {
  sharpColor = color;
  emit sharpColorChanged(color);
}

QColor KeyboardControl::getKeyColor() { return keyColor; }

QColor KeyboardControl::getSharpColor() { return sharpColor; }

void KeyboardControl::setActiveKeyColor(QColor color) {
  activeKeyColor = color;
  emit activeKeyColorChanged(color);
}

void KeyboardControl::setActiveSharpColor(QColor color) {
  activeSharpColor = color;
  emit sharpColorChanged(color);
}

QColor KeyboardControl::getActiveKeyColor() { return activeKeyColor; }

QColor KeyboardControl::getActiveSharpColor() { return activeSharpColor; }
