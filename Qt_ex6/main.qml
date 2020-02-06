import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property bool isGuideArea: true

    ListView {

        id: view
        width: 100
        height: 200
        model: 100
        delegate: numberDelegate
//        clip: true

        highlight: highlightComponent

        highlightFollowsCurrentItem : true      //default : true
        focus: true
        Rectangle {
            anchors.fill: parent
            color: "red"
            opacity: 0.3
            visible: isGuideArea
        }
    }

    Component {
        id: highlightComponent

        Rectangle {
            width: 100
            height: 20
            color: "green"
            border.width: 1
            border.color: "black"
            onWidthChanged: {
                console.log("onWidthChanged : " , width)
            }
        }

    }

    Component {
        id: numberDelegate
        Item  {                              // 이 구간 Item 과 Rectangle 차이는?
            width: 100
            height: 20
            Text {
                anchors.centerIn: parent
                font.bold: true
                text: index
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    view.currentIndex = index
                    console.log("onClicked: ", view.currentIndex)
                }
            }
        }
    }
}
