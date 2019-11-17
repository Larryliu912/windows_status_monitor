import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 320
    height: 240
    title: qsTr("Windows Status Monitor")

    Row {
        id: row
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Text {
            id: uploadSpeed
            y: 25
            width: 155
            height: 50
            text: qsTr("Dowload")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
        }

        Text {
            id: downloadSpeed
            y: 115
            width: 155
            height: 50
            text: qsTr("Download")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
        }
    }
}

/*##^##
Designer {
    D{i:2;anchors_height:24;anchors_width:155}D{i:3;anchors_height:24;anchors_width:155}
D{i:1;anchors_height:400;anchors_width:320;anchors_x:0;anchors_y:0}
}
##^##*/
