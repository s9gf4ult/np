#ifndef CANDLE_H
#define CANDLE_H

#include "ValueError.h"
#include <QDateTime>
#include <QObject>
#include <QSharedPointer>
#include "AbstractCandle.h"
#include "CandleVisitor.h"


class Candle : public AbstractCandle {
 public:
  enum CandleColor
    {RED = -1,
     GRAY = 0,
     GREEN = 1};
  
  Candle (double OpenCost, double CloseCost, double LowCost, double HighCost, double Volume, QDateTime &OpenTime, QDateTime &CloseTime);
  Candle ();
  virtual ~Candle() {};
  virtual CandleColor getColor() const;
  virtual double getOpenCost() const;
  virtual Candle &setOpenCost(double) throw(ValueError);
  virtual double getCloseCost() const;
  virtual Candle &setCloseCost(double) throw(ValueError);
  virtual double getLowCost() const;
  virtual Candle &setLowCost(double) throw(ValueError);
  virtual double getHighCost() const;
  virtual Candle &setHighCost(double) throw(ValueError);
  virtual const QDateTime &getOpenTime() const;
  virtual Candle &setOpenTime(const QDateTime &) throw(ValueError);
  virtual const QDateTime &getCloseTime() const;
  virtual Candle &setCloseTime(const QDateTime &) throw(ValueError);
  virtual double getVolume() const;
  virtual Candle &setVolume(double) throw(ValueError);
  virtual bool isValid() const;
  virtual int compare(const Candle&) const;
  virtual bool operator>(const Candle &) const;
  virtual bool operator>=(const Candle &) const;
  virtual bool operator==(const Candle &) const;
  virtual bool operator<=(const Candle &) const;
  virtual bool operator<(const Candle &) const;
  virtual void accept(CandleVisitor *);
private:
  double OpenCost;
  double CloseCost;
  double LowCost;
  double HighCost;
  QDateTime OpenTime;
  QDateTime CloseTime;
  double Volume;
};
  

#endif
