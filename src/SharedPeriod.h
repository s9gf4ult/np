#ifndef SHAREDPERIOD_H
#define SHAREDPERIOD_H

#include <QDateTime>
#include <QSharedData>
#include "AbstractPeriod.h"

class PeriodVisitor;

class SharedPeriod : public QSharedData, public AbstractPeriod
{
public:
    virtual SharedPeriod *clonePeriod() const = 0;
};

#endif
