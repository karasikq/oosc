import QtQuick 2.15
import OOSC 1.0
import "../../"

OscRectangleBlock {
    id: control
    width: 250
    height: 250
    headerText: "ADSR 1"

    property var adsrController: controller
    Image {
        id: dragImage
        x: parent.width - 28
        y: 7.5
        width: ScaleControl.scaleX(20)
        height: width
        source: "qrc:/resources/images/connectArrow.png"
        fillMode: Image.PreserveAspectFit
        mipmap: true

        property real defaultX: parent.width - 28
        property real defaultY: 7.5
        property var valueSender: controller.sender

        Drag.active: dragArea.drag.active

        MouseArea {
            id: dragArea
            anchors.fill: parent

            onReleased: {
                dragImage.Drag.drop()
                dragImage.x = dragImage.defaultX
                dragImage.y = dragImage.defaultY
            }

            drag.target: dragImage
        }
    }
            
    ADSRDrawer {
        id: drawer
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: ScaleControl.scaleX(10)
        anchors.rightMargin: ScaleControl.scaleX(10)
        anchors.topMargin: ScaleControl.scaleY(50)
        height: ScaleControl.scaleY(100)
        lineColor: ColorScheme.currentScheme.ADSRDrawer.lineColor
        backgroundColor: ColorScheme.currentScheme.ADSRDrawer.backgroundColor
        z: 10
    }

    ADSRController {
        id: controller
        drawer: drawer
    }

    ADSRKnobs {
        id: knobs
        anchors.top: drawer.bottom
        anchors.topMargin: ScaleControl.scaleY(20)
        anchors.horizontalCenter: control.horizontalCenter
        attackParameter: controller.attack
        decayParameter: controller.decay
        sustainParameter: controller.sustain
        releaseParameter: controller.release
    }
}
