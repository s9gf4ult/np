#ifndef PERIODVISITOR_H
#define PERIODVISITOR_H

#include "SecondsPeriod.h"
#include "MinutesPeriod.h"
#include "HourPeriod.h"
#include "DayPeriod.h"

class PeriodVisitor
{
public:
    virtual visit(SecondsPeriod *) = 0;
    virtual visit(MinutesPeriod *) = 0;
    virtual visit(HourPeriod *) = 0;
    virtual visit(DayPeriod *) = 0;

};

#endif // PERIODVISITOR_H
