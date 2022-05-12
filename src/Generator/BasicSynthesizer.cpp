#include "BasicSynthesizer.h"
#include "src/Generator/SubGenerator.h"

BasicSynthesizer::BasicSynthesizer() : Synthesizer<3>() {
  audioChannel =
      std::unique_ptr<AudioChannel>(new AudioChannel(2, bufferSize / 2));
  rawData = new float[bufferSize];
  setupGenerators();
}

void BasicSynthesizer::setupGenerators() {
  generators[0] = std::make_unique<Generator>(0);
  generators[1] = std::make_unique<Generator>(1);
  generators[2] = std::make_unique<SubGenerator>(2);

  generatorsThreadPool = std::make_unique<GeneratorsThreadPool>(3);
  generatorsThreadPool->addTask(0, &BasicSynthesizer::generatorThread, this, 0);
  generatorsThreadPool->addTask(1, &BasicSynthesizer::generatorThread, this, 1);
  generatorsThreadPool->addTask(2, &BasicSynthesizer::generatorThread, this, 2);
}

void BasicSynthesizer::setMasterVolume(float value) {
  Synthesizer<3>::setMasterVolume(value);
}
