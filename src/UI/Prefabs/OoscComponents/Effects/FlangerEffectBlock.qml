import QtQuick 2.0
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../../"
import "../"

EffectPrefab {
    id: control
    effect: effect.effect
    title: "FLANGER"

    FlangerEffect {
        id: effect
        width: parent.width
        height: parent.height
            Item {
                id: textKnobs
                width: control.width
                height: 22
                y: 50
                Text {
                    id: invText
                    width: parent.width / 3
                    color: "#575757"
                    text: "Forward"
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.italic: true
                    font.family: "Golos UI VF"

                    ATextKnob {
                        width: parent.width
                        height: parent.height
                        changeableParametr: effect.invertedMode
                        function valueChangedAction(value) {
                            invText.text = Math.round(value) === 0 ? "Forward" : "Inverted"
                        }
                    }
                }

                Text {
                    id: intText
                    width: parent.width / 3
                    anchors.left: invText.right
                    color: "#575757"
                    text: "Nearest"
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.italic: true
                    font.family: "Golos UI VF"

                    ATextKnob {
                        width: parent.width
                        height: parent.height
                        changeableParametr: effect.interpolation
                        function valueChangedAction(value) {
                            intText.text = effect.interpolationToString(value) 
                        }
                    }
                }

                Text {
                    id: shapeText
                    width: parent.width / 3
                    anchors.left: intText.right
                    color: "#575757"
                    text: "Sin"
                    font.pixelSize: 14
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    font.italic: true
                    font.family: "Golos UI VF"

                    ATextKnob {
                        width: parent.width
                        height: parent.height
                        changeableParametr: effect.lfoShape

                        function valueChangedAction(value) {
                            shapeText.text = effect.lfoShapeToString(value) 
                        }
                    }
                }

            }
        ColumnLayout {
            id: topKnobs
            anchors.top: textKnobs.bottom
            anchors.horizontalCenter: parent.horizontalCenter 
            height: 50
            spacing: 20

            RowLayout {
                spacing: 15
                Layout.alignment: Qt.AlignHCenter
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Delay"
                    changeableParametr: effect.delay

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Width"
                    changeableParametr: effect.flangerWidth

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }

            }

            RowLayout {
                spacing: 15
                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Frequency"
                    changeableParametr: effect.lfoFrequency

                    function dropAction(drag) {
                        control.connectSender(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Depth"
                    changeableParametr: effect.depth

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }

                AbstractKnob {
                    width: 55
                    height: 55
                    pinRadius: 3
                    outerStroke: 5
                    knobTitle: "Feedback"
                    changeableParametr: effect.feedback

                    function dropAction(drag) {
                        control.connectLfoAction(this, drag)
                    }
                }

            }

        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}D{i:1}D{i:5}D{i:6}D{i:7}D{i:4}D{i:3}D{i:2}
}
##^##*/

