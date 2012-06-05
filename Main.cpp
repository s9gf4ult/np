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
    QTextStream out(stdout);
    QList<QString> a;
    a.append(QString("you"));
    a.append(QString("something"));
    out << a.length();
}
  
