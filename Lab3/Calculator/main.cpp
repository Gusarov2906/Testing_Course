#include "calculatorview.h"
#include "calculatortest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    CalculatorTest calculatorTest;
    QApplication a(argc, argv);
    QTest::qExec(&calculatorTest, argc, argv);
    CalculatorView w;
    w.show();
    return a.exec();
}
