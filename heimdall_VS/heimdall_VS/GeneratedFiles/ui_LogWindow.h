/********************************************************************************
** Form generated from reading UI file 'LogWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWindow
{
public:
    QLabel *labelLog;
    QTextEdit *logText;
    QLabel *labelNote;
    QLineEdit *lineNewNote;

    void setupUi(QWidget *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName(QStringLiteral("LogWindow"));
        LogWindow->resize(506, 410);
        labelLog = new QLabel(LogWindow);
        labelLog->setObjectName(QStringLiteral("labelLog"));
        labelLog->setGeometry(QRect(9, 9, 491, 29));
        logText = new QTextEdit(LogWindow);
        logText->setObjectName(QStringLiteral("logText"));
        logText->setGeometry(QRect(9, 44, 488, 321));
        labelNote = new QLabel(LogWindow);
        labelNote->setObjectName(QStringLiteral("labelNote"));
        labelNote->setGeometry(QRect(10, 370, 71, 31));
        lineNewNote = new QLineEdit(LogWindow);
        lineNewNote->setObjectName(QStringLiteral("lineNewNote"));
        lineNewNote->setGeometry(QRect(80, 370, 411, 31));

        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QWidget *LogWindow)
    {
        LogWindow->setWindowTitle(QApplication::translate("LogWindow", "LogWindow", 0));
        labelLog->setText(QApplication::translate("LogWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">LOG</span></p></body></html>", 0));
        labelNote->setText(QApplication::translate("LogWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">New note</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
