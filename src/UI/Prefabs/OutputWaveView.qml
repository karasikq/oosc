import QtQuick 2.10
import QtQuick.Controls 2.5
import OOSC 1.0
import "./"
import "./Forms"

Item {
    id: synthOutputView
    width: 250
    height: 250

    property LinearIndicator volumeIndocatorLeft : volIndicatorLeft
    property LinearIndicator volumeIndocatorRight : volIndicatorRight

    property var leftWavetable: leftWaveView
    property var rightWavetable: rightWaveView

    Item {
        id: leftView
        width: parent.width
        height: ScaleControl.scaleY(100)

        OoscWavetable {
            id: leftWaveView
            anchors.fill: parent
            anchors.leftMargin: ScaleControl.scaleX(20)
            anchors.rightMargin: ScaleControl.scaleX(20) 
            anchors.topMargin: ScaleControl.scaleY(20) 
            objectName: "outputWaveLeft"
            centerLineColor: "#00000000"
            lineColor: ColorScheme.currentScheme.ArrayDrawer.lineColor
            drawGradient: false
            z: 10

//            Component.onCompleted: {
//                var gradientStops = []
//                function Stop(position, color) {
//                    this.position = position;
//                    this.color = color
//                }
//                gradientStops[0] = new Stop(0.0, "#00ff8640")
//                gradientStops[1] = new Stop(0.5, "#ff8640")
//                gradientStops[2] = new Stop(1.0, "#00ff8640")
//                leftWaveView.setLineGradient(gradientStops)
//            }

            Text {
                color: "#55575757"
                text: "+1L"
                anchors.top: parent.top
                anchors.right: parent.right
                font.pixelSize: ScaleControl.scaleY(12) 
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                color: "#55575757"
                text: "-1L"
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                font.pixelSize: ScaleControl.scaleY(12)
                verticalAlignment: Text.AlignVCenter
            }

            LinearIndicator {
                id: volIndicatorLeft
                anchors.right: parent.right
                anchors.rightMargin: ScaleControl.scaleX(-10)
                width: 1
                height: parent.height
                backgroundColor: ColorScheme.currentScheme.VolumeIndicator.background
                foregroundColor: ColorScheme.currentScheme.VolumeIndicator.max
                function setGradient() {
                    var gradientStops = []
                    function Stop(position, color) {
                        this.position = position;
                        this.color = color
                    }
                    gradientStops[0] = new Stop(0.3, ColorScheme.currentScheme.VolumeIndicator.max)
                    gradientStops[1] = new Stop(0.5, ColorScheme.currentScheme.VolumeIndicator.min)
                    gradientStops[2] = new Stop(0.7, ColorScheme.currentScheme.VolumeIndicator.max)
                    return gradientStops;
                }
            }
        }
    }

    Item {
        id: rightView
        width: parent.width
        height: ScaleControl.scaleY(100)
        anchors.top: leftView.bottom

        OoscWavetable {
            id: rightWaveView
            anchors.fill: parent
            anchors.leftMargin: ScaleControl.scaleX(20)
            anchors.rightMargin: ScaleControl.scaleX(20) 
            anchors.topMargin: ScaleControl.scaleY(20) 
//            Component.onCompleted: {
//                    var gradientStops = []
//                    function Stop(position, color) {
//                        this.position = position;
//                        this.color = color
//                    }
//                    gradientStops[0] = new Stop(0.0, "#ff8640")
//                    gradientStops[1] = new Stop(0.5, "#ff8640")
//                    gradientStops[2] = new Stop(1.0, "#ff8640")
//                    rightWaveView.setLineGradient(gradientStops)
//                }
            centerLineColor: "#00000000"
            lineColor: ColorScheme.currentScheme.ArrayDrawer.lineColor
            objectName: "outputWaveRight"
            drawGradient: false
            z: 10

            Text {
                color: "#55575757"
                text: "+1R"
                anchors.top: parent.top
                anchors.right: parent.right
                font.pixelSize: ScaleControl.scaleY(12) 
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                color: "#55575757"
                text: "-1R"
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                font.pixelSize: ScaleControl.scaleY(12)
                verticalAlignment: Text.AlignVCenter
            }

            LinearIndicator {
                id: volIndicatorRight
                anchors.right: parent.right
                anchors.rightMargin: ScaleControl.scaleX(-10)
                width: 1
                height: parent.height
                backgroundColor: ColorScheme.currentScheme.VolumeIndicator.background
                foregroundColor: ColorScheme.currentScheme.VolumeIndicator.max
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33}D{i:2}D{i:3}D{i:1}D{i:5}D{i:6}D{i:4}
}
##^##*/
