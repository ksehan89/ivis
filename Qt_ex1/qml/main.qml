import QtQuick 2.12
import QtQuick.Window 2.12


Window {
    property bool isEnable: false
    property double number: 0.0
//    property enumeration enumValue: 0
    property int num1: 0
//    property list states : [
//        State { name: "activated" },
//        State { name: "deactivated" }
//    ]
    property real sosu: 10.00
    property string text: "Hello"
    property url img_path: "qrc:/POPUP/POPUP_IMG_BG_R.png"
    property var aNumber: 100
    property var aBool: false
    property var aString: "Hello world!"
    property var anotherString: String("#FF008800")
    property var aColor: Qt.rgba(0.2, 0.3, 0.4, 0.5)
    property var aRect: Qt.rect(10, 10, 10, 10)
    property var aPoint: Qt.point(10, 10)
    property var aSize: Qt.size(10, 10)
    property var aVector3d: Qt.vector3d(100, 100, 100)
    property var anArray: [1, 2, 3, "four", "five", (function() { return "six"; })]
    property var anObject: { "foo": 10, "bar": 20 }
//    property var aFunction: (function() { return "one"; })
//    property date today: "2020-01-30"
//    property point name: value








    id: window1
    visible: true
    width: 600
    height: 400
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
//    CustomPopupBG {
//        id:root


//        imagePath: "qrc:/POPUP/POPUP_IMG_Y.png"

//        property int mod: 0

//        Component.onCompleted: {
//            console.log("Component.onCompleted - 2")
//        }



//        Rectangle {
//            //            id: popup_bg
//            ////            width: 100
//            ////            height: 100
//            //            x : 500
//            //            y : 500
//            Component.onCompleted: {
//                console.log("Component.onCompleted - 3")
//            }
//        }

//        Rectangle {
//            id: test
//            //            x: popup_bg3.x + 300
//            //            y: 400
//            width: 300
//            height: 300
//            color: "red"
//            Text {
//                id: name
//                text: window1.text
//                Component.onCompleted: {
//                    console.log("Component.onCompleted - 4")
//                }
//            }
//            Component.onCompleted: {
//                console.log("Component.onCompleted - 5")
//            }//        }

//        Rectangle {
//            id: test2
//            width: 100
//            height: 100
//            color: "yellow"
//            anchors.right: test.right
//            anchors.top: test.top
//            Component.onCompleted: {
//                console.log("Component.onCompleted - 6")
//            }

//        }


//        MouseArea {
//            id: mouseArea
//            anchors.fill:test2
//            hoverEnabled: true
//            propagateComposedEvents: true


//            onCanceled: {
//                console.log("program exit: ")
//            }

////            onPositionChanged: {
////                console.log("onPositionChanged ~~~~~~~~~~~~~~~")
////            }

//            onDoubleClicked: {
//                console.log("onDoubleClicked...12345")
//            }

//            onWheel: {
//                console.log("onWhell #####")

//            }

//            onReleased: {
//                console.log("onReleased test")
//            }

//            onPressAndHold: {
//                console.log("onPressAndHold........")
//            }

//            // test2 영역으로 한정 (anchors.fill:test2)
//            onEntered: {
//                console.log("hover in")
//            }
//            onExited: {
//                console.log("hover out")
//            }

//            onPressed: {
////                console.log("mod1 : ", root.mod)
//                root.mod+=1
////                console.log("mod2 : ", root.mod)
//                if (0 == root.mod%3) {
//                    root.imagePath = "qrc:/POPUP/POPUP_IMG_W.png"
//                    console.log("mod: ", root.mod)
//                } else if (1 == root.mod%3) {
//                    root.imagePath = "qrc:/POPUP/POPUP_IMG_R.png"
//                    console.log("mod: ", root.mod)
//                } else {
//                    root.imagePath = "qrc:/POPUP/POPUP_IMG_Y.png"
//                    console.log("mod: ", root.mod)
//                }
//            }


//            onClicked: {

//                console.log("@@@@@@@@@@@@@@@@@@@@@ "+ isEnable)
//                console.log("@@@@@@@@@@@@@@@@@@@@@ "+ mouse.x)
//                console.log("@@@@@@@@@@@@@@@@@@@@@ "+ mouse.y)

//                if (false == isEnable) {
//                    console.log("log1 : ", isEnable)
//                    isEnable = true
//                    console.log("log2 : ", isEnable)

//                } else {
//                    console.log("log3 : ", isEnable)
//                    isEnable = false
//                    console.log("log4 : ", isEnable)
//                }
//            }


//        }
//    }

    property int colorIndex: 0

    property bool myBool: false
    property int myInt: 0

//    CustomPopupBG{
//        id: custom
//        Rectangle{
//            x: 300
//            y: 300
//            width: 100
//            height: 100
//            color: "gold"
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    colorIndex++
//                    if (0 == colorIndex%3) {
//                        custom.select_enum = 1
//                    } else if (1 == colorIndex%3) {
//                        custom.select_enum = 2
//                    } else if (2 == colorIndex%3) {
//                        custom.select_enum = 3
//                    } else {

//                    }
//                }
//            }
//        }

//    }

    CustomPopupBG {
        id: customFont
        Text {

        }
    }

    Text {
        id:temp
        width: 100
        color: "blue"

        //text: "122333444455555----########"

        clip: true

//        elide:Text.ElideLeft
//        elide:Text.ElideMiddle
        elide:Text.ElideRight

        text: "1
22
333
4444
55555
----
########"
        horizontalAlignment: Text.AlignRight
        //horizontalAlignment: Text.AlignHCenter
        //verticalAlignment: Text.AlignVCenter

        font.bold: true
        font.italic: true

        //text: "1 22 333 4444 55555 ---- ########"
        //wrapMode: Text.WordWrap

        Component.onCompleted: {
            console.log("contentHeight : " , contentHeight)
            console.log("contentwidth : " , contentWidth)
            console.log("line count : " , lineCount)
            console.log("line height : " , lineHeight)
        }

        Rectangle{
            anchors.fill: parent
            color: "red"
            opacity: 0.3
        }
    }

}
