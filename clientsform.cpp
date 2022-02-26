#include "clientsform.h"
#include "addclientform.h"

ClientsForm::ClientsForm(QObject *parent) : Form(parent)
{
    close_when_close = false;
    load(QUrl("qrc:/ClientsForm.qml"));
    request = dentolog->get.send("Clients", {}, this);
    QObject::connect(request, &Dentolog::Request::finished, this, &ClientsForm::getClients);
    request->send();
}

void ClientsForm::update()
{
    request->send();
}


void ClientsForm::getClients(QJsonValue clients)
{
    this->clients = clients.toArray().toVariantList();
    emit clientsChanged();
}

void ClientsForm::newClient()
{
    swap(&addclientsform);
    //Form* temp = new AddClientForm(this);
    //swap_to(temp);
}

void ClientsForm::refresh()
{
    request->send();
}
