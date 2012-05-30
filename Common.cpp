
#include "Common.h"
#include <QDateTime>
#include <QTime>

void mSecsToZero(QDateTime *val) {
  QTime time = val.time();
  time.setHMS(time.hour(), time.minute(), second(), 0);
  val->setTime(time);
};

void secsToZero(QDateTime *val) {
  QTime time = val.time();
  time.setHMS(time.hour(), time.minute(), 0, 0);
  val->setTime(time);
};
