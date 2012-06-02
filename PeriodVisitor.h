#ifndef PERIODVISITOR_H
#define PERIODVISITOR_H

class SecondsPeriod;
class MinutesPeriod;
class HourPeriod;
class DayPeriod;
class MonthPeriod;
class YearPeriod;

class PeriodVisitor
{
public:
    virtual void visit(SecondsPeriod *) = 0;
    virtual void visit(MinutesPeriod *) = 0;
    virtual void visit(HourPeriod *) = 0;
    virtual void visit(DayPeriod *) = 0;
    virtual void visit(MonthPeriod *) = 0;
    virtual void visit(YearPeriod *) = 0;
};

#include "SecondsPeriod.h"
#include "MinutesPeriod.h"
#include "HourPeriod.h"
#include "DayPeriod.h"
#include "MonthPeriod.h"
#include "YearPeriod.h"

#endif // PERIODVISITOR_H
