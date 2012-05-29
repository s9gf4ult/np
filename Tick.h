#ifndef TICK_H
#define TICK_H

#include "ValueError.h"
#include <QDateTime>

class Tick {
public:
  Tick(const QDateTime &, double cost, double volume);
  Tick();
  virtual ~Tick() {};
  virtual Tick &setVolume(double) throw(ValueError);
  virtual double getVolume() const;
  virtual Tick &setCost(double) throw(ValueError);
  virtual double getCost() const;
  virtual Tick &setTime(const QDateTime &);
  virtual const QDateTime &getDateTime() const;

private:
  double Volume;
  double Cost;
  QDateTime Time;
};


#endif
