#ifndef DENTOLOG_REQUEST_H
#define DENTOLOG_REQUEST_H

#include <QObject>
#include <QJsonObject>
#include <QString>
#include <QtNetwork>

#include "dentolog.h"

namespace Dentolog {

class Request : public QObject
{
    Q_OBJECT
public:
    explicit Request(Helper* helper, QString method, QJsonObject data={}, QObject *parent = nullptr);

    void send();
private:
    Helper* helper;
    QNetworkRequest request;
    QString body;

private slots:
    void finish(QNetworkReply* reply);

signals:
    void finished(QJsonValue);
    void finishedWithRequest(Request*, QJsonValue);
    void error(QString);

public slots:
};

}

#endif // DENTOLOG_REQUEST_H
