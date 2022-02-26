#include "errorform.h"
#include <QDebug>

ErrorForm::ErrorForm(QString err_str, QObject *parent) : Form(parent), err_str(err_str)
{
    load(QUrl("qrc:/ErrorForm.qml"));
}
