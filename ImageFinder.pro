TARGET = $$qtLibraryTarget(TestPlugin)
# OS/2 allows only 8 chars in TARGET
os2: TARGET = ImgFndr

HEADERS += \
    imagefindersettings.h \
    imagefinderplugin.h

SOURCES += \
    imagefindersettings.cpp

RESOURCES += imagefinder.qrc

PLUGIN_DIR = $$PWD
include(../../plugins.pri)
