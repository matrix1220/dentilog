#ifndef ERRORFORM_H
#define ERRORFORM_H

#include <QObject>
#include <QString>

#include "form.h"

class ErrorForm : public Form
{
    Q_OBJECT
public:
    explicit ErrorForm(QString err_str, QObject *parent = nullptr);

    Q_PROPERTY(QString err_str MEMBER err_str NOTIFY err_strChanged)

    QString err_str;

signals:
    void err_strChanged();

public slots:

private:
};

#endif // ERRORFORM_H
