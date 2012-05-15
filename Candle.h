#ifndef CANDLE_H
#define CANDLE_H

#include <QObject>
#include "DateTime.h"

class Candle : public QObject {
  Q_OBJECT;
  double OpenCost;
  double CloseCost;
  double LowCost;
  double HighCost;
  DateTime *OpenTime;
  DateTime *CloseTime;
 public:
  Candle (double OpenCost, double CloseCost, double LowCost, double HighCost, DateTime *OpenTime, DateTime *CloseTime);
  virtual double getOpenCost() const;
  virtual double getCloseCost() const;
  virtual double getLowCost() const;
  virtual double getHighCost() const;
  virtual DateTime *getOpenTime() const;
  virtual DateTime *getCloseTime() const;
  virtual bool isValid() const;
  virtual int compare(const Candle&) const;
};
  

#endif
