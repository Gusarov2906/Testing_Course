QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets testlib

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bddtest.cpp \
    calculator.cpp \
    calculatortest.cpp \
    calculatorview.cpp \
    main.cpp

HEADERS += \
    calculator.h \
    calculatortest.h \
    calculatorview.h \
    icalculator.h \
    icalculatorpresenter.h \
    icalculatorview.h

FORMS += \
    calculatorview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
