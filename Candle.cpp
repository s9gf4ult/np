#include "Candle.h"
#include "Common.h"
#include "DateTime.h"

Candle::Candle (double OpenCost, double CloseCost, double LowCost, double HighCost, DateTime *OpenTime, DateTime *CloseTime):
  OpenCost(OpenCost), CloseCost(CloseCost), LowCost(LowCost), HighCost(HighCost), OpenTime(OpenTime), CloseTime(CloseTime) {
    this->OpenTime->setParent(this);
    this->CloseTime->setParent(this);
};

double Candle::getOpenCost() const {
  return this->OpenCost;
};
  
double Candle::getCloseCost() const {
  return this->CloseCost;
};
  
double Candle::getLowCost() const {
  return this->LowCost;
};

double Candle::getHighCost() const {
  return this->HighCost;
};

DateTime *Candle::getOpenTime() const {
  return this->OpenTime;
};

DateTime *Candle::getCloseTime() const {
  return this->CloseTime;
};

bool Candle::isValid() const {
  return ((this->getLowCost() <= this->getHighCost()) &&
          (this->getOpenCost() <= this->getHighCost()) && (this->getOpenCost() >= this->getLowCost()) &&
          (this->getCloseCost() <= this->getHighCost()) && (this->getCloseCost() >= this->getLowCost()) &&
          (*(this->getOpenTime()) <= *(this->getCloseTime())));
};

int Candle::compare(const Candle& cndl) const {
  int c1 = compare<DateTime>(*(this->getOpenTime()), *(cndl.getOpenTime()));
  if (c1 != 0) {
    return c1;
  } else {
    return compare<DateTime>(*(this->getCloseTime()), *(cndl.getCloseTime()));
  };
  return 0;
};

