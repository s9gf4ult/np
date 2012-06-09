#include "YearPeriod.h"
#include <QTime>
#include <QDate>

YearPeriod::YearPeriod()
{
}

QDateTime YearPeriod::getNextTime(const QDateTime qdt) const {
    QDate date = qdt.date();
    return QDateTime(QDate(date.year()+1, 1, 1), QTime(0, 0, 0));
}

QDateTime YearPeriod::getPrevTime(const QDateTime qdt) const {
    QDate date = qdt.date();
    return QDateTime(QDate(date.year() - 1, 1, 1), QTime(0, 0, 0));
}

void YearPeriod::accept(PeriodVisitor *visitor) {
    visitor->visit(this);
}

SharedPeriod *YearPeriod::clonePeriod() const
{
    return new YearPeriod();
}
