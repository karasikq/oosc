import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import OOSC 1.0
import Qt.labs.folderlistmodel 2.15
import "./src/UI/Prefabs"
import "./src/UI/Prefabs/Dropdowns"
import "./src/UI/Prefabs/Midi"
import "./src/UI/Prefabs/OoscComponents"
import "./src/UI/Prefabs/Forms"
import "./src/UI/Prefabs/OoscComponents/LFO"
import "./src/UI/Prefabs/OoscComponents/ADSR"
import "./src/UI/Prefabs/Oscs"
import "./src/UI/Prefabs/OoscComponents/Effects"

Window {
    id: main
    width: 1030
    height: 890
    visible: true
    color: ColorScheme.currentScheme.Window.background
    title: qsTr("OOSC !")

    property real windowRatio: 1.1573

    MixerControl {
        id: mixerControl
    }

    SynthesizerControl {
        id: mainSynth
        objectName: "synth1"
        focus: true
        generatorControls: [oscA.generatorControl, oscB.generatorControl, subOsc.generatorControl]

        Connections {
            target: mainSynth
            function onExtremaRightReceived(range) {
                synthOutputViewLoader.volumeIndocatorRight.dataUpdate(range)
            }

            function onExtremaLeftReceived(range) {
                synthOutputViewLoader.volumeIndocatorLeft.dataUpdate(range)
            }
        }

        Component.onCompleted: {
            mixerControl.attachSynthesizer(mainSynth.synthesizer)
        }
    }

    ColumnLayout {
        id: content
        anchors.fill: parent
        anchors.leftMargin: 20 * ScaleControl.scaleFactorX
        anchors.rightMargin: 20 * ScaleControl.scaleFactorX
        anchors.topMargin: 10 * ScaleControl.scaleFactorY
        anchors.bottomMargin: 20 * ScaleControl.scaleFactorY
        spacing: 20 * ScaleControl.scaleFactorY

        Item {
            id: header
            Layout.fillWidth: true
            height: 65 * ScaleControl.scaleFactorY

            Text {
                id: headerText
                color: "#ffffff"
                text: qsTr("OOSC !")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 32
                verticalAlignment: Text.AlignVCenter
                font.italic: true
            }

            Item {
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                width: 35
                height: 55

                AbstractKnob {
                    y: 5
                    width: 35
                    height: 35
                    knobTitle: "Master"
                    hintText: (20 * Math.log10(currentValue)).toFixed(2) + " dB"

                    changeableParametr: mainSynth.gain
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.topMargin: -15 * ScaleControl.scaleFactorX
            spacing: 20 * ScaleControl.scaleFactorX
            height: 300

            SubOsc {
                id: subOsc
                width: 180 * ScaleControl.scaleFactorX
                height: 300 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                adsrController: adsr1.adsrController
            }

            OscBlock {
                objectName: "oscA"
                id: oscA
                generatorControl: synth1generator1

                GeneratorControl {
                    id: synth1generator1
                    objectName: "synth1generator1"
                    generatorID: 0
                    wavetableDrawer: oscA.wavetableControl
                    adsrController: adsr1.adsrController

                    Component.onCompleted: {
                        oscA.knobsControl.attachKnobs()
                        oscA.octControl.changeableParametr = synth1generator1.octaveOffset
                        oscA.semControl.changeableParametr = synth1generator1.semitoneOffset
                        oscA.cenControl.changeableParametr = synth1generator1.cents
                    }
                }
                width: 250 * ScaleControl.scaleFactorX
                height: 300 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
            }

            OscBlock {
                objectName: "oscB"
                id: oscB
                headerText: "OSC B"
                generatorControl: synth1generator2

                GeneratorControl {
                    id: synth1generator2
                    objectName: "synth1generator2"
                    generatorID: 1
                    wavetableDrawer: oscB.wavetableControl
                    adsrController: adsr1.adsrController

                    Component.onCompleted: {
                        oscB.knobsControl.attachKnobs()
                        oscB.octControl.changeableParametr = synth1generator2.octaveOffset
                        oscB.semControl.changeableParametr = synth1generator2.semitoneOffset
                        oscB.cenControl.changeableParametr = synth1generator2.cents
                    }
                }
                width: 250 * ScaleControl.scaleFactorX
                height: 300 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
            }

            OscRectangleBlock {
                width: 250 * ScaleControl.scaleFactorX
                height: 300 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                headerText: "EFFECTS"

                EffectsList {
                    width: parent.width - 20
                    height: parent.height - 60
                    x: 10
                    y: 40
                    synthesizer: mainSynth
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 20 * ScaleControl.scaleFactorX

            ADSRBlock {
                id: adsr1
                width: 300 * ScaleControl.scaleFactorX
                height: 250 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                headerText: "ENV 1"

                Component.onCompleted: {
                    mainSynth.connectToOutputNote(
                                adsr1.adsrController.dataReceiver)
                }
            }

            LfoBlock {
                id: lfo1
                width: 300 * ScaleControl.scaleFactorX
                height: 250 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height

                Component.onCompleted: {
                    mixerControl.attachTimeReceiver(
                                lfo1.lfoController.timeReceiver)
                }
            }

            DefaultBlock {
                id: visualBlock
                width: 350 * ScaleControl.scaleFactorX
                height: 250 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                OoscDropdownArray {
                    id: visualsBar
                    width: parent.width
                    height: ScaleControl.scaleY(30)
                    z: 10
                    model: ["OUTPUT", "VECTORSCOPE"]

                    /* popup: Popup {
                        y: control.height - 1
                        width: control.width
                        implicitHeight: contentItem.implicitHeight
                        padding: 1

                        contentItem: ListView {
                            clip: true
                            implicitHeight: visualBlock.height
                            model: control.popup.visible ? control.delegateModel : null
                            currentIndex: control.highlightedIndex
                            ScrollIndicator.vertical: ScrollIndicator {}
                        }

                        background: Rectangle {
                            color: ColorScheme.currentScheme.DefaultBlock.background
                            border.color: ColorScheme.currentScheme.DefaultBlock.borderColor
                            radius: 2
                        }
                    } */
                }

                StackLayout {
                    anchors.fill: parent
                    anchors.top: visualsBar.bottom
                    anchors.topMargin: ScaleControl.scaleY(30)
                    currentIndex: visualsBar.currentIndex

                    OutputWaveView {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        id: synthOutputViewLoader

                        Component.onCompleted: {
                            mainSynth.connectToOutputLeft(
                                        leftWavetable.dataReceiver)
                            mainSynth.connectToOutputRight(
                                        rightWavetable.dataReceiver)
                        }
                    }

                    Item {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Vectorscope {
                            id: vectorscope
                            width: 200
                            height: 200
                            anchors.horizontalCenter: parent.horizontalCenter

                            Component.onCompleted: {
                                mainSynth.connectToOutput(
                                            vectorscope.dataReceiver)
                            }
                        }
                        Text {
                            color: "#55575757"
                            text: "+L"
                            anchors.top: vectorscope.top
                            anchors.left: vectorscope.left
                            anchors.leftMargin: ScaleControl.scaleX(20)
                            anchors.topMargin: ScaleControl.scaleY(10)
                            font.pixelSize: ScaleControl.scaleY(16)
                            verticalAlignment: Text.AlignVCenter
                        }
                        Text {
                            color: "#55575757"
                            text: "+R"
                            anchors.top: vectorscope.top
                            anchors.right: vectorscope.right
                            anchors.rightMargin: ScaleControl.scaleX(20)
                            anchors.topMargin: ScaleControl.scaleY(10)
                            font.pixelSize: ScaleControl.scaleY(16)
                            verticalAlignment: Text.AlignVCenter
                        }
                        Text {
                            color: "#55575757"
                            text: "-R"
                            anchors.bottom: vectorscope.bottom
                            anchors.bottomMargin: ScaleControl.scaleY(10)
                            anchors.left: vectorscope.left
                            anchors.leftMargin: ScaleControl.scaleX(20)
                            font.pixelSize: ScaleControl.scaleY(16)
                            verticalAlignment: Text.AlignVCenter
                        }
                        Text {
                            color: "#55575757"
                            text: "-L"
                            anchors.bottom: vectorscope.bottom
                            anchors.bottomMargin: ScaleControl.scaleY(10)
                            anchors.right: vectorscope.right
                            anchors.rightMargin: ScaleControl.scaleX(20)
                            font.pixelSize: ScaleControl.scaleY(16)
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }
        }

        RowLayout {
            width: parent.width
            height: 200 * ScaleControl.scaleFactorY
            spacing: 20 * ScaleControl.scaleFactorX

            Item {
                width: parent.width
                height: parent.height
                Layout.preferredWidth: width
                Layout.preferredHeight: height

                OoscTabBar {
                    id: bar
                    width: parent.width
                    height: 30
                    OoscTabButton {
                        text: qsTr("Midi")
                    }
                    OoscTabButton {
                        text: qsTr("Keyboard")
                    }
                }

                StackLayout {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: bar.bottom
                    anchors.bottom: parent.bottom
                    currentIndex: bar.currentIndex

                    MidiPlaybackView {
                        id: midiPlaybackViewLoader
                        width: parent.width
                        height: parent.height
                        synthesizer: mainSynth

                        Connections {
                            target: midiPlaybackViewLoader
                            function onRequestMidiLoad() {
                                midiLoadView.visible = true
                            }
                        }

                        MidiLoadView {
                            id: midiLoadView
                            anchors.fill: parent
                            visible: false

                            onLoadMidiAndExit: fileUrl => {
                                                   midiPlaybackViewLoader.loadMidiFromUrl(
                                                       fileUrl)
                                                   visible = false
                                               }
                        }
                    }

                    DefaultBlock {
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        KeyboardControl {
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.right: parent.right
                            anchors.topMargin: 35
                            anchors.leftMargin: 25
                            anchors.rightMargin: 20
                            height: 100

                            synthesizer: mainSynth

                            keyColor: ColorScheme.currentScheme.Keyboard.keyColor
                            keyActiveColor: ColorScheme.currentScheme.Keyboard.activeKeyColor
                            sharpColor: ColorScheme.currentScheme.Keyboard.sharpColor
                            sharpActiveColor: ColorScheme.currentScheme.Keyboard.activeSharpColor
                        }
                    }
                }
            }
        }
    }

    MouseArea {
        width: 20
        height: 20
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        onPositionChanged: {
            var w = mouseX + x, h = mouseY + y
            if (w > h * main.windowRatio) {
                main.width = w
                main.height = w * (1.0 / main.windowRatio)
                main.maximumHeight = w * (1.0 / main.windowRatio)
                main.maximumWidth = w
                main.minimumHeight = w * (1.0 / main.windowRatio)
                main.minimumWidth = w
            } else {
                main.width = h * main.windowRatio
                main.height = h
                main.maximumHeight = h
                main.maximumWidth = h * main.windowRatio
                main.minimumHeight = h
                main.minimumWidth = h * main.windowRatio
            }
            ScaleControl.scaleFactorX = main.width / 1030
            ScaleControl.scaleFactorY = main.height / 900
        }
        /* Rectangle { */
        /*   anchors.fill: parent */
        /*   color: "red" */
        /* } */
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:3}D{i:2}D{i:5}D{i:4}D{i:1}D{i:7}D{i:9}D{i:10}D{i:12}
D{i:14}D{i:16}D{i:15}D{i:13}D{i:11}D{i:8}D{i:17}D{i:18}D{i:20}D{i:19}D{i:23}D{i:25}
D{i:24}D{i:22}D{i:21}D{i:27}D{i:26}D{i:6}
}
##^##*/

