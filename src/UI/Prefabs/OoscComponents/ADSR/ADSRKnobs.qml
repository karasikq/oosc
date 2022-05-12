import QtQuick 2.14
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"

Item {
    id: control
    width: topKnobs.width
    height: topKnobs.height

    property real knobSize: 35.0

    property alias attackParameter: attackKnob.changeableParametr
    property alias decayParameter: decayKnob.changeableParametr
    property alias sustainParameter: sustainKnob.changeableParametr
    property alias releaseParameter: releaseKnob.changeableParametr

    RowLayout {
        id: topKnobs
        spacing: ScaleControl.scaleX(20)
        Item {
            width: ScaleControl.scaleX(knobSize)
            height: ScaleControl.scaleY(50)
            Layout.preferredWidth: width
            Layout.preferredHeight: height
            AbstractKnob {
                id: attackKnob
                width: parent.width
                height: width
                knobTitle: "Attack"
                hintText: currentValue < 1.0 ? (currentValue * 1000).toFixed(1) + " ms" : currentValue.toFixed(2) + " s"

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
                id: decayKnob
                width: parent.width
                height: width
                knobTitle: "Decay"
                hintText: currentValue < 1.0 ? (currentValue * 1000).toFixed(1) + " ms" : currentValue.toFixed(2) + " s"

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
                id: sustainKnob
                width: parent.width
                height: width
                knobTitle: "Sustain"
                hintText: (currentValue * 100).toFixed(0) + "%"

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
                id: releaseKnob
                width: parent.width
                height: width
                knobTitle: "Release"
                hintText: currentValue < 1.0 ? (currentValue * 1000).toFixed(1) + " ms" : currentValue.toFixed(2) + " s"

                function dropAction(drag) {
                    control.connectLfoAction(this, drag)
                }
            }
        }
        layoutDirection: Qt.LeftToRight
    }
}
