#include "CommonError.h"
#include <QString>

CommonError &CommonError::setMessage(const QString &msg) {
  Message = msg;
  return *this;
}

const QString &CommonError::getMessage() const {
  return this->Message;
}
