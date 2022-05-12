import QtQuick 2.10
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"

EffectPrefab {
    id: control
    effect: effect.effect
    title: "CHORUS"

    ChorusEffect {
        id: effect

        ColumnLayout {
            id: topKnobs
            x: (control.width - width) / 2
            y: 90
            spacing: 25

            RowLayout {
                spacing: 15

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Voices"
                    changeableParametr: effect.voices

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Delay"
                    changeableParametr: effect.delay

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Width"
                    changeableParametr: effect.sweepWidth

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
                    knobTitle: "Depth"
                    changeableParametr: effect.depth

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Rate"
                    changeableParametr: effect.rate

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Phase"
                    changeableParametr: effect.phase

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
    D{i:0;formeditorZoom:1.66}D{i:1}D{i:2}D{i:6}D{i:7}D{i:8}D{i:5}D{i:10}D{i:11}D{i:12}
D{i:9}D{i:4}D{i:3}
}
##^##*/

