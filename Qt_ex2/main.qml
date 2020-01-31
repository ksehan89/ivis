import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id : rect1
        width: 100
        height: 100
        color: "red"
    }

    Rectangle {
        id : rect2
        //x : rect1.x + 200
        anchors.left: rect1.right
        //y : rect1.y + 200
        width: 100
        height: 100
        color: "blue"
    }
}
