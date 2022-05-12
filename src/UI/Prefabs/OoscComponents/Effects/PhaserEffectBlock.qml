import QtQuick 2.0
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"
import "../"

EffectPrefab {
    id: control
    effect: effect.effect
    title: "PHASER"

    PhaserEffect {
        id: effect
        width: parent.width
        height: parent.height
            Item {
                id: textKnobs
                width: control.width
                height: 22
                y: 50

                Text {
                    id: shapeText
                    width: parent.width
                    color: "#575757"
                    text: "Sin"
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.italic: true
                    font.family: "Golos UI VF"

                    ATextKnob {
                        width: parent.width
                        height: parent.height
                        changeableParametr: effect.lfoShape

                        function valueChangedAction(value) {
                            shapeText.text = effect.lfoShapeToString(value) 
                        }
                    }
                }

            }
        ColumnLayout {
            id: topKnobs
            anchors.top: textKnobs.bottom
            anchors.horizontalCenter: parent.horizontalCenter 
            height: 50
            spacing: 20

            RowLayout {
                spacing: 15
                Layout.alignment: Qt.AlignHCenter
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Width"
                    changeableParametr: effect.phaseWidth

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Depth"
                    changeableParametr: effect.depth

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Filters"
                    changeableParametr: effect.numberOfFilters

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }
            }

            RowLayout {
                spacing: 15
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Frequency"
                    changeableParametr: effect.lfoFrequency

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "F. Freq"
                    changeableParametr: effect.filterFrequency

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Feedback"
                    changeableParametr: effect.feedback

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }

            }

        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}D{i:1}D{i:5}D{i:6}D{i:7}D{i:4}D{i:3}D{i:2}
}
##^##*/

