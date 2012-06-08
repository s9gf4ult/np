#include "Candle.h"
#include "Common.h"
#include <QTextStream>

template <>
SharedCandle* QSharedDataPointer<SharedCandle>::clone() {
    return d->cloneCandle();
}


Candle::Candle(SharedCandle *candle) : d(candle) {

}

Candle::Candle(const Candle &obj) : d(obj.d) {

}

double Candle::getOpenCost() const {
    return d.constData()->getOpenCost();
}

double Candle::getCloseCost() const {
    return d.constData()->getCloseCost();
}

double Candle::getLowCost() const {
    return d.constData()->getLowCost();
}

double Candle::getHighCost() const {
    return d.constData()->getHighCost();
}

double Candle::getVolume() const {
    return d.constData()->getVolume();
}

QDateTime Candle::getOpenTime() const {
    return d.constData()->getOpenTime();
}

QDateTime Candle::getCloseTime() const {
    return d.constData()->getCloseTime();
}

void Candle::accept(CandleVisitor *vis) {
    d.data()->accept(vis);
}

QString Candle::toString() const {
    return d.constData()->toString();
}

int compare(const Candle first, const Candle second)
{
    int c1 = cmp(first.getOpenTime(), second.getOpenTime());
    if (c1 != 0) {
        return c1;
    }
    return cmp(first.getCloseTime(), second.getCloseTime());
}

bool Candle::isValid() const {
    double oc = getOpenCost();
    double cc = getCloseCost();
    double high = getHighCost();
    double low = getLowCost();
    double volume = getVolume();
    QDateTime ot = getOpenTime();
    QDateTime ct = getCloseTime();

    return ((low <= high) &&
            (oc <= high) && (oc >= low) &&
            (cc <= high) && (cc >= low) &&
            (volume >= 0) &&
            (ot <= ct) &&
            (low >= 0));
}

Candle::CandleColor Candle::getColor() const
{
    double oc = getOpenCost();
    double cc = getCloseCost();
    if (oc == cc) {
        return GRAY;
    } else if (oc < cc) {
        return GREEN;
    } else {
        return RED;
    }
}

bool Candle::operator ==(const Candle &other) const
{
    return ((getOpenCost() == other.getOpenCost()) &&
            (getCloseCost() == other.getCloseCost()) &&
            (getLowCost() == other.getLowCost()) &&
            (getHighCost() == other.getHighCost()) &&
            (getVolume() == other.getVolume()) &&
            (getOpenTime() == other.getOpenTime()) &&
            (getCloseTime() == other.getCloseTime()));
}

bool Candle::operator !=(const Candle &other) const
{
    return ! (*this == other);
}

SharedCandle *Candle::data()
{
    return d.data();
}

const SharedCandle *Candle::constData() const
{
    return d.constData();
}
