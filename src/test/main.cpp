#include "tst_CandlesTests.h"
#include <QTest>

int main(int argc, char **argv) {
    CandlesTests ctest;
    QTest::qExec(&ctest, argc, argv);

}
