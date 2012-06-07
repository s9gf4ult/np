#include "Candle.h"
#include <QTextStream>

template <>
AbstractCandle* QSharedDataPointer<AbstractCandle>::clone() {
    QTextStream out(stdout);
    out << "copy candle\n";
    out.flush();
    return d->cloneCandle();
}


Candle::Candle(AbstractCandle *candle) : value(candle) {

}

Candle::Candle(const Candle &obj) : value(obj.value) {

}

double Candle::getOpenCost() const {
    return value.constData()->getOpenCost();
}

double Candle::getCloseCost() const {
    return value.constData()->getCloseCost();
}

double Candle::getLowCost() const {
    return value.constData()->getLowCost();
}

double Candle::getHighCost() const {
    return value.constData()->getHighCost();
}

double Candle::getVolume() const {
    return value.constData()->getVolume();
}

QDateTime Candle::getOpenTime() const {
    return value.constData()->getOpenTime();
}

QDateTime Candle::getCloseTime() const {
    return value.constData()->getCloseTime();
}

void Candle::accept(CandleVisitor *vis) {
    value.data()->accept(vis);
}

QString Candle::toString() const {
    return value.constData()->toString();
}
