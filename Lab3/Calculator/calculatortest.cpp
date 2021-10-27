#include "calculatortest.h"
#include <cfloat>

CalculatorTest::CalculatorTest(QObject *parent) :
    QObject(parent)
{

}

void CalculatorTest::sum()
{
    Calculator calc;
    QCOMPARE(calc.sum(1, 1), 2);
    QCOMPARE(calc.sum(0.1, 0.2), 0.3);
    QCOMPARE(calc.sum(1.5, 1.7), 3.2);
    QCOMPARE(calc.sum(-1.5, 1.7), 0.2);
    QCOMPARE(calc.sum(1.5, -1.7), -0.2);
    QCOMPARE(calc.sum(1.5, 1.5), 3);
    QCOMPARE(calc.sum(1.5e1, 1.5), 16.5);

    QCOMPARE(calc.sum(DBL_MAX, DBL_MAX), qInf());
}

void CalculatorTest::subtract()
{
    Calculator calc;
    QCOMPARE(calc.subtract(1, 1), 0);
    QCOMPARE(calc.subtract(1.5, 1.7), -0.2);
    QCOMPARE(calc.subtract(-1.5, 1.7), -3.2);
    QCOMPARE(calc.subtract(1.5, -1.7), 3.2);
    QCOMPARE(calc.subtract(2, 1.5), 0.5);
    QCOMPARE(calc.subtract(2e-1, 1.5), -1.3);

    QCOMPARE(calc.subtract(DBL_MIN, 1), -1);
}


void CalculatorTest::multiply()
{
    Calculator calc;
    QCOMPARE(calc.multiply(1, 1), 1);
    QCOMPARE(calc.multiply(1.5, 1.7), 2.55);
    QCOMPARE(calc.multiply(-1.5, 1.7), -2.55);
    QCOMPARE(calc.multiply(1.5, -1.7), -2.55);
    QCOMPARE(calc.multiply(1.5, 1.5), 2.25);
    QCOMPARE(calc.multiply(1.5e1, 1.5e1), 225);

    QCOMPARE(calc.multiply(DBL_MAX, 2), qInf());
}

void CalculatorTest::divide()
{
    Calculator calc;
    QCOMPARE(calc.divide(1, 1), 1);
    QCOMPARE(calc.divide(1.5, 1.7), 0.8823529411764706);
    QCOMPARE(calc.divide(-1.5, 1.7), -0.8823529411764706);
    QCOMPARE(calc.divide(1.5, -1.7), -0.8823529411764706);
    QCOMPARE(calc.divide(1.5, 1.5), 1);
    QCOMPARE(calc.divide(1.5e2, 1.5), 100);


    QCOMPARE(calc.divide(1, 0.0001), 10000);
    QCOMPARE(calc.divide(1, -100000), -0.00001);

    try
    {
        calc.divide(0.1, 0.000000001);
    }
    catch (QString e)
    {
        QCOMPARE(e, "Division by zero");
    }

    try
    {
        calc.divide(0.1, -0.000000001);
    }
    catch (QString e)
    {
        QCOMPARE(e, "Division by zero");
    }
}

