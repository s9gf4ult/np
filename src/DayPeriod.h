#ifndef DAYPERIOD_H
#define DAYPERIOD_H

#include "PeriodVisitor.h"
#include "TimePeriod.h"
#include <QDateTime>

class DayPeriod : public TimePeriod
{
public:
  DayPeriod();
  DayPeriod(const QDateTime &, int);
  virtual ~DayPeriod() {}
  virtual QDateTime getNextTime(const QDateTime &) const;
  virtual QDateTime getPrevTime(const QDateTime &) const;
  virtual void accept(PeriodVisitor *);
  virtual DayPeriod &setValue(int);
  virtual int getValue() const;
  virtual DayPeriod &setControlPoint(const QDateTime &);
  virtual const QDateTime &getControlPoint() const;
private:
  int Value;
  QDateTime ControlPoint;
};

#endif
