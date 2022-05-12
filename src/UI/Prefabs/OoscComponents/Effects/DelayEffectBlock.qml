import QtQuick 2.15
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"
import "../"

EffectPrefab {
    id: control
    effect: effect.effect
    title: "DELAY"

    DelayEffect {
        id: effect

        ColumnLayout {
            id: topKnobs
            x: (control.width - width) / 2
            y: 115
            spacing: -5

            RowLayout {
                Layout.leftMargin: (bottomRow.width - width) / 2
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Time"
                    changeableParametr: effect.time
                    hintText: (currentValue * 1000).toFixed(1) + " ms"

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }
            }

            RowLayout {
                id: bottomRow
                spacing: 55
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Mix"
                    changeableParametr: effect.mix
                    hintText: (currentValue * 1000).toFixed(1) + " ms"

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Feedback"
                    changeableParametr: effect.feedback
                    hintText: (currentValue * 1000).toFixed(1) + " ms"

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

