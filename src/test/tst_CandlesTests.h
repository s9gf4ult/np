#ifndef TST_CANDLESTESTS_H
#define TST_CANDLESTESTS_H

#include <QObject>

class CandlesTests : public QObject
{
    Q_OBJECT

public:
    CandlesTests();

private Q_SLOTS:
    /**
     * @brief Test::testReduceCandles
     * testing reduceCandleCollection template function for correctness
     */
    void testReduceCandles();

    /**
     * @brief Test::testImplicitSharing
     * testing implicit sharing on candles
     */
    void testImplicitSharing();
};

#endif // TST_CANDLESTESTS_H
