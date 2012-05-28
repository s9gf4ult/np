#ifndef VALUEERROR_H
#define VALUEERROR_H

#include "CommonError.h"

class ValueError : public CommonError {
public:
  virtual ~ValueError() {};
};

#endif
