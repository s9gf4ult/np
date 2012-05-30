#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H

#include "PeriodVisitor.h"

class TimePeriod {
public:
  /** Return pointer to QDateTime with next multiple time according to
      given time.
  */
  virtual QDateTime getNextTime(const QDateTime &) const = 0;

  /** Return pointer to new QDateTime with previous multiple time according
      to given time
  */
  virtual QDateTime getPrevTime(const QDateTime &) const = 0;
  virtual void accept(PeriodVisitor *) = 0;
};

#endif
