import QtQuick 2.14
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"

Item {
    id: control
    width: topKnobs.width
    height: topKnobs.height

    property real knobSize: 35.0

    property alias phaseParameter: phaseKnob.changeableParametr
    property alias frequencyParameter: frequencyKnob.changeableParametr
    property alias waveshapeParameter: waveshapeKnob.changeableParametr

        RowLayout {
            id: topKnobs
            spacing: ScaleControl.scaleX(20)
            Item {
                width: ScaleControl.scaleX(knobSize)
                height: ScaleControl.scaleY(50)
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: phaseKnob
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
                width: ScaleControl.scaleX(knobSize)
                height: ScaleControl.scaleY(50)
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: frequencyKnob
                    width: parent.width
                    height: width
                    knobTitle: "Frequency"
                    hintText: currentValue.toFixed(2) + " Hz"

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }
            }

            Item {
                width: ScaleControl.scaleX(knobSize)
                height: ScaleControl.scaleY(50)
                Layout.preferredWidth: width
                Layout.preferredHeight: height
                AbstractKnob {
                    id: waveshapeKnob
                    width: parent.width
                    height: width
                    knobTitle: "Shape"
                    hintText: Math.round(currentValue).toFixed(0)

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }
            }
            layoutDirection: Qt.LeftToRight
        }
}

