#include "calculatorview.h"
#include "calculatortest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef QT_DEBUG
    CalculatorTest calculatorTest;
    QTest::qExec(&calculatorTest, argc, argv);
#endif
    CalculatorView w;
    w.show();
    return a.exec();
}
