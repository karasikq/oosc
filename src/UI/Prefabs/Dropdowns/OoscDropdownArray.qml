import QtQuick 2.10
import QtQuick.Controls 2.5
import OOSC 1.0
import Qt.labs.folderlistmodel 2.15
import "../"

ComboBox {
    id: control
    width: 140
    height: 40
    model: []

    delegate: ItemDelegate {
        id: controlItemDelegate
        width: control.width
        contentItem: Text {
            text: modelData
            color: "#fff"
            font: control.font
            elide: Text.ElideMiddle
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        background: Rectangle {
            color: controlItemDelegate.highlighted ? ColorScheme.currentScheme.Dropdown.highlightedColor : ColorScheme.currentScheme.Dropdown.itemColor
        }
        highlighted: control.highlightedIndex === index
    }

    indicator: Canvas {
        id: canvas
        x: control.width - width - control.rightPadding
        y: control.topPadding + (control.availableHeight - height) / 2
        width: 12
        height: 8
        contextType: "2d"

        Connections {
            target: control
            function onPressedChanged() {
                canvas.requestPaint()
            }
        }

        onPaint: {
            context.reset()
            context.moveTo(0, 0)
            context.lineTo(width, 0)
            context.lineTo(width / 2, height)
            context.closePath()
            context.fillStyle = control.pressed ? "#fff" : "#fff"
            context.fill()
        }
    }

    contentItem: Text {
        leftPadding: 12
        text: control.displayText
        color: control.pressed ? "#fff" : "#fff"
        font.letterSpacing: 1.0
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.weight: Font.Normal
        font.family: "Golos UI VF"
        font.italic: true
        renderType: Text.QtRendering
        minimumPointSize: 12
        minimumPixelSize: 12
    }

    background: Rectangle {
        implicitWidth: control.width
        implicitHeight: control.height
        color: "#00000000"
    }

    popup: Popup {
        y: control.height - 1
        width: control.width
        implicitHeight: contentItem.implicitHeight - control.height
        padding: 1

        contentItem: ListView {
            clip: true
            implicitHeight: 250
            model: control.popup.visible ? control.delegateModel : null
            currentIndex: control.highlightedIndex
            ScrollIndicator.vertical: ScrollIndicator {}
        }

        background: Rectangle {
            color: ColorScheme.currentScheme.DefaultBlock.background
            border.color: ColorScheme.currentScheme.DefaultBlock.borderColor
            radius: 2
        }
    }
}
