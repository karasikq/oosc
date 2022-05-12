#include "GeneratorControl.h"
#include "src/Generator/Generator.h"
#include "src/UI/Charts/ArrayDrawer.h"

GeneratorControl::GeneratorControl(QQuickItem *parent)
    : AGeneratorControl(parent) {
  generatorID = 0;
  connect(this,
          &GeneratorControl::wavetableDrawerChanged,
          this,
          &GeneratorControl::updateWavetableDrawer);
  connect(&tablePosition,
          &IChangeableParameter::valueChanged,
          this,
          &GeneratorControl::wavetablePositionChanged);
}

GeneratorControl::~GeneratorControl() = default;

void GeneratorControl::setGenerator(AGenerator *generator) {
  this->generator = generator;
  this->generator->setEnvelope(adsr->getEnvelope());
  auto cGenerator = dynamic_cast<Generator *>(generator);
  pan.setParameter(cGenerator, &Generator::setPan, {0.0f, 1.0f, 0.5f});
  gain.setParameter(cGenerator, &Generator::setLevel, {0.0f, 1.41254f, 1.0f});
  octaveOffset.setParameter(
      cGenerator, &Generator::setOctaveOffset, {-3, 3, 0});
  semitoneOffset.setParameter(
      cGenerator, &Generator::setSemitoneOffset, {-12, 12, 0});
  phase.setParameter(
      cGenerator, &Generator::setPhase, {-M_PI_2M, M_PI_2M, 0.0f});
  cents.setParameter(cGenerator, &Generator::setCents, {-100, 100, 0});
  unisonVoices.setParameter(
      cGenerator, &Generator::setUnisonVoices, {1, 16, 3});
  unisonPan.setParameter(
      cGenerator, &Generator::setUnisonPan, {0.f, 1.f, 0.5f});
  unisonLevel.setParameter(
      cGenerator, &Generator::setUnisonLevel, {0.f, 1.f, 0.1f});
  unisonFine.setParameter(
      cGenerator, &Generator::setUnisonFine, {0.f, 1.f, 0.5f});
  tablePosition.setParameter(
      cGenerator->getWaveTable(),
      &WaveTable::setPosition,
      MinMax<unsigned int>(
          0, this->generator->getWaveTable()->getMaxPosition(), 0));

  emit wavetableChanged(*this->generator->getWaveTable()->getData(),
                        this->generator->getWaveTable()->getStartPosition(),
                        this->generator->getWaveTable()->getEndPosition());
}

void GeneratorControl::setWavetable(std::vector<float> &computedTable,
                                    unsigned int chunkSize) {
  this->generator->getWaveTable()->SetTable(computedTable, chunkSize);
  tablePosition.setParameter(
      this->generator->getWaveTable(),
      &WaveTable::setPosition,
      MinMax<unsigned int>(
          0, this->generator->getWaveTable()->getMaxPosition(), 0));

  emit wavetableChanged(*this->generator->getWaveTable()->getData(),
                        this->generator->getWaveTable()->getStartPosition(),
                        this->generator->getWaveTable()->getEndPosition());
}

void GeneratorControl::setWavetable(WaveShape::Shape shape,
                                    unsigned int chunkSize) {
  this->generator->getWaveTable()->SetTable(shape, chunkSize);
}

void GeneratorControl::setWavetableDrawer(ArrayDrawer *wavetable) {
  wavetableDrawer = wavetable;
  emit wavetableDrawerChanged();
}

ArrayDrawer *GeneratorControl::getWavetableDrawer() { return wavetableDrawer; }

void GeneratorControl::wavetablePositionChanged() {
  emit wavetableChanged(*this->generator->getWaveTable()->getData(),
                        this->generator->getWaveTable()->getStartPosition(),
                        this->generator->getWaveTable()->getEndPosition());
}

void GeneratorControl::updateWavetableDrawer() {
  connect(this,
          &GeneratorControl::wavetableChanged,
          wavetableDrawer->receiver.get(),
          &ADataReceiverSlots::dataUpdate);
}

void GeneratorControl::loadWavetableFromFile(const QVariant &fileName) {
  AudioFile<float> audioFile;
  audioFile.load(fileName.toString().toStdString());
  setWavetable(audioFile.samples[0], 2048);
}

void GeneratorControl::loadWavetableFromFileUrl(const QVariant &fileName) {
  QString file = fileName.toString();
  QVariant fileVariant = file.mid(7, file.length() - 7);
  loadWavetableFromFile(fileVariant);
}
