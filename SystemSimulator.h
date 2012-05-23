#ifndef SYSTEMSIMULATOR_H
#define SYSTEMSIMULATOR_H

#include "Candle.h"
#include "CommonSystem.h"
#include <QList>
#include <QString>

class SystemSimulator : public CommonSystem {
  QString ticket;
  QList<Candle> candles;
  
  
};

#endif
