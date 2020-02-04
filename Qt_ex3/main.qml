import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    CustomComponent {
        id: customComponent
        Rectangle {
            id: sigTest
            signal signalTestor(int aaa1)
            //signal signalTestor(string person)
            width: 100
            height: 100
            color: "red"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    customComponent.myIndex++
                    sigTest.signalTestor(1);
                    console.log("onClicked: ", customComponent.myIndex)
                }
            }

            // Component 방식의 connect
            Component.onCompleted: {
                sigTest.signalTestor.connect(aa)
                sigTest.signalTestor.connect(bb)
                sigTest.signalTestor.connect(cc)
                sigTest.signalTestor("Tom")
                //sigTest.signalTestor.disconnect(cc)
                removeConnectionCC()
                sigTest.signalTestor("abc")
                //removecc(cc);
            }

            function removeConnectionAA() {
                removeConnection(aa)
            }

            function removeConnectionBB() {
                removeConnection(bb)
            }

            function removeConnectionCC() {
                removeConnection(cc)
            }

            function removeConnection(type) {
                sigTest.signalTestor.disconnect(type)
            }
            //===========================================================
//            function aa(myIndex) {
//                console.log("mySig aa : ", customComponent.myIndex)
//            }

//            function bb(myIndex) {
//                console.log("mySig bb : ", customComponent.myIndex)
//            }

//            function cc(myIndex) {
//                console.log("mySig cc : ", customComponent.myIndex)
//            }

//            function removecc(myIndex) {
//                sigTest.signalTestor.disconnect(cc)
//                console.log("disconnect cc.. : ", myIndex)
//            }
            //===========================================================




            // Connections 방식의 connect
            Connections {
                target: sigTest
                onSignalTestor: {
                    sigTest.signalTestor.connect(aa)
                    sigTest.signalTestor.connect(bb)
                    sigTest.signalTestor.connect(cc)
                    //sigTest.signalTestor("MARK1")
                    removeConnectionBB()
                    //console.log("onSigTestor : " , aaa1)
                    //sigTest.signalTestor.disconnect(aa)
                    //sigTest.signalTestor.connect(removecc)
                    //sigTest.signalTestor("MARK2")
                }

                function removeConnectionAA() {
                    removeConnection(aa)
                }

                function removeConnectionBB() {
                    removeConnection(bb)
                }

                function removeConnectionCC() {
                    removeConnection(cc)
                }

                function removeConnection(type) {
                    sigTest.signalTestor.disconnect(type)
                }

            }


        }

    }




//    CustomComponent {
//        id: custamComponent
//        Rectangle {
//            id: rect1
//            signal updateColor(int tttt)    //*
//            width: 100
//            height: 100
//            color: "red"

//            MouseArea {
//                //anchors.fill: rect1
//                anchors.fill: parent
//                onClicked: {
////                    custamComponent.myIndex++
//                    rect1.updateColor(1);   //*
//                }
//            }
//            Component.onCompleted: {
//                rect1.updateColor.connect(aaaaa)
//            }

//            function aaaaa(myNum) {
//                console.log("1myNum : " , myNum)
//            }
//        }
//    }


//    Connections{
//        target: custamComponent
//        onMyIndexChanged: {
//            console.log("onMyIndexChanged: ", customComponent.myIndex)
//        }
//    }

//        Connections{
//            target: rect1
//            onUpdateColor: {
//                console.log("onUpdateColor : " , tttt)
//            }

//        }



}


