#include "listitemsplugin.h"

#include <qqml.h>
#include <QFile>

struct Type {
    const char *type;
    int major, minor;
};

static const Type createableTypes [] = {
    { "BaseListItem", 0, 1 },
    { "Divider", 0, 1 },
    { "SectionHeader", 0, 1 },
    { "SimpleMenu", 0, 1 },
    { "Standard", 0, 1 },
    { "Subheader", 0, 1 },
    { "Subtitled", 0, 1 }
};

void ListItemsPlugin::registerTypes(const char *uri)
{
    const QString filesLocation = fileLocation();
    for (int i = 0; i < int(sizeof(createableTypes)/sizeof(createableTypes[0])); i++)
        qmlRegisterType(QUrl(filesLocation + "/" + createableTypes[i].type + ".qml"),
                        uri, createableTypes[i].major, createableTypes[i].minor, createableTypes[i].type);
}

QString ListItemsPlugin::fileLocation() const
{
    if (isLoadedFromResource())
        return "qrc:/Material/ListItems";
    return baseUrl().toString();
}

bool ListItemsPlugin::isLoadedFromResource() const
{
    // If one file is missing, it will load all the files from the resource
    QFile file(baseUrl().toLocalFile() + "/BaseListItem.qml");
    if (!file.exists())
        return true;
    return false;
}
