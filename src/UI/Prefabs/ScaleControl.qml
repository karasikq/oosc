pragma Singleton
import QtQuick 2.12

Item {
    property var scaleFactorX: 1.0
    property var scaleFactorY: 1.0

    function scaleX(value) {
        return value * scaleFactorX;
    }

    function scaleY(value) {
        return value * scaleFactorY;
    }
}
