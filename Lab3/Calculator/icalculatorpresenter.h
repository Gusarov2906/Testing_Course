#ifndef ICALCULATORPRESENTER_H
#define ICALCULATORPRESENTER_H


class ICalculatorPresenter
{
public:
    virtual void onPlusClicked() = 0;
    virtual void onMinusClicked() = 0;
    virtual void onDivideClicked() = 0;
    virtual void onMultiplyClicked() = 0;
};

#endif // ICALCULATORPRESENTER_H
