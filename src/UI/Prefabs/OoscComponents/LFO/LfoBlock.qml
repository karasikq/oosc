import QtQuick 2.10
import OOSC 1.0
import "../../"

OscRectangleBlock {
    id: control
    width: 350
    height: 250
    headerText: "LFO 1"
    headerHeight: ScaleControl.scaleY(30)

    property alias lfoController: controller 

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

    OoscWavetable {
        id: lfoDrawer
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: ScaleControl.scaleX(10)
        anchors.rightMargin: ScaleControl.scaleX(10)
        anchors.topMargin: ScaleControl.scaleY(50)
        height: ScaleControl.scaleY(100)
        lineColor: ColorScheme.currentScheme.ArrayDrawer.lineColor
        backgroundColor: ColorScheme.currentScheme.ArrayDrawer.backgroundColor
        centerLineColor: ColorScheme.currentScheme.ArrayDrawer.centerLineColor
        z: 10
    }

    LfoController {
        id: controller
        objectName: "lfoA"
        drawer: lfoDrawer.dataReceiver
    }

    LfoKnobs {
        id: knobs
        anchors.top: lfoDrawer.bottom
        anchors.topMargin: ScaleControl.scaleY(20)
        anchors.horizontalCenter: control.horizontalCenter
        phaseParameter: controller.phase
        frequencyParameter: controller.frequency
        waveshapeParameter: controller.waveshape
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33}D{i:1}D{i:2}D{i:3}
}
##^##*/

