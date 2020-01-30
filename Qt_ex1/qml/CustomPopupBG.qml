import QtQuick 2.0

Item {
    // 1. image path를 받을 수 있는 변수를 만든다.
    property string imagePath: "value"

    // 2. 해당 path를 이미지에 입력해서 출력한다.(타겟은 popup_bg2)

    Image {
        id: root
        source: "qrc:/POPUP/POPUP_IMG_BG_R.png"
    }

    Image {
        id: popup_bg2
        source: imagePath
    }
}
