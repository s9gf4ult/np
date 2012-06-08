#include <QString>
#include <QtTest>
#include "Common.h"
#include "Candle.h"
#include "SimpleCandle.h"
#include "SimpleTick.h"
#include "CandleVisitor.h"

class Test : public QObject
{
    Q_OBJECT
    
public:
    Test();
    
private Q_SLOTS:
    void testReduceCandles();
    void testImplicitSharing();
};


class SetVolume : public CandleVisitor {
public:
    SetVolume(double volume) : Volume(volume) {}

    virtual void visit(SimpleCandle *candle) {
        candle->setVolume(Volume);
    }

    virtual void visit(SimpleTick *tick) {
        tick->setVolume(Volume);
    }

private:
    double Volume;
};

Test::Test()
{
}


/**
 * @brief Test::testReduceCandles
 * testing reduceCandleCollection template function for correctness
 */
void Test::testReduceCandles()
{

    QList<Candle> list;
    for (int i = 0; i < 10; ++i) {
        list.append(Candle(new SimpleCandle(10. + (i / 9), 20. - (i / 9), 5. - (i / 9), 25. + (i / 9), 50.,
                                            QDateTime(QDate(2010, 10, 10), QTime(0, 0, i)),
                                            QDateTime(QDate(2010, 10, 10), QTime(0, 0, 2 * i)))));
        QVERIFY(list.last().isValid());
    }
    QDateTime low = QDateTime(QDate(2010, 10, 10), QTime(0, 0, 0));
    QDateTime high = QDateTime(QDate(2010, 10, 10), QTime(0, 0, 2 * 9));
    Candle result = reduceCandleCollection(list);
    QCOMPARE(high, result.getCloseTime());
    QCOMPARE(low, result.getOpenTime());
    QCOMPARE(static_cast<double>(50 * 10), result.getVolume());
    QCOMPARE(10., result.getOpenCost());
    QCOMPARE(19., result.getCloseCost());
    QCOMPARE(4., result.getLowCost());
    QCOMPARE(26., result.getHighCost());
}

void Test::testImplicitSharing()
{
    QDateTime d(QDateTime::currentDateTime());
    Candle a(new SimpleCandle(5, 10, 4, 15, 40,
                              d, d.addSecs(1000)));
    Candle b(a);
    SetVolume setv(20);
    b.accept(&setv);
    QVERIFY(a.getVolume() != b.getVolume()); //Candle was copied
    QVERIFY(a != b);
    QVERIFY(a.data() != b.data());

}

QTEST_APPLESS_MAIN(Test)

#include "tst_test.moc"
