#ifndef DENTOLOG_H
#define DENTOLOG_H

#include <QObject>
#include <QJsonObject>
#include <QString>
#include <QtNetwork>

namespace Dentolog {

enum class METHOD {
  GET,
  POST,
  PUT
};

class Request;
class Dentolog;

class Helper : public QObject {
    Q_OBJECT
public:
    explicit Helper(QString verb, Dentolog *parent = nullptr);
    Dentolog* dentolog;
    QString verb;
    Request* send(QString method, QJsonObject data={}, QObject *parent = nullptr);
};

class Dentolog : public QObject
{
    Q_OBJECT

public:

    explicit Dentolog(QString token, QObject *parent = nullptr);
    QString token;

    Helper get;
    Helper post;
    Helper put;

    QNetworkAccessManager* connection;

    void error(QString err_str);

    static const QString API_URL;

};

}

#endif // DENTOLOG_H
