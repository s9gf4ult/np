#ifndef CANDLE_H
#define CANDLE_H

#include "AbstractCandle.h"
#include <QSharedDataPointer>
#include <QSharedData>

template<class T>
class Candle {
public:
    Candle(T *candle) : value(candle) {

    }

    Candle(const Candle &obj) : value(obj.value) {

    }

    double getOpenCost() const {
        return value->getOpenCost();
    }

    double getCloseCost() const {
        return value->getCloseCost();
    }

    double getLowCost() const {
        return value->getLowCost();
    }

    double getHighCost() const {
        return value->getHighCost();
    }

    double getVolume() const {
        return value->getVolume();
    }

    const QDateTime &getOpenTime() const {
        return value->getOpenTime();
    }

    const QDateTime &getCloseTime() const {
        return value->getCloseTime();
    }

    void accept(CandleVisitor *vis) {
        value->accept(vis);
    }

     QString toString() {
        return value->toString();
    }

    QSharedDataPointer<T> value;
};

#endif // CANDLE_H
