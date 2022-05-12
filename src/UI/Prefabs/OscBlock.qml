import QtQuick 2.12
import OOSC 1.0
import QtQuick.Layouts 1.15
import "./OscKnobs"
import "./Oscs"
import "./OoscComponents"

OscRectangleBlock {
    id: controls
    width: 250
    height: 300
    headerText: "OSC A"
    headerHeight: ScaleControl.scaleY(30)

    property GeneratorControl generatorControl
    property OscKnobs knobsControl: oscKnobsControl 
    property OoscWavetable wavetableControl: oscWavetableDrawer

    property var octControl: octKnob  
    property var semControl: semKnob  
    property var cenControl: cenKnob  

    Rectangle {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: ScaleControl.scaleX(10)
        anchors.topMargin: ScaleControl.scaleY(5)
        width: 20
        height: 20
        color: "#00000000"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                wavetableView.visible = true
                content.visible = false
            }
        }

        Image {
            anchors.fill: parent
            source: "qrc:/resources/images/open_folder.png"
            mipmap: true
        }
    }

    WavetableLoadView {
        id: wavetableView
        anchors.fill: parent
        visible: false

        onLoadWavetableAndExit: fileUrl => {
            generatorControl.loadWavetableFromFileUrl(fileUrl)
            wavetableView.visible = false
            content.visible = true
        }
    }

    Item {
        id: content
        anchors.fill: parent

        Row {
            id: postHeader
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: controls.headerHeight
            height: ScaleControl.scaleY(25)
            spacing: ScaleControl.scaleX(40)

            Text {
                id: octText
                width: ScaleControl.scaleX(30)
                color: "#575757"
                text: qsTr("oct")
                font.pixelSize:ScaleControl.scaleY(12) 
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                ATextKnob {
                    id: octKnob
                    Connections {
                        target: octKnob
                        function onValueChanged(value) {
                            octText.text = "oct " + Math.round(value).toFixed(0)
                        }
                    }
                }
            }

            Text {
                id: semText
                width: ScaleControl.scaleX(30)
                color: "#575757"
                text: qsTr("sem")
                font.pixelSize:ScaleControl.scaleY(12) 
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                ATextKnob {
                    id: semKnob
                    Connections {
                        target: semKnob
                        function onValueChanged(value) {
                            semText.text = "sem " + Math.round(value).toFixed(0)
                        }
                    }
                }
            }

            Text {
                id: cenText
                width: ScaleControl.scaleX(30)
                color: "#575757"
                text: qsTr("cen")
                font.pixelSize:ScaleControl.scaleY(12) 
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                ATextKnob {
                    id: cenKnob
                    Connections {
                        target: cenKnob
                        function onValueChanged(value) {
                            cenText.text = "cen " + Math.round(value).toFixed(0)
                        }
                    }
                }
            }
        }

        Item {
            id: wavetableBlock
            anchors.top: postHeader.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: ScaleControl.scaleX(10)
            anchors.rightMargin:ScaleControl.scaleY(10) 
            height: ScaleControl.scaleY(80)

            OoscWavetable {
                id: oscWavetableDrawer
                anchors.fill: parent
                lineColor: ColorScheme.currentScheme.ArrayDrawer.lineColor
                backgroundColor: ColorScheme.currentScheme.ArrayDrawer.backgroundColor
                centerLineColor: ColorScheme.currentScheme.ArrayDrawer.centerLineColor
                z: 10
            }
        }

        OscKnobs {
            id: oscKnobsControl
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: wavetableBlock.bottom
            anchors.topMargin: ScaleControl.scaleY(10)
            clip: false
            generatorControl: controls.generatorControl
            objectName: "oscAKnobs"
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}D{i:1}D{i:3}D{i:2}D{i:5}D{i:4}D{i:6}
}
##^##*/

