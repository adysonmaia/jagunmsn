# -------------------------------------------------
# Project created by QtCreator 2009-04-22T08:17:59
# -------------------------------------------------
QT += network \
    sql \
    xml
QT -= gui

TARGET = JagunMSNServer
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
DEPENDPATH += ../JagunKetPackageInformation \
    ../JagunKet \
    ../JagunKetServer \
    ../JagunParser \
    ../JagunMSNClient \
    ../JagunMsnDB
INCLUDEPATH += ../JagunKetPackageInformation \
    ../JagunKet \
    ../JagunKetServer \
    ../JagunParser \
    ../JagunMSNClient \
    ../JagunMsnDB
SOURCES +=  jagunket.cpp \
    jagunketserver.cpp \
    jagunketconnection.cpp \
    jagunketfragmentsend.cpp \
    jagunketreceivecontroller.cpp \
    jagunketsendcontroller.cpp \
    jagunkettimer.cpp \
    jagunpackageinformation.cpp \
    jagunparserfromxml.cpp \
    jagunparsertoxml.cpp \
    jagunparsermessageinformation.cpp \
    jagunmsnconnection.cpp \
    jagunmsnserver.cpp \
    jagunmsncontact.cpp \
    jagundb.cpp

HEADERS += jagunket.h \
    jagunketserver.h \
    jagunketconnection.h \
    jagunketfragmentsend.h \
    jagunketreceivecontroller.h \
    jagunketsendcontroller.h \
    jagunkettimer.h \
    jagunpackageinformation.h \
    jagunparserfromxml.h \
    jagunparsertoxml.h \
    jagunparsermessageinformation.h \
    jagunmsnconnection.h \
    jagunmsnserver.h \
    jagunmsncontact.h \
    jagundb.h


SOURCES += main.cpp
