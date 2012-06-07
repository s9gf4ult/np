#ifndef CANDLE_H
#define CANDLE_H

#include "AbstractCandle.h"
#include <QSharedDataPointer>
#include <QSharedData>

//template<class T>
class Candle {
public:
    Candle(AbstractCandle *candle) : value(candle) {

    }

    Candle(const Candle &obj) : value(obj.value) {

    }

    double getOpenCost() const {
        return value.data()->getOpenCost();
    }

    double getCloseCost() const {
        return value.data()->getCloseCost();
    }

    double getLowCost() const {
        return value.data()->getLowCost();
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
        return value.data()->getCloseTime();
    }

    void accept(CandleVisitor *vis) {
        value.data()->accept(vis);
    }

    QString toString() {
        return value.data()->toString();
    }

    QSharedDataPointer<AbstractCandle> value;
};

#endif // CANDLE_H
