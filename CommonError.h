#ifndef COMMONERROR_H
#define COMMONERROR_H

#include <QString>

class CommonError {
public:
  virtual ~CommonError() {};
  virtual const QString &getMessage() const;
  virtual CommonError &setMessage(const QString&);
private:
  QString Message;
};

#endif
