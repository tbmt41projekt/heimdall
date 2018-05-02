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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelLog;
    QTextEdit *logText;

    void setupUi(QWidget *LogWindow)
    {
        if (LogWindow->objectName().isEmpty())
            LogWindow->setObjectName(QStringLiteral("LogWindow"));
        LogWindow->resize(506, 410);
        verticalLayout = new QVBoxLayout(LogWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelLog = new QLabel(LogWindow);
        labelLog->setObjectName(QStringLiteral("labelLog"));

        verticalLayout->addWidget(labelLog);

        logText = new QTextEdit(LogWindow);
        logText->setObjectName(QStringLiteral("logText"));

        verticalLayout->addWidget(logText);


        retranslateUi(LogWindow);

        QMetaObject::connectSlotsByName(LogWindow);
    } // setupUi

    void retranslateUi(QWidget *LogWindow)
    {
        LogWindow->setWindowTitle(QApplication::translate("LogWindow", "LogWindow", 0));
        labelLog->setText(QApplication::translate("LogWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">LOG</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class LogWindow: public Ui_LogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
