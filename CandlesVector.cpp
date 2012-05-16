#include "Candle.h"
#include "CandlesVector.h"
#include <QtAlgorithms>
#include <algorithm>


Candle &CandlesVector::getReduced() {
  if (this->size() > 0) {
    qSort(*this);
    Candle f = this->first();
    Candle l = this->last();
    double mx = f.getLowCost();
    double mn = f.getHighCost();
    Candle cnd;
    foreach(cnd, *this) {
      mx = max(cnd.getHighCost(), mx);
      mn = min(cnd.getLowCost(), mn);
    };
    return *(new Candle(f.getOpenCost, l.getCloseCost,
                        mn, mx,
                        new DateTime(*f.getOpenTime()),
                        new DateTime(*f.getCloseTime())));
  };
};
