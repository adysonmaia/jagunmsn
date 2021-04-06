#-------------------------------------------------
#
# Project created by QtCreator 2009-04-11T10:40:02
#
#-------------------------------------------------

QT       += network

TARGET = JagunKETGuiTest
TEMPLATE = app
DEPENDPATH += ../JagunKetPackageInformation \
              ../JagunKet
INCLUDEPATH += ../JagunKetPackageInformation \
              ../JagunKet
SOURCES += main.cpp\
        mainwindow.cpp \
        jagunketsendcontroller.cpp \
        jagunketreceivecontroller.cpp \
        jagunket.cpp \
        jagunpackageinformation.cpp \
        jagunkettimer.cpp \
        jagunketfragmentsend.cpp

HEADERS  += mainwindow.h \
            jagunketsendcontroller.h \
            jagunketreceivecontroller.h \
            jagunket.h \
            jagunpackageinformation.h \
            jagunkettimer.h \
            jagunketfragmentsend.h

FORMS    += mainwindow.ui
