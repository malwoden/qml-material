TEMPLATE = lib
CONFIG += plugin
QT += qml quick
TARGET = $$qtLibraryTarget(material)

uri = Material

HEADERS += \
    $$PWD/materialplugin.h

SOURCES += \
    $$PWD/materialplugin.cpp

RESOURCES += \
    $$PWD/material.qrc \
    $$PWD/fonts/fonts.qrc \
    $$PWD/icons/icons.qrc

QML_FILES += \
    $$PWD/Action.qml \
    $$PWD/ActionBar.qml \
    $$PWD/ActionButton.qml \
    $$PWD/ApplicationWindow.qml \
    $$PWD/AppTheme.qml \
    $$PWD/AwesomeIcon.qml \
    $$PWD/Button.qml \
    $$PWD/BottomActionSheet.qml \
    $$PWD/BottomSheet.qml \
    $$PWD/Card.qml \
    $$PWD/CheckBox.qml \
    $$PWD/Device.qml \
    $$PWD/Dialog.qml \
    $$PWD/Dropdown.qml \
    $$PWD/Icon.qml \
    $$PWD/IconButton.qml \
    $$PWD/Ink.qml \
    $$PWD/InputDialog.qml \
    $$PWD/Label.qml \
    $$PWD/MainView.qml \
    $$PWD/MaterialAnimation.qml \
    $$PWD/MenuField.qml \
    $$PWD/NavigationDrawer.qml \
    $$PWD/Object.qml \
    $$PWD/OverlayLayer.qml \
    $$PWD/OverlayView.qml \
    $$PWD/Page.qml \
    $$PWD/PageSidebar.qml \
    $$PWD/PageStack.qml \
    $$PWD/Palette.qml \
    $$PWD/PopupBase.qml \
    $$PWD/ProgressBar.qml \
    $$PWD/ProgressCircle.qml \
    $$PWD/RadioButton.qml \
    $$PWD/Sidebar.qml \
    $$PWD/Scrollbar.qml \
    $$PWD/Slider.qml \
    $$PWD/Snackbar.qml \
    $$PWD/Switch.qml \
    $$PWD/TabView.qml \
    $$PWD/Tabs.qml \
    $$PWD/TextField.qml \
    $$PWD/Theme.qml \
    $$PWD/ThinDivider.qml \
    $$PWD/Toolbar.qml \
    $$PWD/ToolTip.qml \
    $$PWD/Units.qml \
    $$PWD/View.qml \
    $$PWD/Wave.qml \
    $$PWD/Window.qml

OTHER_FILES += \
            $$QML_FILES \
            $$PWD/qmldir

installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
target.path = $$installPath

qmlfiles.files += $$PWD/qmldir $$PWD/plugins.qmltypes
qmlfiles.path = $$installPath

INSTALLS += target qmlfiles
