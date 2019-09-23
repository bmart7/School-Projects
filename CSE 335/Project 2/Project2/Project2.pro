#-------------------------------------------------
#
# Project created by QtCreator 2019-04-22T12:42:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
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

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    item.cpp \
    technology.cpp \
    bundle.cpp \
    technologybuilder.cpp \
    bundlebuilder.cpp \
    techfilereader.cpp \
    bundlefilereader.cpp \
    visitor.cpp \
    sumvisitor.cpp \
    savingsvisitor.cpp

HEADERS += \
        mainwindow.h \
    item.h \
    technology.h \
    bundle.h \
    technologybuilder.h \
    bundlebuilder.h \
    techfilereader.h \
    bundlefilereader.h \
    visitor.h \
    sumvisitor.h \
    savingsvisitor.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
