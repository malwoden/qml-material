#include "materialplugin.h"

#include <qqml.h>
#include <QFile>

struct Type {
    const char *type;
    int major, minor;
};

static const Type createableTypes [] = {
    { "Action", 0, 1 },
    { "ActionBar", 0, 1 },
    { "ActionButton", 0, 1 },
    { "AppTheme", 0, 1 },
    { "ApplicationWindow", 0, 1 },
    { "AwesomeIcon", 0, 1 },
    { "BottomActionSheet", 0, 1 },
    { "BottomSheet", 0, 1 },
    { "Button", 0, 1 },
    { "Card", 0, 1 },
    { "CheckBox", 0, 1 },
    { "DatePicker", 0, 1 },
    { "Dialog", 0, 1 },
    { "Dropdown", 0, 1 },
    { "Icon", 0, 1 },
    { "IconButton", 0, 1 },
    { "Ink", 0, 1 },
    { "InputDialog", 0, 1 },
    { "Label", 0, 1 },
    { "MainView", 0, 1 },
    { "MenuField", 0, 1 },
    { "NavigationDrawer", 0, 1 },
    { "Object", 0, 1 },
    { "OverlayLayer", 0, 1 },
    { "OverlayView", 0, 1 },
    { "Page", 0, 1 },
    { "PageSidebar", 0, 1 },
    { "PageStack", 0, 1 },
    { "Popover", 0, 1 },
    { "PopupBase", 0, 1 },
    { "ProgressBar", 0, 1 },
    { "ProgressCircle", 0, 1 },
    { "RadioButton", 0, 1 },
    { "Scrollbar", 0, 1 },
    { "Sidebar", 0, 1 },
    { "Slider", 0, 1 },
    { "Snackbar", 0, 1 },
    { "Switch", 0, 1 },
    { "Tab", 0, 1 },
    { "TabBar", 0, 1 },
    { "TabbedPage", 0, 1 },
    { "TextField", 0, 1 },
    { "ThemePalette", 0, 1 },
    { "ThinDivider", 0, 1 },
    { "TimePicker", 0, 1 },
    { "TimePickerDialog", 0, 1 },
    { "Toolbar", 0, 1 },
    { "Tooltip", 0, 1 },
    { "View", 0, 1 },
    { "Wave", 0, 1 },
    { "Window", 0, 1 }
};


static const Type singletonTypes [] = {
    { "Device", 0, 1 },
    { "MaterialAnimation", 0, 1 },
    { "Palette", 0, 1 },
    { "Theme", 0, 1 },
    { "Units", 0, 1 }
};

void MaterialPlugin::registerTypes(const char *uri)
{
    const QString filesLocation = fileLocation();
    for (int i = 0; i < int(sizeof(createableTypes)/sizeof(createableTypes[0])); i++)
        qmlRegisterType(QUrl(filesLocation + "/" + createableTypes[i].type + ".qml"),
                        uri, createableTypes[i].major, createableTypes[i].minor, createableTypes[i].type);

    for (int i = 0; i < int(sizeof(singletonTypes)/sizeof(singletonTypes[0])); i++)
        qmlRegisterSingletonType(QUrl(filesLocation + "/" + singletonTypes[i].type + ".qml"),
                        uri, singletonTypes[i].major, singletonTypes[i].minor, singletonTypes[i].type);
}

QString MaterialPlugin::fileLocation() const
{
    if (isLoadedFromResource())
        return "qrc:/Material";
    return baseUrl().toString();
}

bool MaterialPlugin::isLoadedFromResource() const
{
    // If one file is missing, it will load all the files from the resource
    QFile file(baseUrl().toLocalFile() + "/Action.qml");
    if (!file.exists())
        return true;
    return false;
}
