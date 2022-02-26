#include "addclientform.h"

AddClientForm::AddClientForm(QObject *parent) : Form(parent)
{
    load(QUrl("qrc:/AddClientForm.qml"));
}

void AddClientForm::newClient(QString firstname)
{
    Dentolog::Request* request = dentolog->put.send("Client", {{"firstname",firstname}}, this);
    connect(request, &Dentolog::Request::finishedWithRequest, this, &AddClientForm::response);
    request->send();

}

void AddClientForm::response(Dentolog::Request* request, QJsonValue)
{
    close();
    request->deleteLater();
}
