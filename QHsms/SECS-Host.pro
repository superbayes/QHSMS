#-------------------------------------------------
#
# Project created by QtCreator 2020-11-20T08:14:18
#
#-------------------------------------------------

QT       += core gui network
CONFIG += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SECSHostSim
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
        B3HsmsEQP.cpp \
        B3HsmsHostSim.cpp \
        HsmsDevice.cpp \
        HsmsEQP.cpp \
        HsmsHost.cpp \
        HsmsMessages.cpp \
        SECS2Item.cpp \
        main.cpp \
        dialog.cpp \
        mytcpserver.cpp

HEADERS += \
        B3HsmsEQP.h \
        B3HsmsHostSim.h \
        HsmsDevice.h \
        HsmsEQP.h \
        HsmsHost.h \
        HsmsMessages.h \
        SECS2Item.h \
        dialog.h \
        mytcpserver.h

FORMS += \
        dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
