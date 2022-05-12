import QtQuick 2.12
import QtQuick.Controls 2.12

//Button {
//    width: background.width
//    height: background.height

//    property bool effectIsActive: false
//    property alias innerText: text.text
//    property string activeColor: "#de5d68"
//    property string disabledColor: "#833b3b"

//    background: Rectangle {
//        width: text.width + 20
//        height: text.height + 20
//        radius: height / 2
//        color: "#00000000"
//        border.color: effectIsActive ? activeColor : disabledColor
//        border.width: 2
//    }

//    Text {
//        x: 10
//        y: 10
//        id: text
//        color: effectIsActive ? activeColor : disabledColor
//        text: "Text"
//        font.letterSpacing: -0.5
//        font.pixelSize: 14
//        horizontalAlignment: Text.AlignHCenter
//        verticalAlignment: Text.AlignVCenter
//        font.italic: false
//        font.weight: Font.Normal
//        font.family: "Golos UI VF"
//        renderType: Text.QtRendering
//        minimumPointSize: 12
//        minimumPixelSize: 12


//    }
//}


CheckBox {
    id: control
    text: qsTr("CheckBox")
    checked: true

    property alias innerText: text.text
    property string activeColor: "#98c379"
    property string disabledColor: "#833b3b"

    property string indicatorActiveColor: "#98c379"
    property string indicatorDisabledColor: "#833b3b"

    indicator: Rectangle {
        id: circle
        width: 8
        height: 8
        y: 12
        radius: height / 2
        color: control.checked ? indicatorActiveColor : indicatorDisabledColor
    }

    contentItem: Text {
        id: text
        leftPadding: circle.width + 2
        color: control.checked ? activeColor : disabledColor
        text: "Text"
        font.letterSpacing: -0.5
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.italic: false
        font.weight: Font.Normal
        font.family: "Golos UI VF"
        renderType: Text.QtRendering
        minimumPointSize: 12
        minimumPixelSize: 12


    }
}
