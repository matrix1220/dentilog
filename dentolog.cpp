#include "dentolog.h"
#include "dentolog.request.h"
#include "errorform.h"

namespace Dentolog {

const QString Dentolog::API_URL("http://127.0.0.1:5000/");

Dentolog::Dentolog(QString token, QObject *parent) :
    QObject(parent),
    token(token),
    get("GET", this),
    post("POST", this),
    put("PUT", this)
{
    connection = new QNetworkAccessManager(this);
}


void Dentolog::error(QString err_str)
{
    ErrorForm* form = new ErrorForm(err_str, this);
    form->show();
}

Helper::Helper(QString verb, Dentolog *parent): QObject(parent), dentolog(parent), verb(verb)
{
}

Request *Helper::send(QString method, QJsonObject data, QObject *parent)
{
    return new Request(this, method, data, parent);
}

}
