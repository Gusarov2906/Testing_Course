#include "calculatorview.h"
#include "calculatortest.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef QT_DEBUG
    CalculatorTest calculatorTest;
    Catch::Session session;
    QTest::qExec(&calculatorTest, argc, argv);

    argc = 2;
    argv[1] = QString("-s").toLocal8Bit().data();
    session.run( argc, argv );
#endif

    CalculatorView w;
    w.show();
    return a.exec();
}
