import QtQuick 2.0

import "./Forms"

DefaultBlock {
    property alias headerText: header.headerText
    property int headerHeight: 35
    DefaultHeader {
        id: header
        width: parent.width
        height: headerHeight
    }
}
