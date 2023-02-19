#include "lsettings.h"

#include <QFile>



LSettings::LSettings(const QString &organization, const QString &application, QObject *parent)
    : QSettings(organization, application, parent)
{
}



LSettings::LSettings(Scope scope, const QString &organization, const QString &application, QObject *parent)
    : QSettings(scope, organization, application, parent)
{
}



LSettings::LSettings(const Format format, const Scope scope, const QString &organization, const QString &application, QObject *parent)
    : QSettings(format, scope, organization, application, parent)
{
}



LSettings::LSettings(const QString &fileName, const QSettings::Format format, QObject *parent)
    : QSettings(fileName, format, parent)
{
}



LSettings::LSettings(QObject *parent)
    : QSettings(parent)
{
}



void LSettings::initBoolValue(const QString &name, bool &v)
{
    bool ok;
    int i = (int)v;
    i = value(name, i).toInt(&ok);

    if (!ok || (i != 0 && i != 1))
        i = (int)v;

    v = (bool)i;
    setValue(name, i);
}
