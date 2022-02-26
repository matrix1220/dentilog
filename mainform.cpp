#include "mainform.h"
#include <QApplication>

MainForm::MainForm(QObject *parent) : Form(parent)
{
    load(QUrl("qrc:/MainForm.qml"));
    show();
}

void MainForm::openClients()
{
    swap(&clientsform);
}

void MainForm::close()
{
    Form::close();
    QApplication::exit();
}


