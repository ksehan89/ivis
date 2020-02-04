import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    CustomComponent2 {
        id: customComponent2
        signal changedColor(int cc)

        Rectangle {
            id: rect_bg
            width: 400
            height: 400
            color: "lightgray"
            Rectangle {
                id: rect1
                width: 100
                height: 100
                color: "red"
                anchors.left: rect_bg.left
                anchors.top: rect_bg.top
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    //text: "Rect1\nColor: "

                }
            }

            Rectangle {
                id: rect2
                width: 100
                height: 100
                color: "blue"
                anchors.right: rect_bg.right
                anchors.top: rect_bg.top
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "Rect2"
                    color: "white"
                }
            }

            Rectangle {
                id: rect3
                width: 100
                height: 100
                color: "green"
                anchors.left: rect_bg.left
                anchors.bottom: rect_bg.bottom
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "Rect3"
                }
            }

            Rectangle {
                id: rect4
                width: 100
                height: 100
                color: "yellow"
                anchors.right: rect_bg.right
                anchors.bottom: rect_bg.bottom
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "Rect4"
                }
            }

            Rectangle {
                id: r1
                width: 50
                height: 50
                color: "red"
                //anchors.verticalCenter: rect_bg.verticalCenter
                anchors.top: rect_bg.top
                anchors.topMargin: 125
                anchors.left: rect_bg.left
                anchors.leftMargin: 100
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "R1"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        //customComponent2.myIndex++
                        console.log("select_r1_1 : ", customComponent2.select_r1)
                        customComponent2.select_r1 = true
                        console.log("select_r1_2 : ", customComponent2.select_r1)
                    }
                }

            }

            Rectangle {
                id: r2
                width: 50
                height: 50
                color: "blue"
                //anchors.verticalCenter: rect_bg.verticalCenter
                anchors.top: rect_bg.top
                anchors.topMargin: 125
                anchors.left: rect_bg.left
                anchors.leftMargin: 150
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "R2"
                    color: "white"
                }
            }

            Rectangle {
                id: r3
                width: 50
                height: 50
                color: "green"
                //anchors.verticalCenter: rect_bg.verticalCenter
                anchors.top: rect_bg.top
                anchors.topMargin: 125
                anchors.left: rect_bg.left
                anchors.leftMargin: 200
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "R3"
                }
            }

            Rectangle {
                id: r4
                width: 50
                height: 50
                color: "yellow"
                //anchors.verticalCenter: rect_bg.verticalCenter
                anchors.top: rect_bg.top
                anchors.topMargin: 125
                anchors.left: rect_bg.left
                anchors.leftMargin: 250
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "R4"
                }
            }

            Rectangle {
                id: red
                width: 100
                height: 50
                color: "red"
                //anchors.verticalCenter: rect_bg.verticalCenter
                anchors.top: r1.bottom
                anchors.topMargin: 5
                anchors.left: r1.left
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "red"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
//                      if (0 !=customComponent2.myIndex

                    }
                }

            }

            Rectangle {
                id: all_red
                width: 100
                height: 50
                color: "red"
                //anchors.verticalCenter: rect_bg.verticalCenter
                anchors.top: red.bottom
                anchors.topMargin: 5
                anchors.left: red.left
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "all_red"
                }
            }

            Rectangle {
                id: yellow
                width: 100
                height: 50
                color: "yellow"
                //anchors.verticalCenter: rect_bg.verticalCenter
                anchors.top: r3.bottom
                anchors.topMargin: 5
                anchors.left: r3.left
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "yellow"
                }
            }

            Rectangle {
                id: all_yellow
                width: 100
                height: 50
                color: "yellow"
                //anchors.verticalCenter: rect_bg.verticalCenter
                anchors.top: yellow.bottom
                anchors.topMargin: 5
                anchors.left: yellow.left
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "all_yellow"
                }
            }

        }
    }

    Connections {
        target: customComponent2
        onMyIndexChanged: {
            console.log("onMyIndexChanged 1: ", customComponent2.myIndex)

        }

//        onChangedColor: {
//            console.log("onChangedColor : ", cc)
//        }
    }
}
