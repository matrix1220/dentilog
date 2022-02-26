#ifndef CLIENTSFORM_H
#define CLIENTSFORM_H

#include <QObject>
#include <QVariantList>
#include <QJsonValue>

#include "form.h"

#include "addclientform.h"

#include "dentolog.h"
#include "dentolog.request.h"
extern Dentolog::Dentolog* dentolog;

class ClientsForm : public Form
{
    Q_OBJECT
public:
    explicit ClientsForm(QObject *parent = nullptr);
    Q_PROPERTY(QVariantList clients MEMBER clients NOTIFY clientsChanged)

    Dentolog::Request* request;

    QVariantList clients;

    AddClientForm addclientsform;

    void update() override;

public slots:
    void getClients(QJsonValue); // make this private
    void newClient();
    void refresh();

signals:
    void clientsChanged();
};

#endif // CLIENTSFORM_H
