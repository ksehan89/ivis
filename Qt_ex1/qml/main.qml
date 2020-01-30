import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    //id: root
    visible: true
    width: 1920
    height: 720
    title: qsTr("Hello World")


//    Item {
//        id:guideLine
//        width: 100
//        height: 100
//        //anchors.centerIn: root
//    }

//    Rectangle{
//        id:rectBG
//        width: 90
//        height: 90
//        anchors.centerIn: guideLine
//        color: "red"
//    }

//    Rectangle{
//        id:target
//        width: 100
//        height: 100
//        anchors.centerIn: guideLine
//        color: "blue"
//        scale: 0.9
//        opacity: 0.3

//    }
    CustomPopupBG {
    id:root
        Rectangle {
//            id: popup_bg
////            width: 100
////            height: 100
//            x : 500
//            y : 500

        }

        Rectangle {
            id: test
//            x: popup_bg3.x + 300
//            y: 400
            width: 300
            height: 300
            color: "red"
            anchors.right: root.temp.right
        }

        Rectangle {
            id: test2
            width: 100
            height: 100
            color: "yellow"
            anchors.right: test.right
            anchors.top: test.top

        }
    }





}
