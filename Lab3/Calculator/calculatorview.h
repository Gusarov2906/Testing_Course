#ifndef CALCULATORVIEW_H
#define CALCULATORVIEW_H

#include "calculator.h"
#include "icalculatorpresenter.h"
#include "icalculatorview.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorView; }
QT_END_NAMESPACE

class CalculatorView : public QMainWindow, ICalculatorView, ICalculatorPresenter
{
    Q_OBJECT

public:
    CalculatorView(QWidget *parent = nullptr);
    ~CalculatorView();

    void printResult(double result) override;
    void displayError(QString message) override;
    QString getFirstArgumentAsString() override;
    QString getSecondArgumentAsString() override;
    void onPlusClicked() override;
    void onMinusClicked() override;
    void onDivideClicked() override;
    void onMultiplyClicked() override;

private slots:
    void on_plusButton_clicked();
    void on_multiplyButton_clicked();
    void on_devideButton_clicked();
    void on_minusButton_clicked();

private:
    Ui::CalculatorView *ui;
    Calculator m_calculator;

    double firstArgument;
    double secondArgument;
    double result;

    bool isSuccess;

    void getArguments();

};
#endif // CALCULATORVIEW_H
