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
#include "PointersList.h"


int main () {
    PointersList<QString> list;
    list.append(new QString("jdjdjd"));
    list.append(new QString("fuck fuck"));
    QTextStream out(stdout);
    for(PointersList<QString>::const_iterator it = list.begin(); it != list.end(); ++it) {
        out << **it << "\n";
    }


    out << "finish\n";
    out.flush();
}
  
