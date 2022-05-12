import QtQuick 2.12
import QtQuick.Controls 2.12

Button {
    id: control
    text: qsTr("Button")

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.down ? "#995229" : "#FF8882"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        opacity: enabled ? 1 : 0.3
        color: "#191d24"
        border.color: control.down ? "#995229" : "#FF8882"
        border.width: 1
        radius: 2
    }
}
