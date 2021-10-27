#include "calculator.h"
#include "cmath"
#include <QString>

Calculator::Calculator()
{

}

double Calculator::sum(double a, double b)
{
    return a + b;
}

double Calculator::subtract(double a, double b)
{
    return a - b;
}

double Calculator::multiply(double a, double b)
{
    return a * b;
}

double Calculator::divide(double a, double b)
{
    if (std::abs(b) < 10e-8)
    {
        throw QString("Division by zero");
    }
    return a / b;
}
