#ifndef LISTITEMSPLUGIN_H
#define LISTITEMSPLUGIN_H

#include <QQmlExtensionPlugin>

class ListItemsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri);

private:
    QString fileLocation() const;
    bool isLoadedFromResource() const;
};

#endif // LISTITEMSPLUGIN_H
