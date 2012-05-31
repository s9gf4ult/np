#ifndef HOURPERIOD_H
#define HOURPERIOD_H

#include "Multiple24.h"
#include "TimePeriod.h"
#include "PeriodVisitor.h"
#include <QDateTime>


class HourPeriod : public TimePeriod {
public:
  HourPeriod();
  explicit HourPeriod(Multiple24);
  virtual ~HourPeriod() {};
  virtual QDateTime getNextTime(const QDateTime &) const;
  virtual QDateTime getPrevTime(const QDateTime &) const;
  virtual void accept(PeriodVisitor *);
  virtual HourPeriod & setValue(Multiple24);
  virtual Multiple24 getValue() const;
private:
  Multiple24 Value;
};

#endif
