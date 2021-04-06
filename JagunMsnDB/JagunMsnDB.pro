# -------------------------------------------------
# Project created by QtCreator 2009-04-21T17:35:45
# -------------------------------------------------
QT += network \
    sql \
    xml
QT -= gui
TARGET = JagunMsnDB
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
DEPENDPATH += ../JagunKetPackageInformation \
    ../JagunKet \
    ../JagunKetServer \
    ../JagunParser \
    ../JagunMSNClient
INCLUDEPATH += ../JagunKetPackageInformation \
    ../JagunKet \
    ../JagunKetServer \
    ../JagunParser \
    ../JagunMSNClient
SOURCES += main.cpp \
    jagunmsncontact.cpp \
    jagundb.cpp
HEADERS += jagundb.h \
    jagunmsncontact.h
RESOURCES += 
