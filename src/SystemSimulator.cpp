#include "SystemSimulator.h"
#include "Period.h"
#include <QList>
#include <QString>

SystemSimulator::SystemSimulator(const QString &ticket,
                                 const QList<SimpleCandle> &candles):
  ticket(ticket), candles(candles), subscribed(false) {
};

QList<QString> * SystemSimulator::getTicketsList() const {
  QList<QString> *ret = new QList<QString>();
  ret->append(this->ticket);
  return ret;
};

QList<SimpleCandle> * SystemSimulator::getCandles(const QString &ticket,
                                            const SharedPeriod &period,
                                            const QDateTime &begin,
                                            const QDateTime &end) const {
  return new QList<SimpleCandle>(this->candles);
}

void SystemSimulator::subscribe(const QString &ticket) {
};

void SystemSimulator::unsubscribe(const QString &ticket) {
};

QList<QString> *SystemSimulator::getSubscripted() const {
  QList<QString> *ret = new QList<QString>();
  ret->append(this->ticket);
  return ret;
}
  
