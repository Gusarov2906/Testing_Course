#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculator.h"
#include "calculatorpresenter.h"
#include "icalculatorview.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CalculatorView : public QMainWindow, ICalculatorView
{
    Q_OBJECT

public:
    CalculatorView(QWidget *parent = nullptr);
    ~CalculatorView();

    void printResult(double result) override;
    void displayError(QString message) override;
    QString getFirstArgumentAsString() override;
    QString getSecondArgumentAsString() override;

private:
    Ui::MainWindow *ui;
    Calculator m_calculator;
    CalculatorPresenter m_calculatorPresenter;

};
#endif // MAINWINDOW_H
