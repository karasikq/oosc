import QtQuick 2.10
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.15
import OOSC 1.0
import "../"
import "../Forms"
import "../Dropdowns"
import "../OoscComponents"
import Qt.labs.folderlistmodel 2.15

DefaultBlock {
    id: control

    signal loadMidiAndExit(string fileUrl)
    signal exit()

    Item {
        anchors.fill: parent
        anchors.margins: ScaleControl.scaleY(20)
        anchors.verticalCenter: parent.verticalCenter
        Item {
            id: packageContent
            width: parent.width / 3 - ScaleControl.scaleX(20)

            Text {
                id: packageText
                width: parent.width
                verticalAlignment: Text.AlignVCenter
                color: "#ffffff"
                text: qsTr("Package")
                font.pixelSize: 16
                horizontalAlignment: Text.AlignHCenter
            }

            OoscDropdown {
                id: packageDropdown
                anchors.top: packageText.bottom
                anchors.topMargin: ScaleControl.scaleY(10)
                width: parent.width
                height: 40
                textRole: "fileName"
                displayText:  "Select package..."

                model: FolderListModel {
                    id: folderModel
                    showFiles: false
                    folder: "file://" + ApplicationConfig.getConfigParametr("MidiDataPath")

                    onStatusChanged: { if (folderModel.status == FolderListModel.Ready) {
                                         packageDropdown.currentIndex = 0
                                         packageDropdown.updateMidiModel()
                                     }
                                     }
                }

                Connections {
                    target: packageDropdown
                    function onActivated() {
                        packageDropdown.updateMidiModel()
                    }
                }


                function updateMidiModel() {
                    midiModel.showFiles = true
                    midiModel.folder = "file://" + ApplicationConfig.getConfigParametr("MidiDataPath") + "/" + packageDropdown.model.get(packageDropdown.currentIndex, "fileName")
                }
            }
        }
        Item {
            id: midiContent
            width: parent.width / 3 - ScaleControl.scaleX(20)
            anchors.left: packageContent.right
            anchors.leftMargin: ScaleControl.scaleX(30);
            Text {
                id: contentText
                width: parent.width
                color: "#ffffff"
                text: qsTr("Midi")
                font.pixelSize: 16
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            OoscDropdown {
                id: midiDropdown
                width: parent.width
                height: 40
                anchors.top: contentText.bottom
                anchors.topMargin: ScaleControl.scaleY(10)
                textRole: "fileName"
                displayText: "Select midi..."

                model: FolderListModel {
                    id: midiModel
                    showFiles: false
                    showDirs: false

                    onStatusChanged: { if (midiModel.status == FolderListModel.Ready) {
                                         midiDropdown.currentIndex = -1
                    }
                    }
                }
            }

            OoscTextField {
                id: midiSearchField
                width: parent.width
                anchors.left: midiDropdown.left
                anchors.top: midiDropdown.bottom
                anchors.topMargin: ScaleControl.scaleY(10)

                placeholderText: "Search"
                placeholderTextColor: "#888888"

                Connections {
                    target: midiSearchField
                    function onAccepted() {
                        midiDropdown.currentIndex = midiDropdown.find(midiSearchField.text, Qt.MatchContains)
                    }
                }
            }
        }
        Item {
            width: parent.width / 3 - ScaleControl.scaleX(20)
            height: 40
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: midiContent.right
            anchors.leftMargin: ScaleControl.scaleX(30);
            OoscButton {
                id: button
                anchors.fill: parent
                text: qsTr("Apply")

                Connections {
                    target: button
                    function onClicked() {
                        control.loadMidiAndExit(midiDropdown.model.get(midiDropdown.currentIndex, "fileUrl"))
                    }
                }
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
