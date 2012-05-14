#include "Candle.h"

Candle::Candle (double OpenCost, double CloseCost, double LowCost, double HighCost, QDateTime *OpenTime, QDateTime *CloseTime):
  OpenCost(OpenCost), CloseCost(CloseCost), LowCost(LowCost), HighCost(HighCost), OpenTime(OpenTime), CloseTime(CloseTime) {
    this->OpenTime->setParent(this);
    this->CloseTime->setParent(this);
};
