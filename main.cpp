#include <QDebug>
#include <QDir>
#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlProperty>
#include <memory>

#include "src/ApplicationConfig.h"
#include "src/AudioSettings.h"
#include "src/MixerQmlWrapper.h"
#include "src/UI/Charts/LinearIndicator.h"
#include "src/UI/Charts/PolarVectorscope.h"
#include "src/UI/Controls/KeyboardControl.h"
#include "src/UI/Controls/TextKnob.h"
#include "src/UI/Effects/CompressorUIWrapper.h"
#include "src/UI/Effects/ChorusUIWrapper.h"
#include "src/UI/Effects/DelayUIWrapper.h"
#include "src/UI/Effects/DistortionUIWrapper.h"
#include "src/UI/Effects/EqUIWrapper.h"
#include "src/UI/Effects/FlangerUIWrapper.h"
#include "src/UI/Effects/PhaserUIWrapper.h"
#include "src/UI/Effects/ReverbUIWrapper.h"
#include "src/UI/Effects/VibratoUIWrapper.h"
#include "src/UI/Midi/MidiPlaybackUI.h"
#include "src/UI/SynthesizerControls/SubGeneratorKnobs.h"
#include "src/UI/SynthesizerControls/GeneratorKnobsControl.h"
#include "src/UI/SynthesizerControls/GeneratorControl.h"
#include "src/Utils/ApplicationConfigQML.h"
#include "src/Utils/QML/FileIO.h"

int main(int argc, char *argv[]) {
  ApplicationConfig::createConfigMap();

  QCoreApplication::setApplicationName(ApplicationConfig::getAppName());

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  // Register OOSC QtQuick Items
  qmlRegisterType<MixerQmlWrapper>("OOSC", 1, 0, "MixerControl");
  qmlRegisterType<FileIO>("OOSC", 1, 0, "FileIO");
  qmlRegisterType<SynthesizerControl>("OOSC", 1, 0, "SynthesizerControl");
  qmlRegisterType<GeneratorControl>("OOSC", 1, 0, "GeneratorControl");
  qmlRegisterType<SubGeneratorControl>("OOSC", 1, 0, "SubGeneratorControl");
  qmlRegisterType<GeneratorKnobsControl>("OOSC", 1, 0, "GeneratorKnobsControl");
  qmlRegisterType<SubGeneratorKnobs>("OOSC", 1, 0, "SubGeneratorKnobs");
  qmlRegisterType<TextKnob>("OOSC", 1, 0, "TextKnob");
  qmlRegisterType<Knob>("OOSC", 1, 0, "OoscKnob");
  qmlRegisterType<KeyboardControl>("OOSC", 1, 0, "KeyboardControl");
  qmlRegisterType<ArrayDrawer>("OOSC", 1, 0, "OoscWavetable");
  qmlRegisterType<ADSRDrawer>("OOSC", 1, 0, "ADSRDrawer");
  qmlRegisterType<LinearIndicator>("OOSC", 1, 0, "LinearIndicator");
  qmlRegisterType<PolarVectorscope>("OOSC", 1, 0, "Vectorscope");
  qmlRegisterType<MidiPlaybackUI>("OOSC", 1, 0, "MidiPlayback");
  qmlRegisterType<LfoController>("OOSC", 1, 0, "LfoController");
  qmlRegisterType<KnobInterpolation>("OOSC", 1, 0, "KnobInterpolation");
  qmlRegisterType<KnobDirection>("OOSC", 1, 0, "KnobDirection");
  qmlRegisterType<ADSRController>("OOSC", 1, 0, "ADSRController");
  qmlRegisterSingletonType<ApplicationConfigQML>(
      "OOSC", 1, 0, "ApplicationConfig", ApplicationConfigQML::provider);

  qmlRegisterType<DelayUIWrapper>("OOSC", 1, 0, "DelayEffect");
  qmlRegisterType<ReverbUIWrapper>("OOSC", 1, 0, "ReverbEffect");
  qmlRegisterType<ChorusUIWrapper>("OOSC", 1, 0, "ChorusEffect");
  qmlRegisterType<PhaserUIWrapper>("OOSC", 1, 0, "PhaserEffect");
  qmlRegisterType<CompressorUIWrapper>("OOSC", 1, 0, "CompressorEffect");
  qmlRegisterType<DistortionUIWrapper>("OOSC", 1, 0, "DistortionEffect");
  qmlRegisterType<EqUIWrapper>("OOSC", 1, 0, "EqEffect");
  qmlRegisterType<FlangerUIWrapper>("OOSC", 1, 0, "FlangerEffect");
  qmlRegisterType<VibratoUIWrapper>("OOSC", 1, 0, "VibratoEffect");

  qRegisterMetaType<IChangeableParameter *>("IChangeableParameter *");
  qRegisterMetaType<BasicSynthesizer *>("BasicSynthesizer *");
  qRegisterMetaType<Effect *>("Effect *");
  qRegisterMetaType<AValueSender *>("AValueSender *");
  qRegisterMetaType<ADataReceiver *>("ADataReceiver *");
  qRegisterMetaType<ITimeReceiver *>("ITimeReceiver *");
  qRegisterMetaType<MinMax<float>>("MinMax<float>");
  qRegisterMetaType<KnobInterpolation::KnobInterpolationMethod>(
      "KnobInterpolationMethod");
  qRegisterMetaType<KnobDirection::KnobDirectionMethod>("KnobDirectionMethod");
  qRegisterMetaType<std::vector<float>>("std::vector<float>");
  qRegisterMetaType<std::vector<float>::const_iterator>("std::vector<float>::const_iterator");
  qRegisterMetaType<ADSRDrawer *>("ADSRDrawer *");

  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine,
      &QQmlApplicationEngine::objectCreated,
      &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  // Setup local directories
  QDir localDir(ApplicationConfig::getLocalDataPath());
  if (!localDir.exists())
    localDir.mkpath(".");

  QDir midiDir(ApplicationConfig::getMidiDataPath());
  if (!midiDir.exists())
    midiDir.mkpath(".");

  QDir wavetablesDir(ApplicationConfig::getWavetablesDataPath());
  if (!wavetablesDir.exists())
    wavetablesDir.mkpath(".");

  return app.exec();
}
