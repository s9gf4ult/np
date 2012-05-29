#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H

class TimePeriod {
public:
  virtual QDateTime &getNextTime(const QDateTime &) const;
  virtual QDateTime &getPrevTime(const QDateTime &) const;
};

#endif
