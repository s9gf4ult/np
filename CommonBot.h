#ifndef COMMONBOT_H
#define COMMONBOT_H

#include <QObject>
#include "CommonSystem.h"

class CommonBot : public QObject {
  Q_OBJECT
  public:
  virtual void initialize(CommonSystem &) = 0;
  virtual void start() = 0;
  virtual void stop() = 0;
};

#endif
