/********************************************************************************
** Form generated from reading UI file 'patientHistoryWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTHISTORYWINDOW_H
#define UI_PATIENTHISTORYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patientHistoryWindow
{
public:
    QListView *patientList;
    QLabel *historyTitle;

    void setupUi(QWidget *patientHistoryWindow)
    {
        if (patientHistoryWindow->objectName().isEmpty())
            patientHistoryWindow->setObjectName(QStringLiteral("patientHistoryWindow"));
        patientHistoryWindow->resize(625, 653);
        patientList = new QListView(patientHistoryWindow);
        patientList->setObjectName(QStringLiteral("patientList"));
        patientList->setGeometry(QRect(60, 70, 501, 521));
        historyTitle = new QLabel(patientHistoryWindow);
        historyTitle->setObjectName(QStringLiteral("historyTitle"));
        historyTitle->setGeometry(QRect(180, 30, 241, 31));

        retranslateUi(patientHistoryWindow);

        QMetaObject::connectSlotsByName(patientHistoryWindow);
    } // setupUi

    void retranslateUi(QWidget *patientHistoryWindow)
    {
        patientHistoryWindow->setWindowTitle(QApplication::translate("patientHistoryWindow", "patientHistoryWindow", 0));
        historyTitle->setText(QApplication::translate("patientHistoryWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">Load patient history</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class patientHistoryWindow: public Ui_patientHistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTHISTORYWINDOW_H
