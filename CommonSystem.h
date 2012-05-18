#ifndef COMMONSYSTEM_H
#define COMMONSYSTEM_H

#include <QObject>
#include <QList>
#include <QString>
#include "Candle.h"

class CommonSystem : QObject {
  Q_OBJECT
  virtual QList<QString> & getTickersList() = 0;
  virtual QList<QSharedPointer<Candle> > & 

#endif
