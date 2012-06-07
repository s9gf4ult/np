#include "MonthPeriod.h"
#include "PeriodVisitor.h"
#include <QDate>
#include <QDateTime>
#include <QTime>

MonthPeriod::MonthPeriod()
{
}

QDateTime MonthPeriod::getNextTime(const QDateTime &qdt) const {
    QDateTime ret = qdt;
    ret.addMonths(1);
    QDate date = ret.date();
    date.setDate(date.year(), date.month(), 1);
    ret.setDate(date);
    ret.setTime(QTime(0, 0, 0));
    return ret;
}

QDateTime MonthPeriod::getPrevTime(const QDateTime &qdt) const {
    QDateTime ret = qdt;
    QTime t = ret.time();
    QTime begin(0, 0, 0);
    if (begin == t) {
        ret.addMonths(-1);
    } else {
        ret.setTime(begin);
    }
    return ret;
}

void MonthPeriod::accept(PeriodVisitor *visitor) {
    visitor->visit(this);
}
