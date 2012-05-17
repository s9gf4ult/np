#include "Candle.h"
#include "CandlesVector.h"
#include <QtAlgorithms>
#include <QVector>
#include <algorithm>


Candle *CandlesVector::getReduced() {
  if (this->size() > 0) {
    qSort(*this);
    Candle f = this->first();
    Candle l = this->last();
    double mx = f.getLowCost();
    double mn = f.getHighCost();
    QVector<Candle>::const_iterator cnd = this->begin();
    for (; cnd != this->end(); ++cnd) {
      mx = std::max(mx, cnd->getHighCost());
      mn = std::min(mn, cnd->getLowCost());
    }
    
    return new Candle(f.getOpenCost(), l.getCloseCost(),
                      mn, mx,
                      f.getOpenTime(), l.getCloseTime());
  };
  return 0;
};
