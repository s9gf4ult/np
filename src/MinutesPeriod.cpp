#include "MinutesPeriod.h"
#include "Common.h"

MinutesPeriod::MinutesPeriod() :
  Value(M60V1) {
}

MinutesPeriod::MinutesPeriod(Multiple60 val) : Value(val) {
}

MinutesPeriod::MinutesPeriod(const MinutesPeriod &other) : Value(other.Value)
{
}

QDateTime MinutesPeriod::getNextTime(const QDateTime qdt) const {
  QDateTime ret = qdt;
  secsToZero(&ret);
  int minute = ret.time().minute();
  int val = static_cast<int>(getValue());
  int append = val - (minute % val);
  return ret.addSecs(append * 60);
};

QDateTime MinutesPeriod::getPrevTime(const QDateTime qdt) const {
  QDateTime ret = qdt;
  secsToZero(&ret);
  int minute = ret.time().minute();
  int val = static_cast<int>(getValue());
  int append = (minute % val);
  append = 0 == append ? val : append;
  return ret.addSecs(-(append * 60));
};

void MinutesPeriod::accept(PeriodVisitor *visitor) {
  visitor->visit(this);
};

MinutesPeriod & MinutesPeriod::setValue(Multiple60 val) {
  Value = val;
  return *this;
};

Multiple60 MinutesPeriod::getValue() const {
    return Value;
}

SharedPeriod *MinutesPeriod::clonePeriod() const
{
    return new MinutesPeriod(*this);
};
