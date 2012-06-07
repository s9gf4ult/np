#ifndef SIMPLECANDLE_H
#define SIMPLECANDLE_H

#include "ValueError.h"
#include <QDateTime>
#include <QObject>
#include <QSharedPointer>
#include "AbstractCandle.h"
#include "CandleVisitor.h"


class SimpleCandle : public AbstractCandle {
 public:
  enum CandleColor
    {RED = -1,
     GRAY = 0,
     GREEN = 1};
  
  SimpleCandle (double OpenCost, double CloseCost, double LowCost, double HighCost, double Volume, QDateTime &OpenTime, QDateTime &CloseTime);
  SimpleCandle ();
  SimpleCandle (const SimpleCandle& other);
  virtual ~SimpleCandle() {}
  virtual CandleColor getColor() const;
  virtual double getOpenCost() const;
  virtual SimpleCandle &setOpenCost(double) throw(ValueError);
  virtual double getCloseCost() const;
  virtual SimpleCandle &setCloseCost(double) throw(ValueError);
  virtual double getLowCost() const;
  virtual SimpleCandle &setLowCost(double) throw(ValueError);
  virtual double getHighCost() const;
  virtual SimpleCandle &setHighCost(double) throw(ValueError);
  virtual const QDateTime &getOpenTime() const;
  virtual SimpleCandle &setOpenTime(const QDateTime &) throw(ValueError);
  virtual const QDateTime &getCloseTime() const;
  virtual SimpleCandle &setCloseTime(const QDateTime &) throw(ValueError);
  virtual double getVolume() const;
  virtual SimpleCandle &setVolume(double) throw(ValueError);
  virtual bool isValid() const;
  virtual int compare(const SimpleCandle&) const;
  virtual bool operator>(const SimpleCandle &) const;
  virtual bool operator>=(const SimpleCandle &) const;
  virtual bool operator==(const SimpleCandle &) const;
  virtual bool operator<=(const SimpleCandle &) const;
  virtual bool operator<(const SimpleCandle &) const;
  virtual void accept(CandleVisitor *);
  virtual QString toString();
  virtual AbstractCandle* cloneCandle() const ;
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
