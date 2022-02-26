import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

CWindow {
    title: "Dentolog"
    visible: true
    minimumWidth: 300
    minimumHeight: 300

   Row {
       anchors.centerIn: parent

        Button {
            text: "Clients"
            onClicked: app.openClients()
        }
        Button {
            text: "Records"
            onClicked: app.openRecords()
        }
   }


}
