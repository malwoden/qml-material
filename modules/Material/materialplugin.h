#ifndef MATERIALPLUGIN_H
#define MATERIALPLUGIN_H

#include <QQmlExtensionPlugin>

class MaterialPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri);

private:
    QString fileLocation() const;
    bool isLoadedFromResource() const;
};

#endif // MATERIALPLUGIN_H
