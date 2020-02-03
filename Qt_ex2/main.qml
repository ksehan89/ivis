import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property int fontIndex: 0
    property bool myBool: false
    property int myInt: 0


    CustomText {
        id: custom

        Rectangle {
            id: rect1
            x: 0
            y: 300
            width: 100
            height: 100
            color: "red"

            Text {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "bold"
            }


            MouseArea {
                anchors.fill: parent
                onClicked: {
//                    fontIndex++
                    console.log("onClicked : ", fontIndex)
                    if (0 == fontIndex) {
                        fontIndex = 1
                        custom.select_enum = 1

//                        //custom.select_enum = 0
//                        console.log("select_enum #1 : ", custom.select_enum)
////                        console.log("custom.select_enum #1 : ", custom.select_enum)
                    }
                }
            }

        }

        Rectangle {
            id: rect2
            width: 100
            height: 100
            color: "yellow"
            anchors.left: rect1.right
            anchors.leftMargin: 300
            anchors.top: rect1.top

            Text {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "normal"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
//                    fontIndex++
                    console.log("onClicked : ", fontIndex)
                    if (1 == fontIndex) {

                        fontIndex = 0
//                        custom.select_enum = 1
                        custom.select_enum = 0

//                        console.log("else")

                    }
                }
            }
        }
    }

}
