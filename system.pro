#-------------------------------------------------
#
# Project created by QtCreator 2023-02-28T16:46:03
#
#-------------------------------------------------
LIBS += -L$$PWD/lib -lsqlite3
QT += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OrderSystem
TEMPLATE = app


SOURCES += main.cpp\
    drink.cpp \
    e.cpp \
        mainwindow.cpp \
    login.cpp \
    sqlunit.cpp \
    table.cpp \
    adminmenu.cpp \
    order.cpp \
    menu.cpp \
    manager.cpp \
    clientlist.cpp \
    consume.cpp \
    customermenu.cpp \
    history.cpp \
    xiang.cpp

HEADERS  += mainwindow.h \
    drink.h \
    e.h \
    login.h \
    sqlite3.h \
    sqlunit.h \
    table.h \
    adminmenu.h \
    order.h \
    menu.h \
    manager.h \
    clientlist.h \
    consume.h \
    customermenu.h \
    history.h \
    xiang.h

FORMS    += mainwindow.ui \
    drink.ui \
    e.ui \
    login.ui \
    table.ui \
    adminmenu.ui \
    order.ui \
    menu.ui \
    manager.ui \
    clientlist.ui \
    consume.ui \
    customermenu.ui \
    history.ui \
    xiang.ui
