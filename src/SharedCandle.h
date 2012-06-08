#ifndef SHAREDCANDLE_H
#define SHAREDCANDLE_H

#include <QDateTime>
#include <QSharedData>
#include "CandleVisitor.h"
#include "AbstractCandle.h"

class SharedCandle : public QSharedData, public AbstractCandle
{
public:
    virtual SharedCandle* cloneCandle() const = 0;
};


#endif // SHAREDCANDLE_H
