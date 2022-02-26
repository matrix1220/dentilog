#ifndef MAINFORM_H
#define MAINFORM_H

#include <QObject>
#include <QVariantList>
#include <QJsonValue>

#include "form.h"

#include "dentolog.h"
#include "dentolog.request.h"
extern Dentolog::Dentolog* dentolog;

#include "clientsform.h"

class QQuickCloseEvent;

class MainForm : public Form
{
    Q_OBJECT
public:
    explicit MainForm(QObject *parent = nullptr);

    ClientsForm clientsform;


public slots:

    void openClients();
    virtual void close() override;

signals:

};

#endif // MAINFORM_H
