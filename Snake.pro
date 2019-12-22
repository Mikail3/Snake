#-------------------------------------------------
#
# Project created by QtCreator 2014-12-27T23:06:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
    apple.cpp \
    food.cpp \
    game.cpp \
    snake.cpp \
    strawberry.cpp

HEADERS  += \
    apple.h \
    food.h \
    game.h \
    snake.h \
    strawberry.h

FORMS    +=

DISTFILES += \
    food.png \
    images/food.png \
    images/food1.png \
    images/snake.png \
    snake.png

RESOURCES += \
    images.qrc
