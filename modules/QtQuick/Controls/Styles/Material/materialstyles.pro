TEMPLATE = lib
CONFIG += plugin
QT += qml quick
TARGET = $$qtLibraryTarget(materialstyles)

uri = QtQuick.Controls.Styles.Material

HEADERS += \
    $$PWD/stylesplugin.h

SOURCES += \
    $$PWD/stylesplugin.cpp

RESOURCES += \
    $$PWD/styles.qrc

QML_FILES += \
    $$PWD/ApplicationWindowStyle.qml \
    $$PWD/ButtonStyle.qml \
    $$PWD/CheckBoxStyle.qml \
    $$PWD/ProgressBarStyle.qml \
    $$PWD/SwitchStyle.qml \
    $$PWD/ToolBarStyle.qml \
    $$PWD/ToolButtonStyle.qml \
    $$PWD/RadioButtonStyle.qml \
    $$PWD/SliderStyle.qml \
    $$PWD/TextFieldStyle.qml

OTHER_FILES += \
    $$QML_FILES \
    $$PWD/qmldir

installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
target.path = $$installPath

qmlfiles.files += $$PWD/qmldir $$PWD/plugins.qmltypes
qmlfiles.path = $$installPath

INSTALLS += target qmlfiles
