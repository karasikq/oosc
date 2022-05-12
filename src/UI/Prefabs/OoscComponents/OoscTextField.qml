import QtQuick 2.12
import QtQuick.Controls 2.12

TextField {
    id: control
    placeholderText: qsTr("Placeholder")
    color: "#ff8640"
    selectByMouse: true

    background: Rectangle {
        width: parent.width
        height: parent.height
        color: "#191d24"
        border.color: control.focus ? "#ff8640" : "#995229"
        radius: 2
    }
}
