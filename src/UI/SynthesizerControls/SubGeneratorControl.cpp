#include "SubGeneratorControl.h"
#include "src/Generator/SubGenerator.h"

SubGeneratorControl::SubGeneratorControl(QQuickItem *parent)
    : AGeneratorControl(parent) {
  generatorID = 0;
  connect(this,
          &SubGeneratorControl::wavetableDrawerChanged,
          this,
          &SubGeneratorControl::updateWavetableDrawer);
}

SubGeneratorControl::~SubGeneratorControl() = default;

void SubGeneratorControl::setGenerator(AGenerator *generator) {
  this->generator = generator;
  this->generator->setEnvelope(adsr->getEnvelope());
  auto sGenerator = dynamic_cast<SubGenerator *>(generator);
  pan.setParameter(sGenerator, &SubGenerator::setPan, {0.0f, 1.0f, 0.5f});
  gain.setParameter(
      sGenerator, &SubGenerator::setLevel, {0.0f, 1.41254f, 0.1f});
  octaveOffset.setParameter(
      sGenerator, &SubGenerator::setOctaveOffset, {-3, 3, 0});
  shape.setParameter(this, &SubGeneratorControl::setShapeValue, {0, 3, 0});

  emit wavetableChanged(*this->generator->getWaveTable()->getData(),
                        this->generator->getWaveTable()->getStartPosition(),
                        this->generator->getWaveTable()->getEndPosition());
}

void SubGeneratorControl::setWavetable(std::vector<float> &computedTable,
                                       unsigned int chunkSize) {
  this->generator->getWaveTable()->SetTable(computedTable, chunkSize);
  emit wavetableChanged(*this->generator->getWaveTable()->getData(),
                        this->generator->getWaveTable()->getStartPosition(),
                        this->generator->getWaveTable()->getEndPosition());
}

void SubGeneratorControl::setWavetable(WaveShape::Shape shape,
                                       unsigned int chunkSize) {
  this->generator->getWaveTable()->SetTable(shape, chunkSize);
}

void SubGeneratorControl::setWavetableDrawer(ArrayDrawer *wavetable) {
  wavetableDrawer = wavetable;
  emit wavetableDrawerChanged();
}

ArrayDrawer *SubGeneratorControl::getWavetableDrawer() {
  return wavetableDrawer;
}

void SubGeneratorControl::updateWavetableDrawer() {
  connect(this,
          &SubGeneratorControl::wavetableChanged,
          wavetableDrawer->receiver.get(),
          &ADataReceiverSlots::dataUpdate);
}

void SubGeneratorControl::setShapeValue(int value) {
  auto sg = dynamic_cast<SubGenerator *>(generator);
  if (sg->getShape() == value) {
    return;
  }

  sg->setShape(value);
  emit wavetableChanged(*this->generator->getWaveTable()->getData(),
                        this->generator->getWaveTable()->getStartPosition(),
                        this->generator->getWaveTable()->getEndPosition());
}

/* void SubGeneratorControl::loadWavetableFromFile(const QVariant &fileName) {
    AudioFile<float> audioFile;
    audioFile.load(fileName.toString().toStdString());
    setWavetable(audioFile.samples[0], 2048);
}

void SubGeneratorControl::loadWavetableFromFileUrl(const QVariant &fileName) {
        QString file = fileName.toString();
        QVariant fileVariant = file.mid(7, file.length() - 7);
        loadWavetableFromFile(fileVariant);
} */
