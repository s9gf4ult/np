#include "Candle.h"
#include "CandlesVector.h"
#include <QList>
#include <QtAlgorithms>
#include <QtGlobal>


Candle *CandlesVector::getReduced() {
  if (this->size() > 0) {
    Candle a = this->first();
    double mx = a.getHighCost();
    double mn = a.getLowCost();
    double oc = a.getOpenCost();
    double cc = a.getCloseCost();
    QDateTime *ot = a.getOpenTime();
    QDateTime *ct = a.getCloseTime();
    
    
    QList<Candle>::const_iterator cnd = this->begin();
    for (; cnd != this->end(); ++cnd) {
      mx = qMax(mx, cnd->getHighCost());
      mn = qMin(mn, cnd->getLowCost());
      if (*cnd->getOpenTime() < *ot) {
        ot = cnd->getOpenTime();
        oc = cnd->getOpenCost();
      };
      if (*cnd->getCloseTime() < *ct) {
        ct = cnd->getCloseTime();
        cc = cnd->getCloseCost();
      }
    };
    
    return new Candle(oc, cc, mn, mx, ot, ct);
  };
  return 0;
};
