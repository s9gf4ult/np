#ifndef SYSTEMSIMULATOR_H
#define SYSTEMSIMULATOR_H

#include "Candle.h"
#include "CommonSystem.h"
#include "TimePeriod.h"
#include <QList>
#include <QString>

class SystemSimulator : public CommonSystem {
  QString ticket;
  QList<Candle> candles;
  bool subscribed;

public:
  SystemSimulator(const QString &,
                  const QList<Candle> &);
  
  virtual QList<QString> * getTicketsList() const;
  virtual QList<Candle> * getCandles(const QString &,
                                     const TimePeriod &,
                                     const QDateTime &,
                                     const QDateTime &) const;
  virtual void subscribe(const QString &);
  virtual void unsubscribe(const QString &);
  virtual QList<QString> * getSubscripted() const;
                                     
  
};

#endif
