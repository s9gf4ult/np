#ifndef COMMON_H
#define COMMON_H

#include "Candle.h"
#include <QtAlgorithms>
#include <QtGlobal>

/** Set MSecs of QDateTime to zero
 */
void mSecsToZero(QDateTime *);

/** Set Seconds and MSeconds to zero
 */
void secsToZero(QDateTime *);


template <typename T>
int cmp(const T &a, const T &b) {
  if (a < b) {
    return -1;
  } else if (a == b) {
    return 0;
  } else {
    return 1;
  }
}

template <typename T>
Candle *reduceCandleCollection(const T &collection){
  if (collection.size() > 0) {
    Candle a = collection.first();
    double mx = a.getHighCost();
    double mn = a.getLowCost();
    double oc = a.getOpenCost();
    double cc = a.getCloseCost();
    QDateTime ot = a.getOpenTime();
    QDateTime ct = a.getCloseTime();
    
    
    typename T::const_iterator cnd = collection.begin();
    for (; cnd != collection.end(); ++cnd) {
      mx = qMax(mx, cnd->getHighCost());
      mn = qMin(mn, cnd->getLowCost());
      if (cnd->getOpenTime() < ot) {
        ot = cnd->getOpenTime();
        oc = cnd->getOpenCost();
      };
      if (cnd->getCloseTime() < ct) {
        ct = cnd->getCloseTime();
        cc = cnd->getCloseCost();
      }
    };
    
    return new Candle(oc, cc, mn, mx, ot, ct);
  };
  return 0;
};


#endif
