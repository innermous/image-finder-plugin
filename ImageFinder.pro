TARGET = $$qtLibraryTarget(ImageFinder)
# OS/2 allows only 8 chars in TARGET
os2: TARGET = ImgFndr

lessThan(QT_VERSION, 5.6) {
    error("ImageFinder requires at least Qt 5.6!")
}

lessThan(QT.webengine.VERSION, 5.6) {
    error("ImageFinder requires at least QtWebEngine 5.6!")
}

HEADERS += \
    imagefinderplugin.h \
    imagefinder.h \
    imagefindersettings.h \

SOURCES += \
    imagefinderplugin.cpp \
    imagefinder.cpp \
    imagefindersettings.cpp \

RESOURCES += imagefinder.qrc

FORMS += imagefindersettings.ui

PLUGIN_DIR = $$PWD
include(../../plugins.pri)
