# -------------------------------------------------
# Project created by QtCreator 2009-04-04T17:06:01
# -------------------------------------------------
QT += network
QT -= gui
TARGET = JagunKetServer
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
DEPENDPATH += ../JagunKetPackageInformation \
    ../JagunKet
INCLUDEPATH += ../JagunKetPackageInformation \
    ../JagunKet
SOURCES += main.cpp \
    jagunketserver.cpp \
    jagunpackageinformation.cpp \
    jagunket.cpp \
    jagunkettimer.cpp \
    jagunketsendcontroller.cpp \
    jagunketreceivecontroller.cpp \
    jagunketconnection.cpp \
    jagunketfragmentsend.cpp
HEADERS += jagunketserver.h \
    jagunpackageinformation.h \
    jagunket.h \
    jagunkettimer.h \
    jagunketsendcontroller.h \
    jagunketreceivecontroller.h \
    jagunketconnection.h \
    jagunketfragmentsend.h
