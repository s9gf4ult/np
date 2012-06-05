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



private:
    QSharedPointer<T> value;
};

#endif // CANDLE_H
