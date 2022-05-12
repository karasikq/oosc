import QtQuick 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls 2.5
import OOSC 1.0
import "../"
import "../Dropdowns"
import "../OoscComponents"
import Qt.labs.folderlistmodel 2.15

Item {
    id: control

    signal loadWavetableAndExit(string fileUrl)
    signal exit()

    ColumnLayout {
        anchors.fill: parent
        spacing: ScaleControl.scaleY(10)
        ColumnLayout {
            id: packageContent
            Layout.fillWidth: true
            spacing: ScaleControl.scaleY(10)

            Text {
                id: packageText
                Layout.fillWidth: true
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                text: qsTr("Package")
                font.pixelSize: 16
                horizontalAlignment: Text.AlignHCenter
            }

            OoscDropdown {
                id: packageDropdown
                Layout.fillWidth: true
                height: ScaleControl.scaleY(40)
                textRole: "fileName"
                displayText:  "Select package..."

                model: FolderListModel {
                    id: folderModel
                    showFiles: false
                    folder: "file://" + ApplicationConfig.getConfigParametr("WavetablesDataPath")

                    onStatusChanged: if (folderModel.status == FolderListModel.Ready) {
                                         packageDropdown.currentIndex = 0
                                         packageDropdown.updateModel()
                                     }
                }

                onActivated: event => {
                    packageDropdown.updateModel()
                }

                function updateModel() {
                    midiModel.showFiles = true
                    midiModel.folder = "file://" + ApplicationConfig.getConfigParametr("WavetablesDataPath") + "/" + packageDropdown.model.get(packageDropdown.currentIndex, "fileName")
                }
            }
        }

        ColumnLayout {
            id: midiContent
            Layout.fillWidth: true
            spacing: ScaleControl.scaleY(10)

            Text {
                id: midiText
                Layout.fillWidth: true
                color: "#ffffff"
                text: qsTr("Midi")
                font.pixelSize: 16
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            OoscDropdown {
                id: midiDropdown
                Layout.fillWidth: true
                height: ScaleControl.scaleY(40)
                textRole: "fileName"
                displayText: "Select wavetable..."

                model: FolderListModel {
                    id: midiModel
                    showFiles: false
                    showDirs: false

                    onStatusChanged: if (midiModel.status == FolderListModel.Ready) {
                                         midiDropdown.currentIndex = -1
                    }
                }
            }

            OoscTextField {
                id: midiSearchField

                placeholderText: "Search"
                placeholderTextColor: "#888888"

                onAccepted: event => {
                    midiDropdown.currentIndex = midiDropdown.find(midiSearchField.text, Qt.MatchContains)
                }
            }

        }

        OoscButton {
            id: button
            x: 80
            y: control.headerHeight + 210
            width: 90
            height: 30
            text: qsTr("Apply")

            onClicked: event => {
                    control.loadWavetableAndExit(midiDropdown.model.get(midiDropdown.currentIndex, "fileUrl"))
            }

        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33}D{i:2}D{i:5}D{i:3}D{i:1}D{i:7}D{i:9}D{i:8}D{i:10}D{i:6}
D{i:13}D{i:12}
}
##^##*/
