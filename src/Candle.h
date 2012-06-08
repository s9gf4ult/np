#ifndef CANDLE_H
#define CANDLE_H

#include "AbstractCandle.h"
#include "SharedCandle.h"
#include <QSharedDataPointer>
#include <QSharedData>

//template<class T>
class Candle : public AbstractCandle {
public:
    enum CandleColor
    {RED = -1,
     GRAY = 0,
     GREEN = 1};

    Candle(SharedCandle *candle);
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
    virtual bool isValid() const;
    virtual CandleColor getColor() const;
    virtual bool operator==(const Candle &) const;
    virtual bool operator!=(const Candle &) const;
    virtual SharedCandle* data();
    virtual const SharedCandle *constData() const;
private:
    QSharedDataPointer<SharedCandle> d;
};

int compare(const Candle first, const Candle second);


#endif // CANDLE_H
