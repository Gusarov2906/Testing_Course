#include "calculatorview.h"
#include "ui_calculatorview.h"
#include <QDebug>
#include <QMessageBox>
#include <QTest>

CalculatorView::CalculatorView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculatorView)
{
    ui->setupUi(this);
    firstArgument = 0;
    secondArgument = 0;
    isSuccess = false;
}


void CalculatorView::printResult(double result)
{
    ui->resultLineEdit->setText(QString::number(result));
}

void CalculatorView::displayError(QString message)
{
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}

QString CalculatorView::getFirstArgumentAsString()
{
    return ui->firstArgumentLineEdit->text();
}

QString CalculatorView::getSecondArgumentAsString()
{
    return ui->secondArgumentLineEdit->text();
}

CalculatorView::~CalculatorView()
{
    delete ui;
}

void CalculatorView::on_plusButton_clicked()
{
    onPlusClicked();
}

void CalculatorView::on_multiplyButton_clicked()
{
    onMultiplyClicked();
}

void CalculatorView::on_devideButton_clicked()
{
    onDivideClicked();
}

void CalculatorView::on_minusButton_clicked()
{
    onMinusClicked();
}

void CalculatorView::onPlusClicked()
{
    getArguments();
    if(!isSuccess)
    {
        return;
    }
    result = m_calculator.sum(firstArgument, secondArgument);
    printResult(result);
}

void CalculatorView::onMinusClicked()
{
    getArguments();
    if(!isSuccess)
    {
        return;
    }
    result = m_calculator.subtract(firstArgument, secondArgument);
    printResult(result);
}

void CalculatorView::onDivideClicked()
{
    getArguments();
    if(!isSuccess)
    {
        return;
    }
    try
    {
    result = m_calculator.divide(firstArgument, secondArgument);
    }
    catch(QString e)
    {
        displayError(e);
        return;
    }

    printResult(result);
}

void CalculatorView::onMultiplyClicked()
{
    getArguments();
    if(!isSuccess)
    {
        return;
    }
    result = m_calculator.multiply(firstArgument, secondArgument);
    printResult(result);
}

void CalculatorView::getArguments()
{
    firstArgument = getFirstArgumentAsString().toDouble(&isSuccess);
    if(!isSuccess)
    {
        displayError("First argument error!");
        return;
    }

    secondArgument = getSecondArgumentAsString().toDouble(&isSuccess);
    if(!isSuccess)
    {
        displayError("Second argument error!");
    }
}
