#include "SystemSimulator.h"
#include "TimePeriod.h"
#include <QList>
#include <QString>

SystemSimulator::SystemSimulator(const QString &ticket,
                                 const QList<Candle> &candles):
  ticket(ticket), candles(candles), subscribed(false) {
};

QList<QString> * SystemSimulator::getTicketsList() const {
  QList<QString> *ret = new QList<QString>();
  ret->append(this->ticket);
  return ret;
};

QList<Candle> * SystemSimulator::getCandles(const QString &ticket,
                                            const TimePeriod &period,
                                            const QDateTime &begin,
                                            const QDateTime &end) const {
  return new QList<Candle>(this->candles);
}

void SystemSimulator::subscribe(const QString &ticket) {
}

  
