#include "calculatortest.h"

CalculatorTest::CalculatorTest(QObject *parent) :
    QObject(parent)
{

}

void CalculatorTest::sum()
{
    Calculator calc;
    QCOMPARE(calc.sum(1, 1), 2);
}

void CalculatorTest::subtract()
{
    Calculator calc;
    QCOMPARE(calc.subtract(1, 1), 0);
}


void CalculatorTest::multiply()
{
    Calculator calc;
    QCOMPARE(calc.multiply(1, 1), 1);
}


void CalculatorTest::divide()
{
    Calculator calc;
    QCOMPARE(calc.divide(1, 1), 1);
}

