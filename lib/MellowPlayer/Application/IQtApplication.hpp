#pragma once

#include <QObject>

namespace MellowPlayer::Application
{
    class IQtApplication : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString buildInfo READ buildInfo CONSTANT)
    public:
        virtual ~IQtApplication();

        virtual void initialize() = 0;
        virtual int run() = 0;
        Q_INVOKABLE virtual void clearCache() const = 0;
        Q_INVOKABLE virtual void clearCookies() const = 0;
        Q_INVOKABLE virtual void requestQuit() = 0;
        Q_INVOKABLE virtual void restart() = 0;
        Q_INVOKABLE virtual void quit() = 0;
        virtual QString buildInfo() const = 0;

        virtual bool restartRequested() const = 0;

    signals:
        void quitRequested();
    };
}
