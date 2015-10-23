TEMPLATE = lib
TARGET = $$qtLibraryTarget(materialextras)
QT += qml quick
CONFIG += qt plugin

uri = Material.Extras

QML_FILES += $$PWD/Object.qml \
             $$PWD/AutomaticGrid.qml \
             $$PWD/CircleImage.qml \
             $$PWD/CircleMask.qml \
             $$PWD/ColumnFlow.qml \
             $$PWD/Document.qml \
             $$PWD/Image.qml \
             $$PWD/Object.qml

OTHER_FILES += \
            $$QML_FILES \
            $$PWD/qmldir

SOURCES += $$PWD/extrasplugin.cpp
HEADERS += $$PWD/extrasplugin.h

RESOURCES += extras.qrc

installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)

qmlfiles.files += $$PWD/qmldir $$PWD/plugins.qmltypes
qmlfiles.path = $$installPath
target.path = $$installPath

INSTALLS += target qmlfiles
