#ifndef MONTHPERIOD_H
#define MONTHPERIOD_H

#include <QDateTime>
#include "SharedPeriod.h"

class MonthPeriod : public SharedPeriod
{
public:
    MonthPeriod();
    virtual ~MonthPeriod() {}
    virtual QDateTime getNextTime(const QDateTime) const;
    virtual QDateTime getPrevTime(const QDateTime) const;
    virtual void accept(PeriodVisitor *);
    virtual SharedPeriod *clonePeriod() const;
};

#endif // MONTHPERIOD_H
