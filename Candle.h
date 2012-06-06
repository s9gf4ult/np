#ifndef CANDLE_H
#define CANDLE_H

#include "AbstractCandle.h"
#include <QSharedPointer>

template<class T>
class Candle : public AbstractCandle {
public:
    Candle(T *candle) : value(candle) {

    }

    virtual double getOpenCost() const {
        return value->getOpenCost();
    }

    virtual double getCloseCost() const {
        return value->getCloseCost();
    }

    virtual double getLowCost() const {
        return value->getLowCost();
    }

    virtual double getHighCost() const {
        return value->getHighCost();
    }

    virtual double getVolume() const {
        return value->getVolume();
    }

    virtual const QDateTime &getOpenTime() const {
        return value->getOpenTime();
    }

    virtual const QDateTime &getCloseTime() const {
        return value->getCloseTime();
    }

    virtual void accept(CandleVisitor *vis) {
        value->accept(vis);
    }

    virtual QString toString() {
        return value->toString();
    }

    QSharedPointer<T> value;
};

#endif // CANDLE_H
