import QtQuick 2.0

Item {
    property int select_enum: CustomText.FontType.FontNormal
    enum FontType {
        FontNormal, FontBold, FontItalic
    }

    Text {
        text: "Hello world"
        //font.bold : true
        property int a: 0

        font.bold: {
            //font.bold = false
            //            console.log("select_enum 1 : ", select_enum)
            //            console.log("custom.select_enum 1 : ", custom.select_enum)
            //            console.log("CustomText.FontType.FontBold 1 : ", CustomText.FontType.FontBold)
            if (CustomText.FontType.FontNormal === select_enum) {
                console.log("select_enum 2 : ", custom.select_enum)
                //                    console.log("CustomText.FontType.FontBold 2 : ", CustomText.FontType.Bold)
                false
            } else if (CustomText.FontType.FontBold === select_enum) {
                console.log("select_enum 3 : ", custom.select_enum)
                //                    console.log("select_enum 3 : ", select_enum)
                //                    console.log("CustomText.FontType.FontBold 3 : ", CustomText.FontType.Bold)
                true
            } else {
                console.log("abccccc")
                false
            }

        }
    }

    //    Rectangle {
    //        width: 100
    //        height: 100
    //        Text {
    //            text: "Hello world"
    //            //font.bold : true

    //            font.bold: {
    //                font.bold = false
    //                console.log("select_enum 1 : ", select_enum)
    //                console.log("custom.select_enum 1 : ", custom.select_enum)
    //                console.log("CustomText.FontType.FontBold 1 : ", CustomText.FontType.FontBold)
    //                if (CustomText.FontType.FontNormal === select_enum) {
    //                    console.log("select_enum 2 : ", select_enum)
    ////                    console.log("CustomText.FontType.FontBold 2 : ", CustomText.FontType.Bold)
    //                    font.bold = false
    //                } else if (CustomText.FontType.FontBold === select_enum) {
    ////                    console.log("select_enum 3 : ", select_enum)
    ////                    console.log("CustomText.FontType.FontBold 3 : ", CustomText.FontType.Bold)
    //                    font.bold = true
    //                } else {
    //                    font.bold = false
    //                }
    //            }

    //        }

    //    }

}
