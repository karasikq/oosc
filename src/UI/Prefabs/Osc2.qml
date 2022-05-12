import QtQuick 2.12
import OOSC 1.0
import "./OscKnobs"
import "./OoscComponents"

OscRectangleBlock {
    id: controls
    width: 250
    height: 300
    headerText: "OSC B"

    property GeneratorControl generatorControl: synth1generator2
    property alias adsrController: synth1generator2.adsrController

    GeneratorControl {
        id: synth1generator2
        objectName: "synth1generator2"
        generatorID: 1
        wavetableDrawer: osc2WavetableDrawer

        Component.onCompleted: {
            oscBControlKnobs.attachKnobs()
            octKnob.changeableParametr = synth1generator2.octaveOffset
            semKnob.changeableParametr = synth1generator2.semitoneOffset
            cenKnob.changeableParametr = synth1generator2.cents
        }
    }

    Rectangle {
        x: 5
        y: 5
        width: 20
        height: 20
        color: "#00000000"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                wtLoader.setSource(
                            "qrc:/src/UI/Prefabs/Oscs/WavetableLoadView.qml")
                wtLoader.visible = true
                content.visible = false
            }
        }
    }

    Loader {
        id: wtLoader
        source: "qrc:/src/UI/Prefabs/Oscs/WavetableLoadView.qml"
        visible: false

        Connections {
            target: wtLoader.item
            onLoadWavetableAndExit: {
                synth1generator2.loadWavetableFromFileUrl(fileUrl)
                wtLoader.visible = false
                content.visible = true
            }
        }
    }

    Item {
        id: content
        anchors.fill: parent
        Row {
            id: postHeader
            x: (parent.width - width) / 2
            y: 30
            height: 25
            spacing: 45

            Text {
                id: octText
                width: 30
                color: "#575757"
                text: qsTr("oct")
                font.pixelSize: 12
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
                width: 30
                color: "#575757"
                text: qsTr("sem")
                font.pixelSize: 12
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
                width: 30
                color: "#575757"
                text: qsTr("cen")
                font.pixelSize: 12
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
            x: 10
            y: 55
            width: parent.width - 20
            height: 100

            OoscWavetable {
                id: osc2WavetableDrawer
                width: parent.width
                height: 80
                anchors.left: parent.left
                anchors.leftMargin: 0
                lineColor: ColorScheme.currentScheme.ArrayDrawer.lineColor
                backgroundColor: ColorScheme.currentScheme.ArrayDrawer.backgroundColor
                centerLineColor: ColorScheme.currentScheme.ArrayDrawer.centerLineColor
                z: 10
            }
        }

        OscKnobs {
            id: oscBControlKnobs
            y: 140
            clip: false
            generatorControl: synth1generator2
            objectName: "oscBKnobs"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.5;height:480;width:640}D{i:2}D{i:1}
}
##^##*/
