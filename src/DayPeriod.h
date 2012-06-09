#ifndef DAYPERIOD_H
#define DAYPERIOD_H

#include "PeriodVisitor.h"
#include "SharedPeriod.h"
#include <QDateTime>

class DayPeriod : public SharedPeriod
{
public:
  DayPeriod();
  DayPeriod(const QDateTime &, int);
  DayPeriod(const DayPeriod &other);
  virtual ~DayPeriod() {}
  virtual QDateTime getNextTime(const QDateTime) const;
  virtual QDateTime getPrevTime(const QDateTime) const;
  virtual void accept(PeriodVisitor *);
  virtual DayPeriod &setValue(int);
  virtual int getValue() const;
  virtual DayPeriod &setControlPoint(const QDateTime &);
  virtual const QDateTime &getControlPoint() const;
  virtual SharedPeriod *clonePeriod() const;
private:
  int Value;
  QDateTime ControlPoint;
};

#endif
