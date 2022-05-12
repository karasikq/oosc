import QtQuick 2.14
import OOSC 1.0

OoscKnob {
    id: control
    width: 45
    height: 45
    startAngle: 30
    endAngle: 300
    outerStroke: ScaleControl.scaleX(4)
    pinRadius: ScaleControl.scaleX(2)
    outerColor: ColorScheme.currentScheme.Knob.lineColor

    property string knobTitle: "Knob"
    property string hintText: control.currentValue.toFixed(2)

    function dropAction(drag) { }

    Text {
        id: text2
        x: 0
        y: control.height
        width: control.width
        color: "#ffffff"
        text: knobTitle
        font.pixelSize: ScaleControl.scaleY(10)
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }

    DropArea {
        width: parent.width
        height: parent.height

        onDropped: {
            console.log("dropped")
            parent.dropAction(drag)
        }

        Rectangle {
            anchors.fill: parent
            color: "green"
            visible: parent.containsDrag
        }
    }

    Connections {
        target: control
        function onValueChanged(value) {

        }
    }

    MouseArea {
        id: controlMouseArea
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        width: control.width
        height: control.height
        z: 2
        Connections {
            target: controlMouseArea
            function onPressed(mouse) {

                control.trackMouse = true
                control.startMousePosition = Qt.point(
                            controlMouseArea.mouseX,
                            controlMouseArea.mouseY)
            }

            function onWheel(mouse) {
                control.mouseWheelDelta = mouse.angleDelta
            }
        }

        Connections {
            target: controlMouseArea
            function onReleased(mouse) {
                control.trackMouse = false
                text2.text = control.knobTitle
                if (mouse.button & Qt.RightButton) {
                    console.log("Clicked")
                    control.disconnectLfo()
                }
            }
        }

        Connections {
            target: controlMouseArea
            function onPositionChanged() {
                control.mousePosition = Qt.point(controlMouseArea.mouseX,
                                                    controlMouseArea.mouseY)
                text2.text = control.hintText
                control.mousePositionChanged()
            }
        }
    }
}
