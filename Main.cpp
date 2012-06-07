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

class SetVolume : public CandleVisitor {
public:
    SetVolume(double v) : Volume(v) {}
    virtual void visit(SimpleCandle *candle) {
        candle->setVolume(Volume);
    }

    virtual void visit(SimpleTick *tick) {
        tick->setVolume(Volume);
    }

protected:
    double Volume;
};

int main () {
    QTextStream out(stdout);
    out << sizeof(Candle) << "\n";
    out.flush();
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    Candle x(new SimpleCandle());
    Candle y(x);
    out << x.toString() << "\n";
    out.flush();
    out << y.toString() << "\n";
    out.flush();
    out << "changing x\n";
    out.flush();
    SetVolume svt(20);
    x.accept(&svt);
    out.flush();
    out << x.toString() << "\n";
    out.flush();
    out << y.toString() << "\n";
    out.flush();
}
  
