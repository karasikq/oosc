import QtQuick 2.0
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"

EffectPrefab {
    id: control
    effect: effect.effect
    title: "DISTORTION"

    DistortionEffect {
        id: effect

        ColumnLayout {
            id: topKnobs
            x: (control.width - width) / 2
            y: 80
            spacing: 35

            RowLayout {
                spacing: 15

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Output"
                    changeableParametr: effect.outputGain
                    hintText: (20 * Math.log10(currentValue)).toFixed(2) + " dB"

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Input"
                    changeableParametr: effect.inputGain
                    hintText: (20 * Math.log10(currentValue)).toFixed(2) + " dB"

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
                    knobTitle: "Type"
                    changeableParametr: effect.distortionType
                    hintText: Math.round(currentValue).toFixed(0)

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Tone"
                    changeableParametr: effect.tone

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

