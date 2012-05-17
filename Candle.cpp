#include "Candle.h"
#include "Common.h"
#include <QDateTime>

Candle::Candle (double OpenCost, double CloseCost, double LowCost, double HighCost, QDateTime *OpenTime, QDateTime *CloseTime):
  OpenCost(OpenCost), CloseCost(CloseCost), LowCost(LowCost), HighCost(HighCost), OpenTime(OpenTime), CloseTime(CloseTime) {
};

Candle::Candle() : OpenCost(0), CloseCost(0), LowCost(0), HighCost(0) {
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

QDateTime *Candle::getOpenTime() const {
  return this->OpenTime.data();
};

QDateTime *Candle::getCloseTime() const {
  return this->CloseTime.data();
};

bool Candle::isValid() const {
  return ((this->getLowCost() <= this->getHighCost()) &&
          (this->getOpenCost() <= this->getHighCost()) && (this->getOpenCost() >= this->getLowCost()) &&
          (this->getCloseCost() <= this->getHighCost()) && (this->getCloseCost() >= this->getLowCost()) &&
          (*(this->getOpenTime()) <= *(this->getCloseTime())));
};

int Candle::compare(const Candle& cndl) const {
  int c1 = cmp(*(this->getOpenTime()), *(cndl.getOpenTime()));
  if (c1 != 0) {
    return c1;
  } else {
    return cmp(*(this->getCloseTime()), *(cndl.getCloseTime()));
  };
  return 0;
};

bool Candle::operator>(const Candle &a) const {
  return this->compare(a) > 0;
}

bool Candle::operator>=(const Candle &a) const {
  return this->compare(a) >= 0;
}

bool Candle::operator==(const Candle &a) const {
  return this->compare(a) == 0;
}

bool Candle::operator<=(const Candle &a) const {
  return this->compare(a) <= 0;
}

bool Candle::operator<(const Candle &a) const {
  return this->compare(a) < 0;
}
