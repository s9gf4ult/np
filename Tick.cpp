#include "Tick.h"

Tick::Tick(const QDateTime &dt, double cost, double volume):
  Volume(volume), Cost(cost), Time(dt) {
};

Tick::Tick():
  Volume(0), Cost(0) {
};

Tick &Tick::setVolume(double volume) throw(ValueError){
  if (volume <= 0) {
    throw(ValueError().setMessage("Volume of tick must be grather than 0"));
  } else {
    Volume = volume;
  }
  return *this;
};

double Tick::getVolume() const {
  return Volume;
};

Tick &Tick::setCost(double cost) throw(ValueError) {
  if (cost <= 0) {
    throw(ValueError().setMessage("Cost of tick must be grather than 0"));
  } else {
    Cost = cost;
  };
  return *this;
};

double Tick::getCost() const {
  return Cost;
};

Tick &Tick::setTime(const QDateTime &qdt) {
  Time = qdt;
  return *this;
}

const QDateTime &Tick::getDateTime() const {
  return Time;
};