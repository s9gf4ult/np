#ifndef TICK_H
#define TICK_H

#include "ValueError.h"
#include <QDateTime>
#include "AbstractCandle.h"
#include "CandleVisitor.h"

class Tick : public AbstractCandle {
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
  virtual double getOpenCost() const;
  virtual double getCloseCost() const;
  virtual double getLowCost() const;
  virtual double getHighCost() const;
  virtual const QDateTime &getOpenTime() const;
  virtual const QDateTime &getCloseTime() const;
  virtual void accept(CandleVisitor *visitor);
private:
  double Volume;
  double Cost;
  QDateTime Time;
};


#endif
