#-------------------------------------------------
#
# Project created by QtCreator 2012-06-08T15:14:44
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    ../SimpleCandle.cpp \
    ../Candle.cpp \
    ../CommonError.cpp \
    main.cpp \
    tst_CandlesTests.cpp \
    tst_PeriodsTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

DEPENDPATH += ../
INCLUDEPATH += ../

HEADERS += \
    tst_CandlesTests.h \
    tst_PeriodsTests.h

