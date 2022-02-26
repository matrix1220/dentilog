#include "form.h"
#include <QApplication>
#include <QCursor>

#include <QtDebug>


Form::Form(QObject *parent) :
  QObject(parent),
  context(engine),
  component(engine),
  close_when_close(true)
{
    setContext(this);
}

void Form::load(QUrl url)
{
    component.loadUrl(url);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    if (component.isLoading()) {
        QObject::connect(&component, SIGNAL(statusChanged(QQmlComponent::Status)), this, SLOT(continue_loading()));
    } else {
        continue_loading();
    }
}

void Form::setContext(QObject * obj)
{
    context.setContextProperty("app", obj);
}

void Form::swap_back()
{
    if(swaped_from) {
        swaped_from->update();
        if(close_when_close) {
            destroy_window();
        } else {
            this->hide();
        }
        swaped_from->show();
        swaped_from = nullptr;
    }
}

void Form::swap(Form *form)
{
    this->hide();
    form->show();
    form->swaped_from = this;

}

void Form::continue_loading()
{
    if (component.isError()) {
        qWarning() << component.errors();
    }
    QApplication::restoreOverrideCursor();
}


void Form::close()
{
    if(swaped_from) {
        swap_back();
    } else {
        destroy_window();
    }
}

void Form::show()
{
    if(window) {
        window->show();
        //qWarning() << "shown";
    } else {
        if (component.isLoading()) {
            QObject::connect(&component, SIGNAL(statusChanged(QQmlComponent::Status)), this, SLOT(show()));
        } else {
            if (component.isError()) {
                qWarning() << component.errors();
            } else {
                window = qobject_cast<QQuickWindow*>(component.create(&context));
                //qWarning() << "created";
                connect(window, SIGNAL(close_event()), this, SLOT(close()));
            }
        }
    }
}

void Form::hide()
{
    if(window)
        window->hide();
}

void Form::destroy_window()
{
    if(window) {
        window->destroy();
        window->deleteLater();
        window = nullptr;
    }
}

void Form::update()
{

}
