#include "SimpleTick.h"

SimpleTick::SimpleTick(const QDateTime &dt, double cost, double volume):
  Volume(volume), Cost(cost), Time(dt) {
}

SimpleTick::SimpleTick():
  Volume(0), Cost(0) {
}

SimpleTick::SimpleTick(const SimpleTick &other)
    :Volume(other.Volume), Cost(other.Cost), Time(other.Time) {

}

SimpleTick &SimpleTick::setVolume(double volume) throw(ValueError){
  if (volume <= 0) {
    throw(ValueError().setMessage("Volume of tick must be grather than 0"));
  } else {
    Volume = volume;
  }
  return *this;
}

double SimpleTick::getVolume() const {
  return Volume;
}

SimpleTick &SimpleTick::setCost(double cost) throw(ValueError) {
  if (cost <= 0) {
    throw(ValueError().setMessage("Cost of tick must be grather than 0"));
  } else {
    Cost = cost;
  };
  return *this;
}

double SimpleTick::getCost() const {
  return Cost;
}

SimpleTick &SimpleTick::setTime(const QDateTime &qdt) {
  Time = qdt;
  return *this;
}

AbstractCandle *SimpleTick::cloneCandle() const {
    return new SimpleTick(*this);
}

const QDateTime &SimpleTick::getDateTime() const {
  return Time;
}

double SimpleTick::getOpenCost() const {
    return getCost();
}

double SimpleTick::getCloseCost() const {
    return getCost();
}

double SimpleTick::getLowCost() const {
    return getCost();
}

double SimpleTick::getHighCost() const {
    return getCost();
}

const QDateTime &SimpleTick::getOpenTime() const {
    return getDateTime();
}

const QDateTime &SimpleTick::getCloseTime() const {
    return getDateTime();
}

void SimpleTick::accept(CandleVisitor *visitor)
{
    visitor->visit(this);
}

QString SimpleTick::toString()
{
    return QString("Tick with time: %1, cost: %2, volume: %3")
            .arg(this->getDateTime().toString())
            .arg(this->getCost())
            .arg(this->getVolume());
}
