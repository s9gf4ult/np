#include "Tick.h"

Tick::Tick(const QDateTime &dt, double cost, double volume):
  Volume(volume), Cost(cost), Time(dt) {
}

Tick::Tick():
  Volume(0), Cost(0) {
}

Tick &Tick::setVolume(double volume) throw(ValueError){
  if (volume <= 0) {
    throw(ValueError().setMessage("Volume of tick must be grather than 0"));
  } else {
    Volume = volume;
  }
  return *this;
}

double Tick::getVolume() const {
  return Volume;
}

Tick &Tick::setCost(double cost) throw(ValueError) {
  if (cost <= 0) {
    throw(ValueError().setMessage("Cost of tick must be grather than 0"));
  } else {
    Cost = cost;
  };
  return *this;
}

double Tick::getCost() const {
  return Cost;
}

Tick &Tick::setTime(const QDateTime &qdt) {
  Time = qdt;
  return *this;
}

const QDateTime &Tick::getDateTime() const {
  return Time;
}

double Tick::getOpenCost() const {
    return getCost();
}

double Tick::getCloseCost() const {
    return getCost();
}

double Tick::getLowCost() const {
    return getCost();
}

double Tick::getHighCost() const {
    return getCost();
}

const QDateTime &Tick::getOpenTime() const {
    return getDateTime();
}

const QDateTime &Tick::getCloseTime() const {
    return getDateTime();
}

void Tick::accept(CandleVisitor *visitor)
{
    visitor->visit(this);
}

QString Tick::toString()
{
    return QString("Tick with time: %1, cost: %2, volume: %3")
            .arg(this->getDateTime().toString())
            .arg(this->getCost())
            .arg(this->getVolume());
}
