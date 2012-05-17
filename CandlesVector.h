#ifndef CANDLESVECTOR_H
#define CANDLESVECTOR_H

#include <QList>
#include "Candle.h"

class CandlesVector : public QList<Candle> {
public:
  virtual Candle *getReduced();
};

#endif
