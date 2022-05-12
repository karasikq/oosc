import QtQuick 2.14
import OOSC 1.0
import QtQuick.Layouts 1.12
import "../"

SubGeneratorKnobs {
    id: control
    width: 250
    height: 140

    property var knobSize: 35.0

    panKnob: oscPanKnob
    gainKnob: oscGainKnob
    shapeKnob: oscShapeKnob

    function connectLfoAction(knob, drag) {
        if (drag.source.lfoController) {
            knob.connectLfo(drag.source.lfoController)
        }
    }

        ColumnLayout {
            id: topKnobs
            x: (control.width - width) / 2
            spacing: 0

            Text {
                Layout.alignment: Qt.AlignHCenter
                color: "#575757"
                text: "- osc -"
                width: topKnobs.width
                font.pixelSize: ScaleControl.scaleY(12)
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            RowLayout {
                spacing: 15 * ScaleControl.scaleFactorX
                height: ScaleControl.scaleY(50) 
                layoutDirection: Qt.LeftToRight

                Item {
                    width: control.knobSize * ScaleControl.scaleFactorX
                    height: 50 * ScaleControl.scaleFactorY
                    Layout.preferredWidth: width
                    Layout.preferredHeight: height
                    AbstractKnob {
                        id: oscPanKnob
                        width: parent.width
                        height: width
                        knobTitle: "Pan"

                        function dropAction(drag) {
                            control.connectLfoAction(this, drag)
                        }
                    }
                }

                Item {
                    width: control.knobSize * ScaleControl.scaleFactorX
                    height: 50 * ScaleControl.scaleFactorY
                    Layout.preferredWidth: width
                    Layout.preferredHeight: height
                    AbstractKnob {
                        id: oscGainKnob
                        width: parent.width
                        height: width
                        knobTitle: "Gain"

                        function dropAction(drag) {
                            control.connectLfoAction(this, drag)
                        }
                    }
                }

                Item {
                    width: control.knobSize * ScaleControl.scaleFactorX
                    height: 50 * ScaleControl.scaleFactorY
                    Layout.preferredWidth: width
                    Layout.preferredHeight: height
                    AbstractKnob {
                        id: oscShapeKnob
                        width: parent.width
                        height: width
                        knobTitle: "Shape"

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
    D{i:0;formeditorZoom:2}D{i:4}D{i:3}D{i:6}D{i:5}D{i:8}D{i:7}D{i:2}D{i:11}D{i:10}D{i:13}
D{i:12}D{i:15}D{i:14}D{i:17}D{i:16}D{i:9}D{i:1}
}
##^##*/

