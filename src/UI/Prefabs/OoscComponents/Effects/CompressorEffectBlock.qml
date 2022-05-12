import QtQuick 2.15
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"

EffectPrefab {
    id: control
    effect: effect.effect
    title: "COMPRESSOR"

    CompressorEffect {
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
                    knobTitle: "Threshold"
                    changeableParametr: effect.threshold
                    hintText: currentValue.toFixed(1) + " dB"

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Ratio"
                    changeableParametr: effect.ratio
                    hintText: currentValue.toFixed(0) + " ms"

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
                    knobTitle: "Attack"
                    changeableParametr: effect.attack
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
                    knobTitle: "Release"
                    changeableParametr: effect.release
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
                    knobTitle: "Gain"
                    changeableParametr: effect.gain
                    hintText: currentValue.toFixed(1) + " dB"

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
    D{i:0;formeditorZoom:1.66}D{i:1}D{i:2}D{i:6}D{i:7}D{i:5}D{i:9}D{i:10}D{i:11}D{i:8}
D{i:4}D{i:3}
}
##^##*/

