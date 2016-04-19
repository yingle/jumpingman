#-------------------------------------------------
#
# Project created by QtCreator 2016-04-19T09:59:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jumpingman
TEMPLATE = app


SOURCES +=\
    board.cpp \
    game.cpp \
    myPlayer.cpp \
    main.cpp

HEADERS  += \
    game.h \
    window_size.h \
    board.h \
    myPlayer.h

FORMS    +=

RESOURCES += \
    res/res.qrc
