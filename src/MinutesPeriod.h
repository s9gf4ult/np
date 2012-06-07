#ifndef MINUTESPERIOD_H
#define MINUTESPERIOD_H

#include "TimePeriod.h"
#include "Multiple60.h"

class MinutesPeriod : public TimePeriod
{
public:
  MinutesPeriod();
  explicit MinutesPeriod(Multiple60);
  virtual ~MinutesPeriod() {}
  virtual QDateTime getNextTime(const QDateTime &) const;
  virtual QDateTime getPrevTime(const QDateTime &) const;
  virtual void accept(PeriodVisitor *);
  virtual MinutesPeriod &setValue(Multiple60);
  virtual Multiple60 getValue() const;
private:
  Multiple60 Value;
};

#endif
