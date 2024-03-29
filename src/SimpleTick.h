#ifndef SIMPLETICK_H
#define SIMPLETICK_H

#include "ValueError.h"
#include <QDateTime>
#include "SharedCandle.h"
#include "CandleVisitor.h"

class SimpleTick : public SharedCandle {
public:
  SimpleTick(const QDateTime &, double cost, double volume);
  SimpleTick();
  SimpleTick(const SimpleTick &other);
  virtual ~SimpleTick() {}
  virtual SimpleTick &setVolume(double) throw(ValueError);
  virtual double getVolume() const;
  virtual SimpleTick &setCost(double) throw(ValueError);
  virtual double getCost() const;
  virtual SimpleTick &setTime(const QDateTime &);
  virtual QDateTime getDateTime() const;
  virtual double getOpenCost() const;
  virtual double getCloseCost() const;
  virtual double getLowCost() const;
  virtual double getHighCost() const;
  virtual QDateTime getOpenTime() const;
  virtual QDateTime getCloseTime() const;
  virtual void accept(CandleVisitor *visitor);
  virtual QString toString() const;
  virtual SharedCandle* cloneCandle() const ;
private:
  double Volume;
  double Cost;
  QDateTime Time;
};


#endif
