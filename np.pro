######################################################################
# Automatically generated by qmake (2.01a) ?? ??? 15 15:48:53 2012
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += Candle.h Common.h CommonSystem.h CommonBot.h SystemSimulator.h \
           TimePeriod.h CommonError.h ValueError.h Tick.h \
    SecondsPeriod.h \
    Multiple60.h \
    Multiple24.h \
    MinutesPeriod.h \
    HourPeriod.h \
    DayPeriod.h \
    PeriodVisitor.h
SOURCES += Candle.cpp Main.cpp SystemSimulator.cpp CommonError.cpp Tick.cpp \
    SecondsPeriod.cpp \
    MinutesPeriod.cpp \
    HourPeriod.cpp \
    DayPeriod.cpp \
    Common.cpp \
    PeriodVisitor.cpp


QMAKE_CXXFLAGS_DEBUG += -pg -g3
QMAKE_LFLAGS_DEBUG += -pg -g3
