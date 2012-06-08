#ifndef HOURPERIOD_H
#define HOURPERIOD_H

#include "Multiple24.h"
#include "SharedPeriod.h"
#include "PeriodVisitor.h"
#include <QDateTime>


class HourPeriod : public SharedPeriod {
public:
  HourPeriod();
  explicit HourPeriod(Multiple24);
  explicit HourPeriod(const HourPeriod &other);
  virtual ~HourPeriod() {}
  virtual QDateTime getNextTime(const QDateTime &) const;
  virtual QDateTime getPrevTime(const QDateTime &) const;
  virtual void accept(PeriodVisitor *);
  virtual HourPeriod & setValue(Multiple24);
  virtual Multiple24 getValue() const;
  virtual SharedPeriod *clonePeriod() const;
private:
  Multiple24 Value;
};

#endif
