#ifndef ABSTRACTPERIOD_H
#define ABSTRACTPERIOD_H

class AbstractPeriod {
public:
    virtual QDateTime getNextTime(const QDateTime) const = 0;
    virtual QDateTime getPrevTime(const QDateTime) const = 0;
    virtual void accept(PeriodVisitor *) = 0;
};

#endif // ABSTRACTPERIOD_H
