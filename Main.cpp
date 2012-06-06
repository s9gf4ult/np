#include "Candle.h"
#include "SimpleCandle.h"
#include "SimpleTick.h"
#include "AbstractCandle.h"
#include "Common.h"
#include <QTextStream>
#include <QTextCodec>
#include <QString>
#include <QDateTime>

int main () {
    QTextStream out(stdout);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    out << QString("size of SimpleCandle : %1\n").arg(sizeof(SimpleCandle));
    out << QString("size of SimpleTick: %1\n").arg(sizeof(SimpleTick));
    out << QString("size of Candle: %1\n").arg(sizeof(Candle<SimpleCandle>));
    out << QString("size of qdatetime: %1\n").arg(sizeof(QDateTime));
    out << QString("size of shared pointer: %1\n").arg(sizeof(QSharedPointer<SimpleCandle>));
    Candle<SimpleCandle> x(new SimpleCandle());
    Candle<AbstractCandle> y(x.value.data());
    out << x.toString() << "\n";

    out.flush();
}
  
