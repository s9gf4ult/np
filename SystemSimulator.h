#ifndef SYSTEMSIMULATOR_H
#define SYSTEMSIMULATOR_H

#include "SimpleCandle.h"
#include "CommonSystem.h"
#include "TimePeriod.h"
#include <QList>
#include <QString>

class SystemSimulator : public CommonSystem {
  QString ticket;
  QList<SimpleCandle> candles;
  bool subscribed;

public:
  SystemSimulator(const QString &,
                  const QList<SimpleCandle> &);
  
  virtual QList<QString> * getTicketsList() const;
  virtual QList<SimpleCandle> * getCandles(const QString &,
                                     const TimePeriod &,
                                     const QDateTime &,
                                     const QDateTime &) const;
  virtual void subscribe(const QString &);
  virtual void unsubscribe(const QString &);
  virtual QList<QString> * getSubscripted() const;
                                     
  
};

#endif
