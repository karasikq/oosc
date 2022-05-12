import QtQuick 2.15
import "../"

Item {
    id: control
    property alias title: effectTitle.text
    property bool active: false
    property var effect

    signal backButtonClicked()
    signal powerButtonClicked()

    ScaleAnimator {
        id: appearAnimation
        target: control
        from: 0.2
        to: 1
        duration: 120
        running: true
    }

    onVisibleChanged: {
        appearAnimation.start()
    }

    function connectSender(knob, drag) {
        if (drag.source.valueSender) {
            knob.connectValueSender(drag.source.valueSender)
        }
    }

    Item { 
        x: effectTitle.x - 38 
        y: 2
        width: 28
        height: 28
        ImageButton {
            anchors.fill: parent
            imageSource: "qrc:/resources/images/effects/backArrow.png"
            onClicked: {
                control.backButtonClicked()
            }
        }
    }

    Item { 
        x: effectTitle.x + effectTitle.width + 10 
        y: 2
        width: 28
        height: 28
        ImageButton {
            anchors.fill: parent
            imageSource: control.active ? "qrc:/resources/images/effects/active.png" : "qrc:/resources/images/effects/deactive.png"
            onClicked: {
                control.powerButtonClicked()
            }
        }
    }

    Text {
        x: (parent.width - width) / 2
        id: effectTitle
        color: "#98c379"
        text: "EFFECT"
        font.pixelSize: 24
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.italic: true
        font.family: "Golos UI VF"
    }
}

/*##^##
Designer {
    D{i:0;height:50;width:185}D{i:1}
}
##^##*/
