#include "PhaserUIWrapper.h"
#include "src/Effects/Phaser.h"

PhaserUIWrapper::PhaserUIWrapper() {
  effect = std::make_unique<Phaser>(AudioSettings::SAMPLE_RATE);
  auto phaser = static_cast<Phaser *>(effect.get());
  lfoShape.setParameter(
      this, &PhaserUIWrapper::setLfoShape, MinMax<int>(0, 3, 0));
  phaseWidth.setParameter(
      phaser, &Phaser::setWidth, MinMax<float>(10.f, 4000.f, 1000.f));
  depth.setParameter(phaser, &Phaser::setDepth, MinMax<float>(0.f, 1.f, 1.f));
  numberOfFilters.setParameter(
      this, &PhaserUIWrapper::setNumberOfFilters, MinMax<int>(1, 11, 1));
  lfoFrequency.setParameter(
      phaser, &Phaser::setLfoFrequency, MinMax<float>(0.f, 3.f, 0.01f));
  filterFrequency.setParameter(
      phaser, &Phaser::setFilterFrequency, MinMax<float>(10.f, 2000.f, 100.f));
  feedback.setParameter(
      phaser, &Phaser::setFeedback, MinMax<float>(0.f, 0.9f, 0.5f));
}

PhaserUIWrapper::~PhaserUIWrapper() {}

void PhaserUIWrapper::setNumberOfFilters(int value) {
  if (value % 2 != 0) {
    value++;
  }
  static_cast<Phaser *>(effect.get())->setNumberOfFilters(value);
}

void PhaserUIWrapper::setLfoShape(int value) {
  static_cast<Phaser *>(effect.get())
      ->setLfoShape(static_cast<WaveShape::Shape>(value));
}
