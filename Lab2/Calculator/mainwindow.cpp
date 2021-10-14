#include "calculatorview.h"
#include "ui_mainwindow.h"

CalculatorView::CalculatorView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void CalculatorView::printResult(double result)
{

}

void CalculatorView::displayError(QString message)
{

}

QString CalculatorView::getFirstArgumentAsString()
{

}

QString CalculatorView::getSecondArgumentAsString()
{

}

CalculatorView::~CalculatorView()
{
    delete ui;
}
