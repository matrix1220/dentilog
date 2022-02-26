#include <QApplication>
#include <QtQml/QQmlApplicationEngine>

#include <QDebug>

#include "dentolog.h"
#include "mainform.h"
#include "errorform.h"
#include "clientsform.h"

QQmlApplicationEngine* engine = nullptr;
Dentolog::Dentolog* dentolog = nullptr;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ::engine = &engine;

    Dentolog::Dentolog dentolog("asdasdasd");
    ::dentolog = &dentolog;

    MainForm mainform;

    return app.exec();
}
