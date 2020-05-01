import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.6
import QType.VideoProbeSender 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Sender")

    Camera {
        id: camera
    }

    VideoOutput {
        id: video
        source: camera
        anchors.fill: parent
    }

    VPSender {
        id: hello
    }


}
