import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11
import Qt.labs.calendar 1.0
Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    RowLayout {
        x: 28
        y: 25

        Text {
            id: text1
            text: "Monkey Number"
            font.pixelSize: 12
            Layout.preferredHeight: 40
            Layout.preferredWidth: 154
        }

        TextEdit {
            id: textEdit
            opacity: 0.432
            text: "number"
            font.pixelSize: 12
            Layout.preferredHeight: 40
            Layout.preferredWidth: 80
        }

        Text {
            id: text2
            text: qsTr("Number")
            font.pixelSize: 12
            Layout.preferredHeight: 40
            Layout.preferredWidth: 70
        }

        TextEdit {
            id: textEdit1
            opacity: 0.245
            text: qsTr("Text Edit")
            font.pixelSize: 12
            Layout.preferredHeight: 44
            Layout.preferredWidth: 102
        }

        RoundButton {
            id: button
            text: qsTr("Start")
            highlighted: false
            clip: true
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
