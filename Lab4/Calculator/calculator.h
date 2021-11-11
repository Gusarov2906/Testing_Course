#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "icalculator.h"

class Calculator : public ICalculator
{
public:
    Calculator();
    double sum(double a, double b) override;
    double subtract(double a, double b) override;
    double multiply(double a, double b) override;
    double divide(double a, double b) override;
};

#endif // CALCULATOR_H
