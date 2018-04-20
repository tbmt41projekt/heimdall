/********************************************************************************
** Form generated from reading UI file 'AddNoteWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNOTEWINDOW_H
#define UI_ADDNOTEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddNoteWindow
{
public:
    QLineEdit *lineNote;
    QPushButton *pushAdd;
    QLabel *label;
    QPushButton *pushFalseAlarm;
    QPushButton *pushGivenPatient;
    QPushButton *pushSleep;

    void setupUi(QDialog *AddNoteWindow)
    {
        if (AddNoteWindow->objectName().isEmpty())
            AddNoteWindow->setObjectName(QStringLiteral("AddNoteWindow"));
        AddNoteWindow->resize(516, 156);
        lineNote = new QLineEdit(AddNoteWindow);
        lineNote->setObjectName(QStringLiteral("lineNote"));
        lineNote->setGeometry(QRect(20, 40, 401, 21));
        pushAdd = new QPushButton(AddNoteWindow);
        pushAdd->setObjectName(QStringLiteral("pushAdd"));
        pushAdd->setGeometry(QRect(430, 40, 75, 23));
        label = new QLabel(AddNoteWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 101, 21));
        pushFalseAlarm = new QPushButton(AddNoteWindow);
        pushFalseAlarm->setObjectName(QStringLiteral("pushFalseAlarm"));
        pushFalseAlarm->setGeometry(QRect(20, 80, 401, 21));
        pushGivenPatient = new QPushButton(AddNoteWindow);
        pushGivenPatient->setObjectName(QStringLiteral("pushGivenPatient"));
        pushGivenPatient->setGeometry(QRect(20, 120, 401, 21));
        pushSleep = new QPushButton(AddNoteWindow);
        pushSleep->setObjectName(QStringLiteral("pushSleep"));
        pushSleep->setGeometry(QRect(20, 100, 401, 21));

        retranslateUi(AddNoteWindow);

        QMetaObject::connectSlotsByName(AddNoteWindow);
    } // setupUi

    void retranslateUi(QDialog *AddNoteWindow)
    {
        AddNoteWindow->setWindowTitle(QApplication::translate("AddNoteWindow", "AddNoteWindow", 0));
        pushAdd->setText(QApplication::translate("AddNoteWindow", "Add", 0));
        label->setText(QApplication::translate("AddNoteWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">New note:</span></p></body></html>", 0));
        pushFalseAlarm->setText(QApplication::translate("AddNoteWindow", "False alarm.", 0));
        pushGivenPatient->setText(QApplication::translate("AddNoteWindow", "Patient has been given", 0));
        pushSleep->setText(QApplication::translate("AddNoteWindow", "Patient is asleep.", 0));
    } // retranslateUi

};

namespace Ui {
    class AddNoteWindow: public Ui_AddNoteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNOTEWINDOW_H
