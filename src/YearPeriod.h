#ifndef YEARPERIOD_H
#define YEARPERIOD_H

#include "SharedPeriod.h"
#include "PeriodVisitor.h"
#include <QDateTime>

class YearPeriod : public SharedPeriod
{
public:
    YearPeriod();
    virtual ~YearPeriod() {}
    virtual QDateTime getNextTime(const QDateTime &) const;
    virtual QDateTime getPrevTime(const QDateTime &) const;
    virtual void accept(PeriodVisitor *);
    virtual SharedPeriod *clonePeriod() const;
};

#endif // YEARPERIOD_H
