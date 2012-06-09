
#include "Common.h"
#include "HourPeriod.h"
#include "Multiple24.h"
#include "PeriodVisitor.h"

HourPeriod::HourPeriod() : Value(M24V1) {
}

HourPeriod::HourPeriod(Multiple24 val) : Value(val) {
}

HourPeriod::HourPeriod(const HourPeriod &other) : Value(other.Value)
{
}

QDateTime HourPeriod::getNextTime(const QDateTime qdt) const {
  QDateTime ret = qdt;
  minuteSetZero(&ret);
  int hour = ret.time().hour();
  int val = static_cast<int>(getValue());
  int append = val - (hour % val);
  return ret.addSecs(append * 3600);
};

QDateTime HourPeriod::getPrevTime(const QDateTime qdt) const {
  QDateTime ret = qdt;
  minuteSetZero(&ret);
  int hour = ret.time().hour();
  int val = static_cast<int>(getValue());
  int append = hour % val;
  append = 0 == append ? val : append;
  return ret.addSecs(-(append * 3600));
};

void HourPeriod::accept(PeriodVisitor *visitor) {
  visitor->visit(this);
};

HourPeriod & HourPeriod::setValue(Multiple24 val) {
  Value = val;
};

Multiple24 HourPeriod::getValue() const {
    return Value;
}

SharedPeriod *HourPeriod::clonePeriod() const
{
    return new HourPeriod(*this);
}
