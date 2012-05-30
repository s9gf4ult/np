#ifndef SECONDSPERIOD_H
#define SECONDSPERIOD_H

#include "Multiple60.h"
#include "PeriodVisitor.h"
#include "TimePeriod.h"
#include <QDateTime>

class SecondsPeriod : public TimePeriod {
public:
  SecondsPeriod();
  SecondsPeriod(Multiple60);
  virtual ~SecondsPeriod() {};
  virtual QDateTime getNextTime(const QDateTime &) const;
  virtual QDateTime getPrevTime(const QDateTime &) const;
  virtual void accept(PeriodVisitor *);
  virtual SecondsPeriod &setValue(Multiple60);
  virtual Multiple60 getValue() const;
private:
  Multiple60 Value;
};

#endif
