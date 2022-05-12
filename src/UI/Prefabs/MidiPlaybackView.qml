import QtQuick 2.10
import QtQuick.Controls 2.5
import OOSC 1.0
import QtQuick.Layouts 1.15
import "./Forms"
import "./OoscComponents"

DefaultBlock {
    id: control

    signal requestMidiLoad()

    function loadMidiFromUrl(url) {
        midiPlayback.loadFromFileUrl(url)
    }

    function attachSynthesizer(synth) {
        midiPlayback.synthesizer = synth
    }

    property alias synthesizer: midiPlayback.synthesizer

    MidiPlayback {
        id: midiPlayback
        visible: true
        objectName: "midiPlayback"
    }

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 70
        height: 60

        Item {
            width: 60
            height: 60
            ImageButton {
                anchors.fill: parent
                id: playMidiButton
                imageSource: "qrc:/resources/images/midiPlayback/play.png"

                Connections {
                    target: playMidiButton
                    function onClicked() {
                        playMidiButton.visible = false
                        pauseMidiButton.visible = true
                        midiPlayback.play()
                    }
                }
            }

            ImageButton {
                anchors.fill: parent
                id: pauseMidiButton
                visible: false
                imageSource: "qrc:/resources/images/midiPlayback/pause.png"
                Connections {
                    target: pauseMidiButton
                    function onClicked() {
                        playMidiButton.visible = true
                        pauseMidiButton.visible = false
                        midiPlayback.pause()
                    }
                }
            }
        }


        Item {
            width: 60
            height: 60
            ImageButton {
                id: stopMidiButton
                anchors.fill: parent
                imageSource: "qrc:/resources/images/midiPlayback/stop.png"
                Connections {
                    target: stopMidiButton
                    function onClicked() {
                        playMidiButton.visible = true
                        pauseMidiButton.visible = false
                        midiPlayback.stop()
                    }
                }
            }
        }

        Item {
            width: 60
            height: 60
            ImageButton {
                id: loadMidiButton
                anchors.fill: parent
                imageSource: "qrc:/resources/images/midiPlayback/midi.png"

                Connections {
                    target: loadMidiButton
                    function onClicked() {
                        control.requestMidiLoad()
                    }
                }
            }
        }
    }
}
