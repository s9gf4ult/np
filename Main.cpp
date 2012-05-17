#include "Candle.h"
#include "CandlesVector.h"
#include <QtGlobal>
#include <QSharedPointer>
#include <QDateTime>
#include <iostream>

Candle & randomCandle(const QDateTime &dt) {
  int low = 0;
  int high = 0;
  while (low == high) {
    int a = qrand() % 100;
    int b = qrand() % 100;
    low = qMin(a, b);
    high = qMax(a, b);
  }
  double open = (double) (qrand() % (high - low) + low);
  double close = (double) (qrand() % (high - low) + low);
  QDateTime * dto = new QDateTime(dt);
  dto->addSecs(qrand() % 1000 - 500);
  QDateTime * dtc = new QDateTime(*dto);
  dtc->addSecs(qrand() % 1000);
  return *(new Candle(open, close, (double)low, (double)high, dto, dtc));
}

int main (int argc, char **argv) {
  QDateTime dt = QDateTime::currentDateTime();
  CandlesVector vct;
  int i;
  for (i = 0; i < 1000000; i++) {
    vct.append(randomCandle(dt));
  }

  QSharedPointer<Candle> cnd = QSharedPointer<Candle>(vct.getReduced());
  
  
  std::cout << cnd->getLowCost() << std::endl;
  std::cout << cnd->getHighCost() << std::endl;
  std::cout << vct.size() << std::endl;
}
  
