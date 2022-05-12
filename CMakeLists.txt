cmake_minimum_required(VERSION 3.14)

project(oosc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_definitions(-DQT_QML_RELEASE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
    src/ADSR/ADSREnvelope.cpp
    src/ApplicationConfig.cpp
    src/Effects/Chorus.cpp
    src/Effects/Compressor.cpp
    src/Effects/Delay.cpp
    src/Effects/ParametricEQ.cpp
    src/Effects/Distortion.cpp
    src/Effects/Vibrato.cpp
    src/Effects/Reverb.cpp
    src/Effects/Flanger.cpp
    src/Effects/Phaser.cpp
    src/Generator/AGenerator.cpp
    src/Generator/Generator.cpp
    src/Generator/SubGenerator.cpp
    src/Generator/Note.cpp
    src/Generator/WaveTable.cpp
    src/Generator/GeneratorsThreadPool.cpp
    src/MIDI/MidiPlayback.cpp
    src/MixerOutput.cpp
    src/MixerQmlWrapper.cpp
    src/Generator/Synthesizer.cpp
    src/Generator/BasicSynthesizer.cpp
    src/Parametrs/ChangeableParameter.cpp
    src/Parametrs/AValueSender.cpp
    src/UI/Charts/ADataReceiver.cpp
    src/UI/Charts/ADSRDrawer.cpp
    src/UI/Charts/ArrayDrawer.cpp
    src/UI/Charts/ArrayGradientDrawer.cpp
    src/UI/Charts/LinearIndicator.cpp
    src/UI/Charts/PolarVectorscope.cpp
    src/UI/Controls/Knob.cpp
    src/UI/Controls/AKnob.cpp
    src/UI/Controls/TextKnob.cpp
    src/UI/Controls/KeyboardControl.cpp
    src/UI/Midi/MidiPlaybackUI.cpp
    src/UI/SynthesizerControls/AGeneratorControl.cpp
    src/UI/SynthesizerControls/GeneratorControl.cpp
    src/UI/SynthesizerControls/SubGeneratorControl.cpp
    src/UI/SynthesizerControls/GeneratorKnobsControl.cpp
    src/UI/SynthesizerControls/SubGeneratorKnobs.cpp
    src/UI/SynthesizerControls/SynthesizerControl.cpp
    src/UI/SynthesizerControls/LfoController.cpp
    src/UI/SynthesizerControls/ADSRController.cpp
    # EFFECTS WRAPPERS
    src/UI/Effects/EffectUIWrapper.cpp
    src/UI/Effects/DelayUIWrapper.cpp
    src/UI/Effects/ReverbUIWrapper.cpp
    src/UI/Effects/ChorusUIWrapper.cpp
    src/UI/Effects/PhaserUIWrapper.cpp
    src/UI/Effects/CompressorUIWrapper.cpp
    src/UI/Effects/DistortionUIWrapper.cpp
    src/UI/Effects/EqUIWrapper.cpp
    src/UI/Effects/FlangerUIWrapper.cpp
    src/UI/Effects/VibratoUIWrapper.cpp
    # [EFFECTS WRAPPERS]
    src/Utils/ApplicationConfigQML.cpp
    src/Utils/AudioChannel.cpp
    src/Utils/BezierCurve.cpp
    src/Utils/CubicBezierCurve.cpp
    src/Utils/Filters/AllPassFilter.cpp
    src/Utils/Filters/CombFilter.cpp
    src/Utils/IIR/IIR.cpp
    src/Utils/IIR/IIRCoefficients.cpp
    src/Utils/LFO.cpp
    src/Utils/QML/FileIO.cpp
    src/Utils/WaveShape.cpp
    src/Utils/ITimeReceiver.cpp
    src/AudioSettings.cpp
    ThirdParty/midifile/src/Binasc.cpp
    ThirdParty/midifile/src/MidiEvent.cpp
    ThirdParty/midifile/src/MidiEventList.cpp
    ThirdParty/midifile/src/MidiFile.cpp
    ThirdParty/midifile/src/MidiMessage.cpp
    ThirdParty/midifile/src/Options.cpp
    main.cpp
    qml.qrc
)

set(RESOURCES qml.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(oosc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${RESOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET oosc APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(oosc SHARED
            ${PROJECT_SOURCES}
            ${RESOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(oosc
          ${PROJECT_SOURCES}
          ${RESOURCES}
        )
    endif()
endif()

# target_compile_definitions(oosc
#   PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(oosc
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Qml portaudio)

set_target_properties(oosc PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(oosc)
    qt_finalize_executable(oosc)
endif()
