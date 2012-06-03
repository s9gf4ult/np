#ifndef ABSTRACTCANDLE_H
#define ABSTRACTCANDLE_H

#include <QDateTime>

class AbstractCandle
{
public:
    virtual double getOpenCost() const = 0;
    virtual double getCloseCost() const = 0;
    virtual double getLowCost() const = 0;
    virtual double getHighCost() const = 0;
    virtual double getVolume() const = 0;
    virtual const QDateTime &getOpenTime() const = 0;
    virtual const QDateTime &getCloseTime() const = 0;
};

#endif // ABSTRACTCANDLE_H
