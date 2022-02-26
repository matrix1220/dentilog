import QtQuick 2.5
import QtQuick.Window 2.2

CWindow {
    title: "Error"
    visible: true
    minimumHeight: 100
    //maximumHeight: 100
    minimumWidth: 250
    //maximumWidth: 250
    //width: 250
    //height: 100

    flags: Qt.WindowCloseButtonHint | Qt.CustomizeWindowHint | Qt.Dialog | Qt.WindowTitleHint

    Image {
        width: 50
        fillMode: Image.PreserveAspectFit
        source: "error.png"
        anchors.right: message.left
        anchors.verticalCenter: message.verticalCenter
    }

    Text {
        id: message
        anchors.centerIn: parent
        text: app.err_str
    }

}
