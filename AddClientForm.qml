import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Controls.Universal 2.12

CWindow {
    title: "Add Client"
    visible: true
    width: 300
    height: 300
    Universal.theme: Universal.Dark
    Universal.accent: Universal.Violet

    property int textmargins: 5

    Column {
        anchors.centerIn: parent

        Rectangle {
            width: parent.width
            height: firstname.implicitHeight + 10

            radius: textmargins
            color: '#eee'
            border.color: '#888'
            border.width: 2

            TextEdit {
                wrapMode: TextEdit.Wrap
                clip: true
                anchors.fill: parent
                anchors.margins: textmargins
                id: firstname
                text: "firstname"
            }
        }

        Button {
            text: "add"
            onClicked: app.newClient(firstname.text)
        }
    }


}
