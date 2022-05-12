import QtQuick 2.12
import QtQuick.Controls 2.12
import "../"

TabButton {
    id: control
    text: qsTr("Button")
    height: parent.height

    contentItem: Text {
        id: controlText
        topPadding: 4
        text: control.text
        opacity: checked ? 1.0 : 0.5
        color: checked ? ColorScheme.currentScheme.TabButton.active : ColorScheme.currentScheme.TabButton.unactive
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Golos UI VF"
        elide: Text.ElideRight
        font.pixelSize: 14
        font.italic: true
        font.bold: false
    }

    background: Rectangle {
        color: "#00000000"
    }

    Rectangle {
        width: parent.width - 2
        x: 1
        height: 1
        anchors.bottom: parent.bottom
        color:checked ? ColorScheme.currentScheme.TabButton.active : ColorScheme.currentScheme.TabButton.unactive 
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
