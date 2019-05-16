#-------------------------------------------------
#
# Project created by QtCreator 2019-05-15T13:20:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gstreamer_and_qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

win32{
GSTREAMER_PATH = ../../3rdLibs/gstreamer/1.0/x86_64

INCLUDEPATH += $${GSTREAMER_PATH}/include/gstreamer-1.0
INCLUDEPATH += $${GSTREAMER_PATH}/include/glib-2.0
INCLUDEPATH += $${GSTREAMER_PATH}/lib/glib-2.0/include

INCLUDEPATH += ../../3rdLibs/boost/boost_1_69_0

LIBS += $${GSTREAMER_PATH}/lib/gobject-2.0.lib
LIBS += $${GSTREAMER_PATH}/lib/glib-2.0.lib
LIBS += $${GSTREAMER_PATH}/lib/gstreamer-1.0.lib
LIBS += $${GSTREAMER_PATH}/lib/gstvideo-1.0.lib
}

SOURCES += \
    simplest_video_player.cpp \
        main.cpp

HEADERS += \
    simplest_video_player.hpp

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
