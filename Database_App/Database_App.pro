#-------------------------------------------------
#
# Project created by QtCreator 2017-08-02T14:05:31
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Database_App
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        login_window.cpp \
    db_connection.cpp \
    teaminfo.cpp \
    tableview.cpp \
    teamsrecord.cpp

HEADERS += \
        login_window.h \
    db_connection.h \
    teaminfo.h \
    tableview.h \
    teamsrecord.h

FORMS += \
    Login_Window.ui \
    teaminfo.ui \
    tableview.ui \
    teamsrecord.ui
