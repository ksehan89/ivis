import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        width: 600
        height: 300
        color: "skyblue"
        ListView {
            anchors.fill: parent
            model:TestListModel
            delegate: Text { text: "id : " + id + "\tlabel : " + label + "\tisEnable : " + isEnable}
        }
    }
}
