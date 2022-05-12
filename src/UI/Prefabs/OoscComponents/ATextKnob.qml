import QtQuick 2.0
import OOSC 1.0

TextKnob {
    id: control
    width: parent.width
    height: parent.height
    direction: KnobDirection.Vertical

    function valueChangedAction(value) {
        
    }

    Connections {
        function onValueChanged(value) {
            valueChangedAction(value)
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
        }

        Connections {
            target: controlMouseArea
            function onReleased(mouse) {
                control.trackMouse = false
                if (mouse.button & Qt.RightButton) {

                }
            }
        }

        Connections {
            target: controlMouseArea
            function onPositionChanged() {
                control.mousePosition = Qt.point(controlMouseArea.mouseX,
                                                    controlMouseArea.mouseY)
                control.mousePositionChanged()
            }
        }
    }
}
