#ifndef CANDLESVECTOR_H
#define CANDLESVECTOR_H

#include <QVector>
#include "Candle.h"

class CandlesVector : public QVector<Candle> {
public:
  virtual Candle &getReduced();
};

#endif
