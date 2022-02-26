import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

ApplicationWindow {
    signal close_event()
    onClosing: {
        close.accepted = false;
        close_event();
    }

}
