#ifndef PERIOD_H
#define PERIOD_H

#include <QSharedDataPointer>
#include <QDateTime>
#include "PeriodVisitor.h"
#include "SharedPeriod.h"
#include "AbstractPeriod.h"

class Period : public AbstractPeriod
{
public:
    Period();
    Period(SharedPeriod* data);
    Period(const Period& other);
    virtual ~Period() {}

    virtual QDateTime getNextTime(const QDateTime) const;
    virtual QDateTime getPrevTime(const QDateTime) const;
    virtual void accept(PeriodVisitor *);
    virtual SharedPeriod *data();
    virtual const SharedPeriod *constData() const;
private:
    QSharedDataPointer<SharedPeriod> d;
};

#endif // PERIOD_H
