#include "SimpleCandle.h"
#include "Common.h"
#include "ValueError.h"
#include <QDateTime>

SimpleCandle::SimpleCandle (double OpenCost,
                double CloseCost,
                double LowCost,
                double HighCost,
                double Volume,
                QDateTime &OpenTime,
                QDateTime &CloseTime):
    OpenCost(OpenCost),
    CloseCost(CloseCost),
    LowCost(LowCost),
    HighCost(HighCost),
    Volume(Volume),
    OpenTime(OpenTime),
    CloseTime(CloseTime) {
}

SimpleCandle::SimpleCandle() : OpenCost(0), CloseCost(0), LowCost(0), HighCost(0), Volume(0) {
}

SimpleCandle::SimpleCandle(const SimpleCandle &other)
    : OpenCost(other.OpenCost), CloseCost(other.CloseCost),
      LowCost(other.LowCost), HighCost(other.HighCost),
      OpenTime(other.OpenTime), CloseTime(other.CloseTime), Volume(other.Volume)
{

}

double SimpleCandle::getOpenCost() const {
  return this->OpenCost;
};

SimpleCandle & SimpleCandle::setOpenCost(double oc) throw(ValueError) {
  if (oc <= 0) {
    throw(ValueError().setMessage("Open cost must be grather than 0"));
  } else if (oc > HighCost || oc < LowCost) {
    throw(ValueError().setMessage("Open cost must be in low/high boundaries"));
  } else {
    this->OpenCost = oc;
  }
  return *this;
}
  
double SimpleCandle::getCloseCost() const {
  return this->CloseCost;
};

SimpleCandle & SimpleCandle::setCloseCost(double cc) throw(ValueError) {
  if (cc <= 0) {
    throw(ValueError().setMessage("Close cost must be grather than 0"));
  } else if (cc > HighCost || cc < LowCost) {
    throw(ValueError().setMessage("Close cost must be in low/high boundaries"));
  } else {
    this->CloseCost = cc;
  }
  return *this;
}

double SimpleCandle::getLowCost() const {
  return this->LowCost;
};

SimpleCandle & SimpleCandle::setLowCost(double lc) throw(ValueError) {
  if (lc <= 0) {
    throw(ValueError().setMessage("Low Cost must be grather than 0"));
  } else if (lc > OpenCost || lc > CloseCost || lc > HighCost) {
    throw(ValueError().setMessage("Low Cost must be lowest in the candle"));
  } else {
    this->LowCost = lc;
  }
  return *this;
}

double SimpleCandle::getHighCost() const {
  return this->HighCost;
};

SimpleCandle & SimpleCandle::setHighCost(double hc) throw(ValueError) {
  if (hc <= 0) {
    throw(ValueError().setMessage("High Cost must be grather than 0"));
  } else if ((hc < OpenCost) || (hc < CloseCost) || (hc < LowCost)) {
    throw(ValueError().setMessage("High Cost must be lowest in the candle"));
  } else {
    this->HighCost = hc;
  }
  return *this;
}


const QDateTime &SimpleCandle::getOpenTime() const {
  return this->OpenTime;
};

SimpleCandle & SimpleCandle::setOpenTime(const QDateTime &ot) throw(ValueError) {
  if (ot > CloseTime) {
    throw(ValueError().setMessage("OpenTime is grather than CloseTime"));
  } else {
    this->OpenTime = ot;
  }
  return *this;
};

const QDateTime &SimpleCandle::getCloseTime() const {
  return this->CloseTime;
};

SimpleCandle & SimpleCandle::setCloseTime(const QDateTime &ct) throw(ValueError) {
  if (ct < OpenTime) {
    throw(ValueError().setMessage("CloseTime is less than OpenTime"));
  } else {
    this->CloseTime = ct;
  }
  return *this;
};

double SimpleCandle::getVolume() const {
  return this->Volume;
};

SimpleCandle & SimpleCandle::setVolume(double volume) throw(ValueError) {
  if (volume <= 0) {
    throw(ValueError().setMessage("Volume must be grather than zero"));
  } else {
    this->Volume = volume;
  }
  return *this;
};
  

bool SimpleCandle::isValid() const {
  return ((this->getLowCost() <= this->getHighCost()) &&
          (this->getOpenCost() <= this->getHighCost()) && (this->getOpenCost() >= this->getLowCost()) &&
          (this->getCloseCost() <= this->getHighCost()) && (this->getCloseCost() >= this->getLowCost()) &&
          (this->getOpenTime() <= this->getCloseTime()));
};

int SimpleCandle::compare(const SimpleCandle& cndl) const {
  int c1 = cmp(this->getOpenTime(), cndl.getOpenTime());
  if (c1 != 0) {
    return c1;
  } else {
    return cmp(this->getCloseTime(), cndl.getCloseTime());
  };
  return 0;
};

bool SimpleCandle::operator>(const SimpleCandle &a) const {
  return this->compare(a) > 0;
}

bool SimpleCandle::operator>=(const SimpleCandle &a) const {
  return this->compare(a) >= 0;
}

bool SimpleCandle::operator==(const SimpleCandle &a) const {
  return this->compare(a) == 0;
}

bool SimpleCandle::operator<=(const SimpleCandle &a) const {
  return this->compare(a) <= 0;
}

bool SimpleCandle::operator<(const SimpleCandle &a) const {
    return this->compare(a) < 0;
}

void SimpleCandle::accept(CandleVisitor *visitor)
{
    visitor->visit(this);
}

QString SimpleCandle::toString()
{
    return QString("Candle, open time: %1, close time %2, open cost: %3, close cost: %4, highest cost: %5, lowest cost: %6, volume: %7")
            .arg(this->getOpenTime().toString())
            .arg(this->getCloseTime().toString())
            .arg(this->getOpenCost())
            .arg(this->getCloseCost())
            .arg(this->getHighCost())
            .arg(this->getLowCost())
            .arg(this->getVolume());
}


AbstractCandle *SimpleCandle::cloneCandle() const{
    return new SimpleCandle(*this);
}

SimpleCandle::CandleColor SimpleCandle::getColor() const {
  if (CloseCost > LowCost)
    return GREEN;
  else if (CloseCost == LowCost)
    return GRAY;
  else
    return RED;
}
