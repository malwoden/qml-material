#include "stylesplugin.h"

#include <qqml.h>
#include <QFile>

struct Type {
    const char *type;
    int major, minor;
};

static const Type createableTypes [] = {
    { "ApplicationWindowStyle", 0, 1 },
    { "ButtonStyle", 0, 1 },
    { "CheckBoxStyle", 0, 1 },
    { "ProgressBarStyle", 0, 1 },
    { "RadioButtonStyle", 0, 1 },
    { "SliderStyle", 0, 1 },
    { "SwitchStyle", 0, 1 },
    { "TextFieldStyle", 0, 1 },
    { "ToolBarStyle", 0, 1 },
    { "ToolButtonStyle", 0, 1 }
};

void StylesPlugin::registerTypes(const char *uri)
{
    const QString filesLocation = fileLocation();
    for (int i = 0; i < int(sizeof(createableTypes)/sizeof(createableTypes[0])); i++)
        qmlRegisterType(QUrl(filesLocation + "/" + createableTypes[i].type + ".qml"), uri,
                        createableTypes[i].major, createableTypes[i].minor, createableTypes[i].type);
}

QString StylesPlugin::fileLocation() const
{
    if (isLoadedFromResource())
        return "qrc:/QtQuick/Controls/Styles/Material";
    return baseUrl().toString();
}

bool StylesPlugin::isLoadedFromResource() const
{
    // If one file is missing, it will load all the files from the resource
    QFile file(baseUrl().toLocalFile() + "/ButtonStyle.qml");
    if (!file.exists())
        return true;
    return false;
}
