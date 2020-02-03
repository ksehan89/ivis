import QtQuick 2.0

Item {
    // 1. image path를 받을 수 있는 변수를 만든다.
    property string imagePath: "qrc:/POPUP/POPUP_IMG_R.png"

    // 2. 해당 path를 이미지에 입력해서 출력한다.(타겟은 popup_bg2)

    Image {
        id: root
        source: "qrc:/POPUP/POPUP_IMG_BG_R.png"
    }

    Image {
        id: popup_bg2
        source: imagePath
    }


    property int select_enum: CustomPopupBG.Color1.Red1
    enum Color1 {
        Red1, Green1, Blue1
    }

    Rectangle {
        width: 200
        height: 200
        color: {
            console.log("select_enum : ", select_enum)
            if (CustomPopupBG.Color1.Red1 === select_enum) {
                "red"
            } else if (CustomPopupBG.Color1.Green1 === select_enum) {
                "green"
            } else if (CustomPopupBG.Color1.Blue1 === select_enum) {
                "blue"
            } else {
                "yellow"
            }
        }
    }

}
