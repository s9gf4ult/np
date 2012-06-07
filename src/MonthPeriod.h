#ifndef MONTHPERIOD_H
#define MONTHPERIOD_H

#include <QDateTime>
#include "TimePeriod.h"

class MonthPeriod : public TimePeriod
{
public:
    MonthPeriod();
    virtual ~MonthPeriod() {}
    virtual QDateTime getNextTime(const QDateTime &) const;
    virtual QDateTime getPrevTime(const QDateTime &) const;
    virtual void accept(PeriodVisitor *);
};

#endif // MONTHPERIOD_H
