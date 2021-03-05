import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Image Viewer")

    Image{
        id:image
        focus: true
        source: 'qrc:/image/ee.jpg'
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }
}
