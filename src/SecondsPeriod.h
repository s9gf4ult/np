#ifndef SECONDSPERIOD_H
#define SECONDSPERIOD_H

#include "Multiple60.h"
#include "PeriodVisitor.h"
#include "SharedPeriod.h"
#include <QDateTime>

class SecondsPeriod : public SharedPeriod {
public:
  SecondsPeriod();
  explicit SecondsPeriod(Multiple60);
  explicit SecondsPeriod(const SecondsPeriod& other);
  virtual ~SecondsPeriod() {}
  virtual QDateTime getNextTime(const QDateTime &) const;
  virtual QDateTime getPrevTime(const QDateTime &) const;
  virtual void accept(PeriodVisitor *);
  virtual SecondsPeriod &setValue(Multiple60);
  virtual Multiple60 getValue() const;
  virtual SharedPeriod* clonePeriod() const;
private:
  Multiple60 Value;
};

#endif
