pragma Singleton
import QtQuick 2.12
import OOSC 1.0

Item {
    id: synthThemeController
    objectName: "synthThemeController"

    property var currentScheme: ({})

    FileIO {
        id: themeFile
        source: ":/resources/json/defaultTheme.json"
    }

    Component.onCompleted: {
        var out = themeFile.read()
        synthThemeController.currentScheme = JSON.parse(out).theme
    }
}
