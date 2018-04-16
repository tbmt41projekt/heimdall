/********************************************************************************
** Form generated from reading UI file 'LogbydateWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGBYDATEWINDOW_H
#define UI_LOGBYDATEWINDOW_H

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

class Ui_LogbydateWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *logText;

    void setupUi(QWidget *LogbydateWindow)
    {
        if (LogbydateWindow->objectName().isEmpty())
            LogbydateWindow->setObjectName(QStringLiteral("LogbydateWindow"));
        LogbydateWindow->resize(506, 396);
        verticalLayout = new QVBoxLayout(LogbydateWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(LogbydateWindow);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        logText = new QTextEdit(LogbydateWindow);
        logText->setObjectName(QStringLiteral("logText"));

        verticalLayout->addWidget(logText);


        retranslateUi(LogbydateWindow);

        QMetaObject::connectSlotsByName(LogbydateWindow);
    } // setupUi

    void retranslateUi(QWidget *LogbydateWindow)
    {
        LogbydateWindow->setWindowTitle(QApplication::translate("LogbydateWindow", "LogbydateWindow", 0));
        label->setText(QApplication::translate("LogbydateWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">LOG</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class LogbydateWindow: public Ui_LogbydateWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGBYDATEWINDOW_H
