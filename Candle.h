#ifndef CANDLE_H
#define CANDLE_H

#include "ValueError.h"
#include <QDateTime>
#include <QObject>
#include <QSharedPointer>


class Candle {
 public:
  Candle (double OpenCost, double CloseCost, double LowCost, double HighCost, QDateTime &OpenTime, QDateTime &CloseTime);
  Candle ();
  virtual double getOpenCost() const;
  virtual void setOpenCost(double) throw(ValueError);
  virtual double getCloseCost() const;
  virtual void setCloseCost(double) throw(ValueError);
  virtual double getLowCost() const;
  virtual void setLowCost(double) throw(ValueError);
  virtual double getHighCost() const;
  virtual void setHighCost(double) throw(ValueError);
  virtual QDateTime &getOpenTime() const;
  virtual void setOpenTime(const QDateTime &) throw(ValueError);
  virtual QDateTime &getCloseTime() const;
  virtual void setCloseTime(const QDateTime &) throw(ValueError);
  virtual double getVolume() const;
  virtual void setVolume(double) throw(ValueError);
  virtual bool isValid() const;
  virtual int compare(const Candle&) const;
  virtual bool operator>(const Candle &) const;
  virtual bool operator>=(const Candle &) const;
  virtual bool operator==(const Candle &) const;
  virtual bool operator<=(const Candle &) const;
  virtual bool operator<(const Candle &) const;
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
