#ifndef STYLESPLUGIN_H
#define STYLESPLUGIN_H

#include <QQmlExtensionPlugin>

class StylesPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri);

private:
    QString fileLocation() const;
    bool isLoadedFromResource() const;
};

#endif // STYLESPLUGIN_H
