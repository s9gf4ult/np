#include "CommonError.h"
#include <QString>

CommonError::CommonError(const QString &msg) : Message(msg) {
};

CommonError::CommonError(const char *msg) : Message(msg) {
};


QString &getMessage() const {
  return this->Message;
}
