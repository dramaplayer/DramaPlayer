#-------------------------------------------------
#
# Project created by QtCreator 2014-01-04T00:23:35
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DramaPlayer
TEMPLATE = app


SOURCES += main.cpp \
    MediaListCtrl.cpp \
    DramaPlayer.cpp \
    Player.cpp \
    Button.cpp \
    CloseButton.cpp \
    MinimizeButton.cpp \
    PortraitButton.cpp \
    PreviouseButton.cpp \
    PlayOrPauseButton.cpp \
    NextButton.cpp \
    SeekSlider.cpp \
    VolumeSlider.cpp

HEADERS  += \
    MediaListCtrl.h \
    MediaBaiscInfo.h \
    DramaPlayer.h \
    Player.h \
    Button.h \
    CloseButton.h \
    MinimizeButton.h \
    PortraitButton.h \
    PreviouseButton.h \
    PlayOrPauseButton.h \
    NextButton.h \
    SeekSlider.h \
    VolumeSlider.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    resource.qrc

