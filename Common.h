#ifndef COMMON_H
#define COMMON_H

#include "SimpleCandle.h"
#include "Candle.h"
#include <QtAlgorithms>
#include <QtGlobal>

/** Set MSecs of QDateTime to zero
 */
void mSecsToZero(QDateTime *);

/** Set Seconds and MSeconds to zero
 */
void secsToZero(QDateTime *);

/** Set MSecs, Secs and Munute to zero
    in given QDateTime
*/
void minuteSetZero(QDateTime *);


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
Candle reduceCandleCollection(T collection){
  if (collection.size() > 0) {
    Candle a = collection.first();
    double mx = a.getHighCost();
    double mn = a.getLowCost();
    double oc = a.getOpenCost();
    double cc = a.getCloseCost();
    double volume = 0;
    QDateTime ot = a.getOpenTime();
    QDateTime ct = a.getCloseTime();
    
    
    typename T::const_iterator cnd = collection.begin();
    for (; cnd != collection.end(); ++cnd) {
        volume += cnd->getVolume();
        mx = qMax(mx, cnd->getHighCost());
        mn = qMin(mn, cnd->getLowCost());
        if (cnd->getOpenTime() < ot) {
            ot = cnd->getOpenTime();
            oc = cnd->getOpenCost();
        };
        if (cnd->getCloseTime() > ct) {
            ct = cnd->getCloseTime();
            cc = cnd->getCloseCost();
        }
    }
    
    return Candle(new SimpleCandle(oc, cc, mn, mx, volume, ot, ct));
  };
  return 0;
}



#endif
