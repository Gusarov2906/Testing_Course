#ifndef ICALCULATORVIEW_H
#define ICALCULATORVIEW_H

#include <QString>

class ICalculatorView
{
public:
    virtual void printResult(double result) = 0;
    virtual void displayError(QString message) = 0;
    virtual QString getFirstArgumentAsString() = 0;
    virtual QString getSecondArgumentAsString() = 0;
};

#endif // ICALCULATORVIEW_H
