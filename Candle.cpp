#include "Candle.h"
#include "Common.h"
#include "ValueError.h"
#include <QDateTime>

Candle::Candle (double OpenCost, double CloseCost, double LowCost, double HighCost, QDateTime &OpenTime, QDateTime &CloseTime):
  OpenCost(OpenCost), CloseCost(CloseCost), LowCost(LowCost), HighCost(HighCost), OpenTime(OpenTime), CloseTime(CloseTime) {
};

Candle::Candle() : OpenCost(0), CloseCost(0), LowCost(0), HighCost(0) {
};

double Candle::getOpenCost() const {
  return this->OpenCost;
};

Candle & Candle::setOpenCost(double oc) throw(ValueError) {
  if (oc <= 0) {
    throw(ValueError().setMessage("Open cost must be grather than 0"));
  } else if (oc > HighCost || oc < LowCost) {
    throw(ValueError().setMessage("Open cost must be in low/high boundaries"));
  } else {
    this->OpenCost = oc;
  }
  return *this;
}
  
double Candle::getCloseCost() const {
  return this->CloseCost;
};

Candle & Candle::setCloseCost(double cc) throw(ValueError) {
  if (cc <= 0) {
    throw(ValueError().setMessage("Close cost must be grather than 0"));
  } else if (cc > HighCost || cc < LowCost) {
    throw(ValueError().setMessage("Close cost must be in low/high boundaries"));
  } else {
    this->CloseCost = cc;
  }
  return *this;
}

double Candle::getLowCost() const {
  return this->LowCost;
};

Candle & Candle::setLowCost(double lc) throw(ValueError) {
  if (lc <= 0) {
    throw(ValueError().setMessage("Low Cost must be grather than 0"));
  } else if (lc > OpenCost || lc > CloseCost || lc > HighCost) {
    throw(ValueError().setMessage("Low Cost must be lowest in the candle"));
  } else {
    this->LowCost = lc;
  }
  return *this;
}

double Candle::getHighCost() const {
  return this->HighCost;
};

Candle & Candle::setHighCost(double hc) throw(ValueError) {
  if (hc <= 0) {
    throw(ValueError().setMessage("High Cost must be grather than 0"));
  } else if ((hc < OpenCost) || (hc < CloseCost) || (hc < LowCost)) {
    throw(ValueError().setMessage("High Cost must be lowest in the candle"));
  } else {
    this->HighCost = hc;
  }
  return *this;
}


const QDateTime &Candle::getOpenTime() const {
  return this->OpenTime;
};

Candle & Candle::setOpenTime(const QDateTime &ot) throw(ValueError) {
  if (ot > CloseTime) {
    throw(ValueError().setMessage("OpenTime is grather than CloseTime"));
  } else {
    this->OpenTime = ot;
  }
  return *this;
};

const QDateTime &Candle::getCloseTime() const {
  return this->CloseTime;
};

Candle & Candle::setCloseTime(const QDateTime &ct) throw(ValueError) {
  if (ct < OpenTime) {
    throw(ValueError().setMessage("CloseTime is less than OpenTime"));
  } else {
    this->CloseTime = ct;
  }
  return *this;
};

double Candle::getVolume() const {
  return this->Volume;
};

Candle & Candle::setVolume(double volume) throw(ValueError) {
  if (volume <= 0) {
    throw(ValueError().setMessage("Volume must be grather than zero"));
  } else {
    this->Volume = volume;
  }
  return *this;
};
  

bool Candle::isValid() const {
  return ((this->getLowCost() <= this->getHighCost()) &&
          (this->getOpenCost() <= this->getHighCost()) && (this->getOpenCost() >= this->getLowCost()) &&
          (this->getCloseCost() <= this->getHighCost()) && (this->getCloseCost() >= this->getLowCost()) &&
          (this->getOpenTime() <= this->getCloseTime()));
};

int Candle::compare(const Candle& cndl) const {
  int c1 = cmp(this->getOpenTime(), cndl.getOpenTime());
  if (c1 != 0) {
    return c1;
  } else {
    return cmp(this->getCloseTime(), cndl.getCloseTime());
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

Candle::CandleColor Candle::getColor() const {
  if (CloseCost > LowCost)
    return GREEN;
  else if (CloseCost == LowCost)
    return GRAY;
  else
    return RED;
}
