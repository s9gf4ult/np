#ifndef ABSTRACTCANDLE_H
#define ABSTRACTCANDLE_H

#include <QDateTime>
#include <QSharedData>
#include "CandleVisitor.h"



class AbstractCandle : public QSharedData
{
public:
    virtual double getOpenCost() const = 0;
    virtual double getCloseCost() const = 0;
    virtual double getLowCost() const = 0;
    virtual double getHighCost() const = 0;
    virtual double getVolume() const = 0;
    virtual const QDateTime &getOpenTime() const = 0;
    virtual const QDateTime &getCloseTime() const = 0;
    virtual void accept(CandleVisitor *) = 0;
    virtual QString toString() = 0;
    virtual AbstractCandle* cloneCandle() const = 0;
};

template <>
AbstractCandle* QSharedDataPointer<AbstractCandle>::clone() {
    return this->data()->cloneCandle();
}

#endif // ABSTRACTCANDLE_H
