#ifndef CANDLE_H
#define CANDLE_H

#include "AbstractCandle.h"
#include <QSharedDataPointer>
#include <QSharedData>

//template<class T>
class Candle {
public:
    Candle(AbstractCandle *candle);
    Candle(const Candle &obj);
    virtual ~Candle() {}
    virtual double getOpenCost() const;
    virtual double getCloseCost() const;
    virtual double getLowCost() const;
    virtual double getHighCost() const;
    virtual double getVolume() const;
    virtual QDateTime getOpenTime() const;
    virtual QDateTime getCloseTime() const;
    virtual void accept(CandleVisitor *vis);
    virtual QString toString() const;

    QSharedDataPointer<AbstractCandle> value;
};



#endif // CANDLE_H
