#ifndef CALCULATORTEST_H
#define CALCULATORTEST_H

#include <QObject>
#include "calculator.h"
#include <QtTest/QTest>
#include <QLineEdit>

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
    void testSimpleCalculate();
    void testFloatCalculate();
    void testErrorMessageBox();

private:
    int m_timeoutMessageBox = 250;
    void clearLineEdit(QLineEdit* lineEdit);

};

#endif // CALCULATORTEST_H
