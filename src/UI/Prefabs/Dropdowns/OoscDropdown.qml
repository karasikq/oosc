import QtQuick 2.10
import QtQuick.Controls 2.5
import OOSC 1.0
import Qt.labs.folderlistmodel 2.15

ComboBox {
    id: control
    width:  140
    height: 40
    model: []
    displayText: "Choose"

    delegate: ItemDelegate {
        id: controlItemDelegate
        width: control.width
        contentItem: Text {
            text: fileName
            color: "#fff"
            font: control.font
            elide: Text.ElideMiddle
            verticalAlignment: Text.AlignVCenter
        }
        background: Rectangle {
            color: controlItemDelegate.highlighted ? "#212730" : "#191d24"
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
            function onPressedChanged() { canvas.requestPaint(); }
        }

        onPaint: {
            context.reset();
            context.moveTo(0, 0);
            context.lineTo(width, 0);
            context.lineTo(width / 2, height);
            context.closePath();
            context.fillStyle = control.pressed ? "#fff" : "#fff";
            context.fill();
        }
    }

    contentItem: Text {
        leftPadding: 10
        rightPadding: 30
        text: control.currentIndex > -1 ? control.model.get(control.currentIndex, control.textRole) : control.displayText
        font: control.font
        color: control.pressed ? "#fff" : "#fff"
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideMiddle
    }

    background: Rectangle {
        implicitWidth: control.width
        implicitHeight: control.height
        color: "#191d24"
        border.color: "#ff8640"
        border.width: control.visualFocus ? 2 : 1
        radius: 2
    }

    popup: Popup {
        y: control.height - 1
        width: control.width
        implicitHeight: contentItem.implicitHeight
        padding: 1

        contentItem: ListView {
            clip: true
            implicitHeight: 250
            model: control.popup.visible ? control.delegateModel : null
            currentIndex: control.highlightedIndex
            ScrollIndicator.vertical: ScrollIndicator { }

        }

        background: Rectangle {
            color: "#191d24"
            border.color: "#ff8640"
            radius: 2
        }
    }
}
