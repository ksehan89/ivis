import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // Model View Delegate
    // ==========================================================================================
    // Qt Quick에서는 데이터가 모델 뷰 분리를 통해 프레젠테이션과 분리된다.
    // 각 view 마다, 데이터 요소의 시각화가 Delegate(대리자)로 분리된다.
    // Model: data, View + Delegate:
    // 각 항목에 대해 인스턴스화되는 repeater의 내용은 실제로 기본 특성인 delegate에 바인드 된다.
    // ==========================================================================================


    Item  {
        // 세로
//        width: 80
//        height: 300
        // 가로
//        width: 480
//        height: 80
//        color: "lightgray"
        width: 240
        height: 300

        ListView {
            id: view
            anchors.fill: parent
            anchors.margins: 20

            clip: true

            model: 100

            //orientation: ListView.Horizontal    //세로에서 가로로 전환시에
            //layoutDirection: Qt.RightToLeft     //수평방향 바꿀때 사용.

            delegate: numberDelegate
            spacing: 5

            highlight: highlightComponent
            //highlightFollowsCurrentItem: false
            focus: true
        }

        Component {
            id: highlightComponent
            Rectangle {
                width: ListView.view.width
                color: "green"
                //width: 200
//                height: 40
//                opacity: 0.8
//                y: view.currentItem.y
//                Behavior on y {
//                    SpringAnimation {
//                        spring: 3
//                        damping: 0.7
//                    }
//                }

            }
        }

        Component {
            id: numberDelegate
            Item {                              // 이 구간 Item 과 Rectangle 차이는?
                //width: 40
                width: ListView.view.width
                height: 40
                //color: "green"
                //opacity: 0.7
                Text {
                    anchors.centerIn: parent
//                    anchors.fill: parent
//                    horizontalAlignment: Text.AlignHCenter
//                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
//                    //color: "white"
                    text: index

                }
            }
        }
    }


////----------------------------------------------------------------------------------------------------

////    // Model View 분리 (Delegate 사용)
////    ListModel {
////        id: model1
////        ListElement { name: "Mercury"; surfaceColor: "gray" }
////        ListElement { name: "Venus"; surfaceColor: "yellow" }
////        ListElement { name: "Earth"; surfaceColor: "blue" }
////        ListElement { name: "Mars"; surfaceColor: "orange" }
////        ListElement { name: "Jupiter"; surfaceColor: "orange" }
////        ListElement { name: "Saturn"; surfaceColor: "yellow" }
////        ListElement { name: "Uranus"; surfaceColor: "lightBlue" }
////        ListElement { name: "Neptune"; surfaceColor: "lightBlue" }
////    }

////    Component {
////        id: contactDelegate
////        Rectangle {
////            width: 120
////            height: 32
////            color: {
////                if (index%2 == 1) {
////                    "green"
////                } else {
////                    "red"
////                }
////            }
////            Text {
////                anchors.fill: parent
////                horizontalAlignment: Text.AlignHCenter
////                verticalAlignment: Text.AlignVCenter
////                //text: index
////                //text: modelData + '(' + index + ')'
////                text: name
////            }
////            Rectangle {
////                anchors.left: parent.left
////                anchors.verticalCenter: parent.verticalCenter
////                anchors.leftMargin: 5

////                width: 16
////                height: 16
////                radius: 8
////                color: surfaceColor
////            }
////        }
////    }

////    ListView {
////        anchors.fill: parent
////        model: model1
////        delegate: contactDelegate
////    }

////----------------------------------------------------------------------------------------------------

////    Column {
////        spacing: 2

////        Repeater {
////            //model: 10
////            //model: ["Enterprise", "Columbia", "Challenger", "Discovery", "Endeavour", "Atlantis"]
////            model: ListModel {
////                ListElement { name: "Mercury"; surfaceColor: "gray" }
////                ListElement { name: "Venus"; surfaceColor: "yellow" }
////                ListElement { name: "Earth"; surfaceColor: "blue" }
////                ListElement { name: "Mars"; surfaceColor: "orange" }
////                ListElement { name: "Jupiter"; surfaceColor: "orange" }
////                ListElement { name: "Saturn"; surfaceColor: "yellow" }
////                ListElement { name: "Uranus"; surfaceColor: "lightBlue" }
////                ListElement { name: "Neptune"; surfaceColor: "lightBlue" }
////            }

////            Rectangle{
////                id: blueBox
////                width: 120
////                height: 32
////                color: {
////                    if (index%2 == 1) {
////                        "green"
////                    } else {
////                        "red"
////                    }
////                }
////                Text {
////                    anchors.fill: parent
////                    horizontalAlignment: Text.AlignHCenter
////                    verticalAlignment: Text.AlignVCenter
////                    //text: index
////                    //text: modelData + '(' + index + ')'
////                    text: name
////                }
////                Rectangle {
////                    anchors.left: parent.left
////                    anchors.verticalCenter: parent.verticalCenter
////                    anchors.leftMargin: 5

////                    width: 16
////                    height: 16
////                    radius: 8
////                    color: surfaceColor
////                }
////            }
////        }
////    }
}


////----------------------------------------------------------------------------------------------------


//import QtQuick 2.12
//import QtQuick.Window 2.12

//Window {
//    visible: true
//    width: 640
//    height: 480

//    Component {
//        id: petDelegate
//        Rectangle {
//            width: 40
//            height: 40
//            Text {
//                anchors.centerIn: parent
//                font.bold: true
//                text: index
//            }
//        }
//    }

//    // Define a highlight with customized movement between items.
//    Component {
//        id: highlightBar
//        Rectangle {
//            width: 200; height: 50
//            color: "#FFFF88"
//            y: listView.currentItem.y;
//            Behavior on y { SpringAnimation { spring: 2; damping: 0.1 } }
//        }
//    }

//    ListView {
//        id: listView
//        width: 200; height: parent.height
//        x: 30

//        model: 100
//        delegate: petDelegate
//        focus: true

//        // Set the highlight delegate. Note we must also set highlightFollowsCurrentItem
//        // to false so the highlight delegate can control how the highlight is moved.
//        highlight: highlightBar
//        highlightFollowsCurrentItem: false
//    }
//}


////----------------------------------------------------------------------------------------------------

//import QtQuick 2.12
//import QtQuick.Window 2.12

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")

//    Rectangle {
//        width: 240
//        height: 300

//        ListView {
//            id: view
//            anchors.fill: parent
//            anchors.margins: 20

//            clip: true

//            model: 100

//            delegate: numberDelegate
//            spacing: 5

//            highlight: highlightComponent
//            focus: true
//        }

//        Component {
//            id: highlightComponent

//            Rectangle {
//                width: ListView.view.width
//                color: "green"
//            }
//        }

//        Component {
//            id: numberDelegate

//            Item {
//                width: ListView.view.width
//                height: 40

//                Text {
//                    anchors.centerIn: parent

//                    //font.pixelSize: 10

//                    text: index
//                }
//            }
//        }
//    }

//}
