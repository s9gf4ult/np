#ifndef CANDLE_H
#define CANDLE_H

#include <QDateTime>
#include <QObject>

class Candle : public QObject {
  Q_OBJECT;
  double OpenCost;
  double CloseCost;
  double LowCost;
  double HighCost;
  QDateTime *OpenTime;
  QDateTime *CloseTime;
 public:
  Candle (double OpenCost, double CloseCost, double LowCost, double HighCost, QDateTime *OpenTime, QDateTime *CloseTime);

};
  

#endif
