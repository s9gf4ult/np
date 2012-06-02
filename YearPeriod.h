#ifndef YEARPERIOD_H
#define YEARPERIOD_H

#include "TimePeriod.h"
#include "PeriodVisitor.h"
#include <QDateTime>

class YearPeriod : public TimePeriod
{
public:
    YearPeriod();
    virtual ~YearPeriod() {}
    virtual QDateTime getNextTime(const QDateTime &) const;
    virtual QDateTime getPrevTime(const QDateTime &) const;
    virtual void accept(PeriodVisitor *);
};

#endif // YEARPERIOD_H
