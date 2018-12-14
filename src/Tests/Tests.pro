QT += widgets testlib multimedia multimediawidgets

CONFIG += qt console warn_on depend_includepath testcase

TEMPLATE = app

HEADERS = \
   ../MediaPlayer/mainwindow.h \
   ../MediaPlayer/mediaplayer.h \
   ../MediaPlayer/mediawidget.h

SOURCES = \
    testmediaplayer.cpp \
    ../MediaPlayer/main.cpp \
    ../MediaPlayer/mainwindow.cpp \
    ../MediaPlayer/mainwindow.cpp \
    ../MediaPlayer/mediaplayer.cpp \
    ../MediaPlayer/mediawidget.cpp \
    ../MediaPlayer/MediaPlayer.pro

