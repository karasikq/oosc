import QtQuick 2.0
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"

EffectPrefab {
    id: control
    effect: effect.effect
    title: "VIBRATO"

    VibratoEffect {
        id: effect
        anchors.fill: parent

        ColumnLayout {
            id: topKnobs
            anchors.horizontalCenter: parent.horizontalCenter
            y: 80
            spacing: 35

            RowLayout {
                spacing: 15
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Width"
                    changeableParametr: effect.vibratoWidth

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Interpolation"
                    changeableParametr: effect.interpolation

                    function dropAction(drag) {
                        control.connectSender(this, drag)
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
                    knobTitle: "Shape"
                    changeableParametr: effect.lfoShape

                    function dropAction(drag) {
                        control.connectSender(this, drag)
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

