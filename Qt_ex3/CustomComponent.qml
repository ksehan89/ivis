import QtQuick 2.0

Item {
    property int myIndex: 0
    onMyIndexChanged: {
        console.log(" inner onMyIndexChanged: ", myIndex)
    }


}
