#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T00:48:23
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = alphaWidget
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    AffdexThread.cpp \
    imglistener.cpp

HEADERS  += mainwindow.h \
    affdex.h \
    AffdexThread.h \
    imglistener.h

INCLUDEPATH +=  "D:/Affectiva/Affdex SDK/include/" \
                "F:/SRTP/alphatest/ffmpeg/include/"

LIBS += -LF:/SRTP/alphatest/ffmpeg/lib/ -lavformat \
        -LF:/SRTP/alphatest/ffmpeg/lib/ -lavcodec \
        -LF:/SRTP/alphatest/ffmpeg/lib/ -lavdevice \
        -LF:/SRTP/alphatest/ffmpeg/lib/ -lavfilter \
        -LF:/SRTP/alphatest/ffmpeg/lib/ -lavutil

release:LIBS += "D:/Affectiva/Affdex SDK/lib/release/affdex-native.lib"
debug:LIBS += "D:/Affectiva/Affdex SDK/lib/debug/affdex-native.lib"

FORMS    += mainwindow.ui
