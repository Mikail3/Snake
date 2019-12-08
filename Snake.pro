QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
    button.cpp \
    food.cpp \
    game.cpp \
    main.cpp \
    movesnake.cpp \
    score.cpp \ \
    snakepart.cpp



HEADERS  += main.h \
    game.h \
    snakepart.h \
    movesnake.h \
    food.h \
    score.h \
    button.h

RESOURCES += \
    resources.qrc
