import QtQuick 2.15
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"

EffectPrefab {
    id: control
    effect: effect.effect
    title: "REVERB"

    ReverbEffect {
        id: effect

        ColumnLayout {
            id: topKnobs
            x: (control.width - width) / 2
            y: 80
            spacing: 35

            RowLayout {
                Layout.leftMargin: 35
                spacing: 15

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Wet"
                    changeableParametr: effect.wet

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Dry"
                    changeableParametr: effect.dry

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
                    knobTitle: "Width"
                    changeableParametr: effect.reverbWidth

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Damping"
                    changeableParametr: effect.damping

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Roomsize"
                    changeableParametr: effect.roomSize

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

