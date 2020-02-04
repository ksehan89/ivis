import QtQuick 2.0

Item {
    property int myIndex: 0
    onMyIndexChanged: {
        console.log("inner onMyIndexChanged: ", myIndex)
    }

    id: container
    property alias cellColor: rectangle.color
    signal clicked(cellColor: color)

    width: 100; height: 100

    Rectangle {
        id: rectangle
        anchors.fill: parent
    }

    MouseArea {
        anchors.fill: parent
        onClicked: container.clicked(container.cellColor)
    }




//    property bool select_r1: false

//    Rectangle {
//        width: 100
//        height: 100
//        color: {
//            //if ()
//        }

//        Text {
//            anchors.fill: parent
//            horizontalAlignment: Text.AlignHCenter
//            verticalAlignment: Text.AlignVCenter
//            text: {

//                if (true == customComponent2.select_r1) {
//                    "Rect1\nColor: "
//                }
//            }
//        }
//    }

}
