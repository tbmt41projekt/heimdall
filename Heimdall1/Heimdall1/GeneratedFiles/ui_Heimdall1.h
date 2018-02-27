/********************************************************************************
** Form generated from reading UI file 'Heimdall1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEIMDALL1_H
#define UI_HEIMDALL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Heimdall1Class
{
public:
    QWidget *centralWidget;
    QRadioButton *radioButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Heimdall1Class)
    {
        if (Heimdall1Class->objectName().isEmpty())
            Heimdall1Class->setObjectName(QStringLiteral("Heimdall1Class"));
        Heimdall1Class->resize(600, 400);
        centralWidget = new QWidget(Heimdall1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(200, 140, 82, 17));
        Heimdall1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Heimdall1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        Heimdall1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Heimdall1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Heimdall1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Heimdall1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Heimdall1Class->setStatusBar(statusBar);

        retranslateUi(Heimdall1Class);

        QMetaObject::connectSlotsByName(Heimdall1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Heimdall1Class)
    {
        Heimdall1Class->setWindowTitle(QApplication::translate("Heimdall1Class", "Heimdall1", 0));
        radioButton->setText(QApplication::translate("Heimdall1Class", "RadioButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Heimdall1Class: public Ui_Heimdall1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIMDALL1_H
