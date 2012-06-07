
#include "Common.h"
#include "Multiple60.h"
#include "SecondsPeriod.h"
#include <QDateTime>

SecondsPeriod::SecondsPeriod() : Value(M60V1) {
}

SecondsPeriod::SecondsPeriod(Multiple60 val) : Value(val) {
}

QDateTime SecondsPeriod::getNextTime(const QDateTime &qdt) const {
  QDateTime newd = qdt;
  mSecsToZero(&newd);
  int second = newd.time().second();
  int val = static_cast<int>(getValue());
  int append = val - (second % val);
  return newd.addSecs(append);
}

QDateTime SecondsPeriod::getPrevTime(const QDateTime &qdt) const {
  QDateTime newd = qdt;
  mSecsToZero(&newd);
  int second = newd.time().second();
  int val = static_cast<int>(getValue());
  int append = second % val;
  append = 0 == append ? Value : append;
  return newd.addSecs(-append);
}

void SecondsPeriod::accept(PeriodVisitor *visitor) {
  visitor->visit(this);
}

SecondsPeriod &SecondsPeriod::setValue(Multiple60 val) {
  Value = val;
  return *this;
}

Multiple60 SecondsPeriod::getValue() const {
  return Value;
}
