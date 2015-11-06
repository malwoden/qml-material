#include "extrasplugin.h"

#include <qqml.h>
#include <QFile>

static const struct {
    const char *type;
    int major, minor;
} qmldir [] = {
    { "AutomaticGrid", 0, 1 },
    { "CircleImage", 0, 1 },
    { "CircleMask", 0, 1 },
    { "ColumnFlow", 0, 1 },
    { "Document", 0, 1 },
    { "Image", 0, 1 },
    { "Object", 0, 1 }
};

void ExtrasPlugin::registerTypes(const char *uri)
{
    const QString filesLocation = fileLocation();
    for (int i = 0; i < int(sizeof(qmldir)/sizeof(qmldir[0])); i++)
        qmlRegisterType(QUrl(filesLocation + "/" + qmldir[i].type + ".qml"), uri,
                        qmldir[i].major, qmldir[i].minor, qmldir[i].type);
}

QString ExtrasPlugin::fileLocation() const
{
    if (isLoadedFromResource())
        return "qrc:/Material/Extras";
    return baseUrl().toString();
}

bool ExtrasPlugin::isLoadedFromResource() const
{
    // If one file is missing, it will load all the files from the resource
    QFile file(baseUrl().toLocalFile() + "/AutomaticGrid.qml");
    if (!file.exists())
        return true;
    return false;
}
