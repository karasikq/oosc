import QtQuick 2.0
import QtQuick.Controls 2.12

CheckBox {
    id: control
    checked: true

    property alias innerText: text.text
    property string activeColor: "#98c379"
    property string disabledColor: "#833b3b"

    property string indicatorActiveColor: "#98c379"
    property string indicatorDisabledColor: "#833b3b"

    indicator: Image {
        width: 45
        height: width * 1.146
        source: control.checked ? "qrc:/resources/images/effects/active.png" : "qrc:/resources/images/effects/deactive.png"
    }

    contentItem: Text {
        id: text
        y: 30
        color: control.checked ? "#98c379" : "#833b3b"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Golos UI VF"
    }
}
