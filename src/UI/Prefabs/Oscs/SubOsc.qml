import QtQuick 2.12
import OOSC 1.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "../OscKnobs"
import "../"
import "../OoscComponents"

OscRectangleBlock {
    id: controls
    width: 180
    height: 300
    headerText: "SUB"
    headerHeight: ScaleControl.scaleY(30)

    property SubGeneratorControl generatorControl: synth1generator3
    property alias adsrController: synth1generator3.adsrController

    SubGeneratorControl {
        id: synth1generator3
        objectName: "synth1generator3"
        generatorID: 2
        wavetableDrawer: waveDrawer

        Component.onCompleted: {
            subKnobs.attachKnobs()
            synth1generator3.bypass = true
            octKnob.changeableParametr = synth1generator3.octaveOffset
        }
    }

    Item {
        id: content
        anchors.fill: parent

        Item {
            id: waveBlock
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: ScaleControl.scaleX(10) 
            anchors.rightMargin: ScaleControl.scaleX(10)
            anchors.topMargin: ScaleControl.scaleY(55)
            height: ScaleControl.scaleY(80)

            OoscWavetable {
                id: waveDrawer
                anchors.fill: parent
                lineColor: ColorScheme.currentScheme.ArrayDrawer.lineColor
                backgroundColor: ColorScheme.currentScheme.ArrayDrawer.backgroundColor
                centerLineColor: ColorScheme.currentScheme.ArrayDrawer.centerLineColor
                z: 10
            }
        }

        Item {
            id: octBlock
            anchors.top: waveBlock.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.topMargin: ScaleControl.scaleY(30)
            height: ScaleControl.scaleY(40)

            Text {
                id: oct
                color: "#575757"
                anchors.horizontalCenter: parent.horizontalCenter
                text: "OCTAVE"
                font.pixelSize: ScaleControl.scaleY(20)
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.italic: true
                font.family: "Golos UI VF"

                ATextKnob {
                    id: octKnob
                    anchors.fill: parent
                    Connections {
                        target: octKnob
                        function onValueChanged(value) {
                            oct.text = "OCTAVE " + Math.round(value).toFixed(0)
                        }
                    }
                }
            }

            Image {
                id: name
                anchors.left: oct.right
                anchors.verticalCenter: oct.verticalCenter
                width: ScaleControl.scaleX(20)
                height: width
                source: "qrc:/resources/images/up_down.png"
            }

        }

        SubOscKnobs {
            id: subKnobs
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: octBlock.bottom
            anchors.topMargin: ScaleControl.scaleY(5)
            generatorControl: synth1generator3
            objectName: "subKnobs"
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}D{i:1}D{i:3}D{i:2}D{i:5}D{i:4}D{i:6}
}
##^##*/

