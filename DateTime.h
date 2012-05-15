#ifndef DATETIME_H
#define DATETIME_H

#include <QDateTime>
#include <QObject>

class DateTime : public QObject, public QDateTime {
  Q_OBJECT;
};

#endif
