#include "AbstractCandle.h"
#include "Candle.h"
#include "DayPeriod.h"
#include "HourPeriod.h"
#include "MinutesPeriod.h"
#include "MonthPeriod.h"
#include "PeriodVisitor.h"
#include "Common.h"
#include <QList>
#include <QScopedPointer>
#include <QString>
#include <QTextCodec>
#include <QTextStream>
#include "SecondsPeriod.h"
#include "Tick.h"
#include "YearPeriod.h"


int main () {
    QTextStream out(stdout);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    QList<AbstractCandle *> list;
    QDateTime o = QDateTime::currentDateTime();
    QDateTime c = o.addSecs(45);
    list.append(new Candle(5., 10., 4., 10., 22.,
                           o,
                           c));
    list.append(new Tick(c, 12, 22));
    QSharedPointer<Candle> cnd = QSharedPointer<Candle>(reduceCandleCollection(&list));
    out << cnd->getOpenCost() << "\n";
    out << cnd->getOpenTime().toString() << "\n";
    out.flush();

    foreach(AbstractCandle *cndl, list) {
        delete cndl;
    }
}
  
