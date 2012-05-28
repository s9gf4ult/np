#ifndef COMMONERROR_H
#define COMMONERROR_H

#include <QString>

class CommonError {
public:
  CommonError(const QString &);
  CommonError(const char *);
  virtual ~CommonError() {};
  virtual QString &getMessage() const;
private:
  QString Message;
#endif
};
