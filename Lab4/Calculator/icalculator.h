#ifndef ICALCULATOR_H
#define ICALCULATOR_H


class ICalculator
{
public:
    virtual double sum(double a, double b) = 0;
    virtual double subtract(double a, double b) = 0;
    virtual double multiply(double a, double b) = 0;
    virtual double divide(double a, double b) = 0;
};

#endif // ICALCULATOR_H
