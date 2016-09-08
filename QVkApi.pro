#-------------------------------------------------
#
# Project created by QtCreator 2016-08-18T19:02:55
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QVkApi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    abstractreply.cpp \
    abstractentity.cpp \
    vkapi.cpp

HEADERS  += mainwindow.h \
    user.h \
    abstractreply.h \
    abstractentity.h \
    app.h \
    vkapi.h

FORMS    += mainwindow.ui
