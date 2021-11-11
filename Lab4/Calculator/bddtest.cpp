#include "catch.hpp"
#include "calculatorview.h"
#include "ui_calculatorview.h"
#include <QTimer>

SCENARIO( "Operations with simple two args", "[args]" ) {
    CalculatorView view;
    view.show();
    GIVEN( "first and second argument" ) {
        view.ui->firstArgumentLineEdit->setText("5");
        view.ui->secondArgumentLineEdit->setText("4");

        REQUIRE(view.ui->firstArgumentLineEdit->text().toStdString() ==  QString("5").toStdString());
        REQUIRE(view.ui->secondArgumentLineEdit->text().toStdString() ==  QString("4").toStdString());

        WHEN( "sum button pressed") {
            view.on_plusButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("9").toStdString() );
            }
        }
        WHEN( "minus button pressed") {
            view.on_minusButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("1").toStdString() );
            }
        }
        WHEN( "divide button pressed") {
            view.on_devideButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("1.25").toStdString() );
            }
        }
        WHEN( "multiply button pressed") {
            view.on_multiplyButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("20").toStdString() );
            }
        }
    }
}

SCENARIO( "Operations with float two args", "[args]" ) {
    CalculatorView view;
    view.show();
    GIVEN( "first and second argument" ) {
        view.ui->firstArgumentLineEdit->setText("-5.2");
        view.ui->secondArgumentLineEdit->setText("4");

        REQUIRE(view.ui->firstArgumentLineEdit->text().toStdString() ==  QString("-5.2").toStdString());
        REQUIRE(view.ui->secondArgumentLineEdit->text().toStdString() ==  QString("4").toStdString());

        WHEN( "sum button pressed") {
            view.on_plusButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("-1.2").toStdString() );
            }
        }
        WHEN( "minus button pressed") {
            view.on_minusButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("-9.2").toStdString() );
            }
        }
        WHEN( "divide button pressed") {
            view.on_devideButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("-1.3").toStdString() );
            }
        }
        WHEN( "multiply button pressed") {
            view.on_multiplyButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("-20.8").toStdString() );
            }
        }
    }
}

SCENARIO( "Operations with null argument", "[args]" ) {
    CalculatorView view;
    view.show();
    GIVEN( "first and second argument" ) {
        view.ui->firstArgumentLineEdit->setText("1");
        view.ui->secondArgumentLineEdit->setText("0");

        REQUIRE(view.ui->firstArgumentLineEdit->text().toStdString() ==  QString("1").toStdString());
        REQUIRE(view.ui->secondArgumentLineEdit->text().toStdString() ==  QString("0").toStdString());

        WHEN( "sum button pressed") {
            view.on_plusButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("1").toStdString() );
            }
        }
        WHEN( "minus button pressed") {
            view.on_minusButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("1").toStdString() );
            }
        }
        WHEN( "divide button pressed") {
            QTimer::singleShot(100, view.msgBox, SLOT(close()));
            view.on_devideButton_clicked();
            THEN( "result appeared in message box" ) {
                REQUIRE(view.msgBox->text().toStdString() == QString("Division by zero").toStdString());
            }
        }
        WHEN( "multiply button pressed") {
            view.on_multiplyButton_clicked();
            THEN( "result appeared in result field" ) {
                REQUIRE( view.ui->resultLineEdit->text().toStdString() == QString("0").toStdString() );
            }
        }
    }
}

SCENARIO( "Operations without second argument", "[args]" ) {
    CalculatorView view;
    view.show();
    GIVEN( "first argument" ) {
        view.ui->firstArgumentLineEdit->setText("4");
        REQUIRE(view.ui->firstArgumentLineEdit->text().toStdString() ==  QString("4").toStdString());

        WHEN( "sum button pressed") {
            QTimer::singleShot(100, view.msgBox, SLOT(close()));
            view.on_plusButton_clicked();
            THEN( "result appeared in message box" ) {
                REQUIRE(view.msgBox->text().toStdString() == QString("Second argument error!").toStdString());
            }
        }
    }
}

SCENARIO( "Operations without first argument", "[args]" ) {
    CalculatorView view;
    view.show();
    GIVEN( "second argument" ) {
        view.ui->secondArgumentLineEdit->setText("4");
        REQUIRE(view.ui->secondArgumentLineEdit->text().toStdString() ==  QString("4").toStdString());

        WHEN( "sum button pressed") {
            QTimer::singleShot(100, view.msgBox, SLOT(close()));
            view.on_plusButton_clicked();
            THEN( "result appeared in message box" ) {
                REQUIRE(view.msgBox->text().toStdString() == QString("First argument error!").toStdString());
            }
        }
    }
}


