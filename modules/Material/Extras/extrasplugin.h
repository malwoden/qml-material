#ifndef EXTRASPLUGIN_H
#define EXTRASPLUGIN_H

#include <QQmlExtensionPlugin>

class ExtrasPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri);

private:
    QString fileLocation() const;
    bool isLoadedFromResource() const;
};

#endif // EXTRASPLUGIN_H
