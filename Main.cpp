#include "Candle.h"
#include "SimpleCandle.h"
#include "SimpleTick.h"
#include "AbstractCandle.h"
#include "Common.h"
#include "CandleVisitor.h"
#include <QTextStream>
#include <QTextCodec>
#include <QString>
#include <QDateTime>


int main () {
    QTextStream out(stdout);
    out.setCodec(QTextCodec::codecForName("UTF-8"));



    out.flush();
}
  
