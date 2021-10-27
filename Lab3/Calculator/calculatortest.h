#ifndef CALCULATORTEST_H
#define CALCULATORTEST_H

#include <QObject>
#include "calculator.h"
#include <QtTest/QTest>

class CalculatorTest : public QObject
{
    Q_OBJECT
public:
    explicit  CalculatorTest(QObject *parent = 0);

private slots:
    void sum();
    void subtract();
    void multiply();
    void divide();
};

#endif // CALCULATORTEST_H
