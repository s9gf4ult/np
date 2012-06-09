#include "Period.h"
#include "SharedPeriod.h"
#include <QSharedDataPointer>

template<>
SharedPeriod* QSharedDataPointer<SharedPeriod>::clone() {
    return d->clonePeriod();
}

Period::Period()
{
}

Period::Period(SharedPeriod *data) : d(data)
{
}

Period::Period(const Period &other) : d(other.d)
{
}

SharedPeriod *Period::data()
{
    return d.data();
}

const SharedPeriod *Period::constData() const
{
    return d.constData();
}

QDateTime Period::getNextTime(const QDateTime time) const {
    return constData()->getNextTime(time);
}

QDateTime Period::getPrevTime(const QDateTime time) const {
    return constData()->getPrevTime(time);
}

void Period::accept(PeriodVisitor *visitor) {
    data()->accept(visitor);
}
