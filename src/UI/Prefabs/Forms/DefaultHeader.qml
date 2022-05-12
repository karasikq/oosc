import QtQuick 2.0
import "../"

Item {
    id: header
    width: parent.width
    height: 35
    property string headerText: "HEADER"

    Text {
        id: text9
        color: "#ffffff"
        text: qsTr(headerText)
        anchors.fill: parent
        font.letterSpacing: 1.0
        font.pixelSize: ScaleControl.scaleY(14)
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.italic: true
        font.bold: false
        font.weight: Font.Normal
        font.family: "Golos UI VF"
        renderType: Text.QtRendering
        minimumPointSize: 12
        minimumPixelSize: 12
    }

//    Image {
//        id: image4
//        x: 8
//        y: 7.5
//        width: 20
//        height: 20
//        anchors.right: parent.right
//        source: "qrc:/resources/images/enable.png"
//        fillMode: Image.PreserveAspectFit
//        anchors.rightMargin: 10
//    }
}
