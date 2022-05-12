#include "WaveTable.h"
#include "../AudioSettings.h"

WaveTable::WaveTable(unsigned int _size) {
  size = _size;
  chunkSize = 2048;
  position = 0;
  table.resize(size);
}

WaveTable::WaveTable(WaveShape::Shape _shape, unsigned int _size) {
  size = _size;
  table.resize(size);
  chunkSize = 2048;
  shape = _shape;
  position = 0;
  maxPosition = size / chunkSize - 1;
  SetTable(_shape, _size);
}

WaveTable::~WaveTable() {}

void WaveTable::SetTable(std::vector<float> &computedTable,
                         unsigned int chunkSize) {
  unsigned int computedSize = computedTable.size();
  this->chunkSize = chunkSize;
  size = computedSize;
  position = 0;
  maxPosition = size / chunkSize - 1;
  table.clear();
  table = computedTable;
}

void WaveTable::SetTable(WaveShape::Shape shape, unsigned int chunkSize) {
  this->chunkSize = chunkSize;
  if (size != chunkSize) {
    table.clear();
    table.resize(chunkSize);
  }
  this->size = chunkSize;
  WaveShape wave;
  for (unsigned int sample = 0; sample < size; sample++) {
    float time = (M_PI_2M * (float)sample) / (float)size;
    table[sample] = wave.Value(time, shape);
  }
}

float WaveTable::Value(float time) {
  unsigned int cellIndex = chunkSize * (fmod(time, M_PI_2M) / M_PI_2M);

  return table[position * chunkSize + cellIndex];
}

std::vector<float> *WaveTable::getData() { return &table; }

std::vector<float>::const_iterator WaveTable::getStartPosition() {
  return table.begin() + position * chunkSize;
}

std::vector<float>::const_iterator WaveTable::getEndPosition() {
  return table.begin() + (position + 1) * chunkSize;
}

unsigned int WaveTable::getPosition() const { return this->position; }

void WaveTable::setPosition(unsigned int position) {
  this->position = position;
}

unsigned int WaveTable::getMaxPosition() const { return this->maxPosition; }

float *WaveTable::getRaw() { return table.data(); }

unsigned int WaveTable::getChunkSize() const { return chunkSize; }

unsigned int WaveTable::tableSize() const { return size; }

float WaveTable::getSample(unsigned int sample) const { return table[sample]; }
