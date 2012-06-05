######################################################################
# Automatically generated by qmake (2.01a) ?? ??? 15 15:48:53 2012
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += Common.h CommonSystem.h CommonBot.h SystemSimulator.h \
           TimePeriod.h CommonError.h ValueError.h \
    SecondsPeriod.h \
    Multiple60.h \
    Multiple24.h \
    MinutesPeriod.h \
    HourPeriod.h \
    DayPeriod.h \
    PeriodVisitor.h \
    MonthPeriod.h \
    YearPeriod.h \
    AbstractCandle.h \
    CandleVisitor.h \
    AbstractHistorySource.h \
    PointersList.h \
    CSVHistorySource.h \
    SimpleTick.h \
    SimpleCandle.h \
    Candle.h
SOURCES += Main.cpp SystemSimulator.cpp CommonError.cpp \
    SecondsPeriod.cpp \
    MinutesPeriod.cpp \
    HourPeriod.cpp \
    DayPeriod.cpp \
    Common.cpp \
    MonthPeriod.cpp \
    YearPeriod.cpp \
    CVHistorySource.cpp \
    SimpleTick.cpp \
    SimpleCandle.cpp


QMAKE_CXXFLAGS_DEBUG += -pg -g3
QMAKE_LFLAGS_DEBUG += -pg -g3
