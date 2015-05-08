TEMPLATE = lib
CONFIG += plugin
QT += qml quick
TARGET = $$qtLibraryTarget(materiallistitems)

uri = Material.ListItems

HEADERS += \
    $$PWD/listitemsplugin.h

SOURCES += \
    $$PWD/listitemsplugin.cpp

RESOURCES += \
    $$PWD/listitems.qrc

QML_FILES += \
    $$PWD/BaseListItem.qml \
    $$PWD/Divider.qml \
    $$PWD/SectionHeader.qml \
    $$PWD/SimpleMenu.qml \
    $$PWD/Standard.qml \
    $$PWD/Subheader.qml \
    $$PWD/Subtitled.qml \

OTHER_FILES += \
    $$QML_FILES \
    $$PWD/qmldir

installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
target.path = $$installPath

qmlfiles.files += $$PWD/qmldir $$PWD/plugins.qmltypes
qmlfiles.path = $$installPath

INSTALLS += target qmlfiles
