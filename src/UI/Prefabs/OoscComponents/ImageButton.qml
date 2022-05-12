import QtQuick 2.12
import QtQuick.Controls 2.12

Button {
    id: control

    property alias imageSource: image.source

    contentItem: Image {
        id: image
        anchors.fill: parent
        x: 0
        y: 0
        opacity: enabled ? 1.0 : 0.3
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        source: "qrc:/resources/images/enable.png"
        mipmap: true
    }

    background: Rectangle {
        color: "#00000000"
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:16}
}
##^##*/
