#ifndef CANDLE_H
#define CANDLE_H

#include <QObject>
#include <QDateTime>
#include <QSharedPointer>

class Candle {
  double OpenCost;
  double CloseCost;
  double LowCost;
  double HighCost;
  QSharedPointer<QDateTime> OpenTime;
  QSharedPointer<QDateTime> CloseTime;
 public:
  Candle (double OpenCost, double CloseCost, double LowCost, double HighCost, QDateTime *OpenTime, QDateTime *CloseTime);
  Candle ();
  virtual double getOpenCost() const;
  virtual double getCloseCost() const;
  virtual double getLowCost() const;
  virtual double getHighCost() const;
  virtual QDateTime *getOpenTime() const;
  virtual QDateTime *getCloseTime() const;
  virtual bool isValid() const;
  virtual int compare(const Candle&) const;
  virtual bool operator>(const Candle &) const;
  virtual bool operator>=(const Candle &) const;
  virtual bool operator==(const Candle &) const;
  virtual bool operator<=(const Candle &) const;
  virtual bool operator<(const Candle &) const;
};
  

#endif
