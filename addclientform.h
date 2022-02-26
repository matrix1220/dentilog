#ifndef ADDCLIENTFORM_H
#define ADDCLIENTFORM_H

#include <QObject>

#include <QJsonValue>

#include "form.h"

#include "dentolog.h"
#include "dentolog.request.h"
extern Dentolog::Dentolog* dentolog;

class AddClientForm : public Form
{
    Q_OBJECT
public:
    explicit AddClientForm(QObject* parent=nullptr);
public slots:
    void newClient(QString firstname);
    void response(Dentolog::Request*, QJsonValue);
};

#endif // ADDCLIENTFORM_H
