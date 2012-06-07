#include "DayPeriod.h"
#include <QDate>
#include <QDateTime>
#include <QTime>

DayPeriod::DayPeriod() :
  Value(1),
  ControlPoint(QDateTime(QDate(1900, 1, 1), QTime(0, 0))) {
};

DayPeriod::DayPeriod(const QDateTime &qdt, int value) : Value(value), ControlPoint(qdt) {
};

QDateTime DayPeriod::getNextTime(const QDateTime &qdt) const {
  QDateTime ret = qdt;
  int days = getControlPoint().daysTo(ret);
  int val = static_cast<int>(getValue());
  int append = val - (days % val);
  append = append >= 0 ? append : -append;
  return ret.addDays(append);
};

QDateTime DayPeriod::getPrevTime(const QDateTime &qdt) const {
  QDateTime ret = qdt;
  int days = getControlPoint().daysTo(ret);
  int val = static_cast<int>(getValue());
  int append = days % val;
  if (0 == append) {
    append = val;
  } else if (append < 0) {
    append = -append;
  };
  return ret.addDays( -append );
};

void DayPeriod::accept(PeriodVisitor *visitor) {
  visitor->visit(this);
};

DayPeriod & DayPeriod::setValue(int val) {
  Value = val;
  return *this;
}

int DayPeriod::getValue() const
{
    return this->Value;
}

DayPeriod & DayPeriod::setControlPoint(const QDateTime &qdt) {
  ControlPoint = qdt;
  return *this;
}

const QDateTime &DayPeriod::getControlPoint() const
{
    return this->ControlPoint;
}


