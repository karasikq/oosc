import QtQuick 2.14
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../"

GeneratorKnobsControl {
    id: control
    width: 250
    height: 140

    property real knobSize: 35.0

    posKnob: oscWavetablePosKnob
    panKnob: oscPanKnob
    gainKnob: oscGainKnob
    phaseKnob: oscPhaseKnob
    unisonVoicesKnob: oscUniVoicesKnob
    unisonPanKnob: oscUniPanKnob
    unisonLevelKnob: oscUniLevelKnob
    unisonFineKnob: oscUniFineKnob

    function connectLfoAction(knob, drag) {
        if (drag.source.valueSender) {
            knob.connectValueSender(drag.source.valueSender)
        }
    }

    ColumnLayout {
        id: topKnobs
        x: (control.width - width) / 2
        y: 0
        height: 70
        spacing: 0

        Text {
            Layout.alignment: Qt.AlignHCenter
            color: "#575757"
            text: "- unison -"
            width: topKnobs.width
            font.pixelSize: ScaleControl.scaleY(12)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        RowLayout {
            spacing: 15 * ScaleControl.scaleFactorX
            height: ScaleControl.scaleY(50) 
            layoutDirection: Qt.LeftToRight

            Item {
                width: control.knobSize * ScaleControl.scaleFactorX
                height: 50 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: oscUniVoicesKnob
                    width: parent.width
                    height: width
                    knobTitle: "Voices"
                    hintText: Math.round(currentValue).toFixed(0)

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }
            }

            Item {
                id: unisonPanColumn
                width: control.knobSize * ScaleControl.scaleFactorX
                height: 50 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: oscUniPanKnob
                    width: parent.width
                    height: width
                    knobTitle: "Pan"

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }
            }

            Item {
                id: unisonLevelColumn
                width: control.knobSize * ScaleControl.scaleFactorX
                height: 50 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: oscUniLevelKnob
                    width: parent.width
                    height: width
                    knobTitle: "Level"

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }
            }

            Item {
                id: unisonFineColumn
                width: control.knobSize * ScaleControl.scaleFactorX
                height: 50 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: oscUniFineKnob
                    width: parent.width
                    height: width
                    knobTitle: "Fine"

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }
            }
        }
        Text {
            Layout.alignment: Qt.AlignHCenter
            color: "#575757"
            text: "- osc -"
            width: topKnobs.width
            font.pixelSize: ScaleControl.scaleY(12)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        RowLayout {
            id: bottomKnobs
            height: 70
            spacing: 15 * ScaleControl.scaleFactorX
            layoutDirection: Qt.LeftToRight

            Item {
                id: wavetableColumn
                width: control.knobSize * ScaleControl.scaleFactorX
                height: 50 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: oscWavetablePosKnob
                    width: parent.width
                    height: width
                    knobTitle: "Pos"
                    hintText: oscWavetablePosKnob.currentValue.toFixed(0)

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }
            }

            Item {
                id: phaseColumn
                width: control.knobSize * ScaleControl.scaleFactorX
                height: 50 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: oscPhaseKnob
                    width: parent.width
                    height: width
                    knobTitle: "Phase"
                    hintText: (currentValue * 57.2957795131).toFixed(0) + "°"
                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }
            }

            Item {
                id: panColumn
                width: control.knobSize * ScaleControl.scaleFactorX
                height: 50 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: oscPanKnob
                    width: parent.width
                    height: width
                    knobTitle: "Pan"
                    hintText: getPanText(currentValue)

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }

                    function getPanText(value) {
                        var fixed = Math.round(value * 100)
                        if (fixed < 50) {
                            return Math.abs(
                                        ((fixed - 50) * 2)).toFixed(0) + " L"
                        } else if (fixed === 50) {
                            return "<C>"
                        } else {
                            return ((fixed - 50) * 2).toFixed(0) + " R"
                        }
                    }
                }
            }

            Item {
                id: gainColumn
                width: control.knobSize * ScaleControl.scaleFactorX
                height: 50 * ScaleControl.scaleFactorY
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: oscGainKnob
                    width: parent.width
                    height: width
                    knobTitle: "Gain"
                    hintText: (20 * Math.log10(
                                   oscGainKnob.currentValue)).toFixed(2) + " dB"

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
    D{i:0;formeditorZoom:2}D{i:4}D{i:3}D{i:6}D{i:5}D{i:8}D{i:7}D{i:2}D{i:11}D{i:10}D{i:13}
D{i:12}D{i:15}D{i:14}D{i:17}D{i:16}D{i:9}D{i:1}
}
##^##*/

