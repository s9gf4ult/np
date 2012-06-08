#ifndef ABSTRACTCANDLE_H
#define ABSTRACTCANDLE_H

#include <QDateTime>
#include <QString>
#include "CandleVisitor.h"

class AbstractCandle {
public:
    virtual double getOpenCost() const = 0;
    virtual double getCloseCost() const = 0;
    virtual double getLowCost() const = 0;
    virtual double getHighCost() const = 0;
    virtual double getVolume() const = 0;
    virtual QDateTime getOpenTime() const = 0;
    virtual QDateTime getCloseTime() const = 0;
    virtual void accept(CandleVisitor *) = 0;
    virtual QString toString() const = 0;
};

#endif // ABSTRACTCANDLE_H
