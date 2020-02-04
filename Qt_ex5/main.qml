import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Item {
        width: 400
        height: 400

        Rectangle {
            id: rect
            width: 100
            height: 100
            color: "red"



            //            states: State {
            //                name: "rotated"
            //                PropertyChanges {
            //                    target: rect
            //                    rotation: 180
            //                    transformOrigin: Item.BottomRight

            //                }
            //            }



            //    SequentialAnimation {
            //        PropertyAction { target: img; property: "smooth"; value: "true" }
            //        NumberAnimation { target: img; property: "width"; to: 300; duration: 1000 }
            //        PropertyAction { target: img; property: "smooth"; value: "false" }
            //    }


            //        // Behavior
            //        Behavior on width {
            //            NumberAnimation { duration: 1000 }
            //        }

            //        MouseArea {
            //            anchors.fill: parent
            //            onClicked: rect.width = 50
            //        }


            //        SequentialAnimation {     //SequentialAnimation QML Element
            ////        ParallelAnimation {         //ParallelAnimation QML Element
            //            running: true
            //            NumberAnimation {
            //                target: rect
            //                property: "x"
            //                to: 50
            //                duration: 1000
            //                //easing.type: Easing.InOutQuad
            //            }
            //            NumberAnimation {
            //                target: rect
            //                property: "y"
            //                to: 50
            //                duration: 1000
            //                //easing.type: Easing.InOutQuad
            //            }
            //        }
            //    }



            //      // Transition
            //    Rectangle {
            //        id: signal
            //        width: 200
            //        height: 200
            //        state: "NORMAL"

            //        states: [
            //            State {
            //                name: "NORMAL"
            //                PropertyChanges { target: signal; color: "green" }
            //                PropertyChanges { target: flag; color: "FLAG_DOWN" }
            //            },
            //            State {
            //                name: "CRITICAL"
            //                PropertyChanges { target: signal; color: "red" }
            //                PropertyChanges { target: flag; color: "FLAG_UP" }
            //            }
            //        ]
            //    }

            //    Rectangle {
            //        id: signalswitch
            //        width: 75
            //        height: 75
            //        color: "blue"

            //        MouseArea {
            //            anchors.fill: parent
            //            onClicked: {
            //                if (signal.state == "NORMAL") {
            //                    signal.state = "CRITICAL"
            //                } else {
            //                    signal.state = "NORMAL"
            //                }
            //            }
            //        }
            //    }

            //    Rectangle {
            //        id: bell
            //        width: 75
            //        height: 75
            //        color: "yellow"

            //        states: State {
            //            name: "RINGING"
            //            when: (signal.state == "CRITICAL")
            //            PropertyChanges { target: speaker; play: "RING!" }

            //        }
            //    }

        }

    }

}


