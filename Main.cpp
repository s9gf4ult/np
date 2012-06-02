#include "DayPeriod.h"
#include "HourPeriod.h"
#include "MinutesPeriod.h"
#include "MonthPeriod.h"
#include "PeriodVisitor.h"
#include <QList>
#include <QString>
#include <QTextCodec>
#include <QTextStream>
#include "SecondsPeriod.h"
#include "YearPeriod.h"


class PrintingVisitor : public PeriodVisitor {
public:
    PrintingVisitor() : out(stdout) {
        out.setCodec(QTextCodec::codecForName("UTF-8"));

    }


    virtual ~PrintingVisitor() {}
    virtual void visit(SecondsPeriod *prd ) {
        out << QString("Print %1 second period\n").arg(static_cast<int>(prd->getValue()));
        out.flush();
    }

    virtual void visit(MinutesPeriod *prd) {
        out << QString("Print %1 minute period\n").arg(static_cast<int>(prd->getValue()));
        out.flush();
    }

    virtual void visit(HourPeriod *prd) {
        out << QString("Print %1 hour period\n").arg(static_cast<int>(prd->getValue()));
        out.flush();
    }

    virtual void visit(DayPeriod *prd) {
        out << QString("Print Day Period starting from %1\n").arg(prd->getControlPoint().toString());
        out.flush();
    }

    virtual void visit(MonthPeriod *prd) {
        out << QString("Print month period\n");
        out.flush();
    }

    virtual void visit(YearPeriod *prd) {
        out << QString("Print period Year\n");
        out.flush();
    }

private:
    QTextStream out;
};

int main () {
    PrintingVisitor pvis;
    QList<TimePeriod*> ql;
    SecondsPeriod sprd(M60V15);
    MinutesPeriod mprd(M60V10);
    YearPeriod yprd;
    DayPeriod dprd;
    ql.append(&sprd);
    ql.append(&mprd);
    ql.append(&yprd);
    ql.append(&dprd);
    for (QList<TimePeriod*>::const_iterator it = ql.begin(); it != ql.end(); ++it) {
        (*it)->accept(&pvis);
    }
    QTextStream out(stdout);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    QDateTime date = QDateTime::currentDateTime();
    out << date.toString() << "\n";
    date = sprd.getNextTime(date);
    out << QString("Next period multiple %2 seconds is %1\n").arg(date.toString()).arg(static_cast<int>(sprd.getValue()));
    date = mprd.getNextTime(date);
    out << QString("Next period multiple %1 minutes is %2\n").arg(mprd.getValue()).arg(date.toString());
}
  
