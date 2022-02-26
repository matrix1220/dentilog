import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.5


CWindow {
    title: "Dentolog"
    visible: true
    minimumWidth: 300
    minimumHeight: 300

    RowLayout {
        anchors.fill: parent

        ListView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 1
            model: app.clients

            delegate: Rectangle {
                width: parent.width
                border.color: 'black'
                border.width: 1
                radius: 2
                anchors.margins: 5
                height: 32
                Text {
                    anchors.centerIn: parent
                    text: modelData['firstname']
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignTop

            Button {
                text: "new"
                onClicked: app.newClient()
            }
            Button {
                text: "refresh"
                onClicked: app.refresh()
            }
        }
    }

}
