#ifndef MINUTESPERIOD_H
#define MINUTESPERIOD_H

#include "SharedPeriod.h"
#include "Multiple60.h"

class MinutesPeriod : public SharedPeriod
{
public:
  MinutesPeriod();
  explicit MinutesPeriod(Multiple60);
  explicit MinutesPeriod(const MinutesPeriod &other);
  virtual ~MinutesPeriod() {}
  virtual QDateTime getNextTime(const QDateTime) const;
  virtual QDateTime getPrevTime(const QDateTime) const;
  virtual void accept(PeriodVisitor *);
  virtual MinutesPeriod &setValue(Multiple60);
  virtual Multiple60 getValue() const;
  virtual SharedPeriod* clonePeriod() const;
private:
  Multiple60 Value;
};

#endif
