/********************************************************************************
** Form generated from reading UI file 'heimdall_VS.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEIMDALL_VS_H
#define UI_HEIMDALL_VS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_heimdall_VSClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QFrame *frame_2;
    QLabel *label_3;
    QTextEdit *textEdit_10;
    QTextEdit *textEdit_11;
    QTextEdit *textEdit_12;
    QTextEdit *textEdit_13;
    QTextEdit *textEdit_6;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *heimdall_VSClass)
    {
        if (heimdall_VSClass->objectName().isEmpty())
            heimdall_VSClass->setObjectName(QStringLiteral("heimdall_VSClass"));
        heimdall_VSClass->resize(504, 383);
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        heimdall_VSClass->setFont(font);
        heimdall_VSClass->setMouseTracking(true);
        heimdall_VSClass->setAutoFillBackground(false);
        heimdall_VSClass->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        centralWidget = new QWidget(heimdall_VSClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-214, 270, 361, 20));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(70, 49, 121, 81));
        frame_2->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 40, 91, 31));
        label_3->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        textEdit_10 = new QTextEdit(centralWidget);
        textEdit_10->setObjectName(QStringLiteral("textEdit_10"));
        textEdit_10->setGeometry(QRect(250, 90, 51, 31));
        textEdit_11 = new QTextEdit(centralWidget);
        textEdit_11->setObjectName(QStringLiteral("textEdit_11"));
        textEdit_11->setGeometry(QRect(400, 90, 51, 31));
        textEdit_12 = new QTextEdit(centralWidget);
        textEdit_12->setObjectName(QStringLiteral("textEdit_12"));
        textEdit_12->setGeometry(QRect(250, 150, 51, 31));
        textEdit_13 = new QTextEdit(centralWidget);
        textEdit_13->setObjectName(QStringLiteral("textEdit_13"));
        textEdit_13->setGeometry(QRect(400, 150, 51, 31));
        textEdit_6 = new QTextEdit(centralWidget);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(260, 30, 191, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 30, 231, 21));
        label_2->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 150, 141, 31));
        label_4->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(200, 160, 47, 13));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(200, 100, 47, 13));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(350, 100, 47, 13));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(350, 160, 47, 13));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 300, 181, 31));
        pushButton->setFont(font);
        pushButton->setMouseTracking(false);
        pushButton->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 250, 121, 31));
        pushButton_2->setStyleSheet(QStringLiteral(""));
        heimdall_VSClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(heimdall_VSClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        heimdall_VSClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(heimdall_VSClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        heimdall_VSClass->setStatusBar(statusBar);

        retranslateUi(heimdall_VSClass);

        QMetaObject::connectSlotsByName(heimdall_VSClass);
    } // setupUi

    void retranslateUi(QMainWindow *heimdall_VSClass)
    {
        heimdall_VSClass->setWindowTitle(QApplication::translate("heimdall_VSClass", "heimdall_VS", 0));
        label->setText(QString());
        label_3->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-weight:600;\">Heart rate</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("heimdall_VSClass", "Personal identification number:", 0));
        label_4->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-weight:600;\">Respiratory rate</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        label_8->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        label_9->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        label_10->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        pushButton->setText(QApplication::translate("heimdall_VSClass", "Start measurement", 0));
        pushButton_2->setText(QApplication::translate("heimdall_VSClass", "Select resp.ROI", 0));
    } // retranslateUi

};

namespace Ui {
    class heimdall_VSClass: public Ui_heimdall_VSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIMDALL_VS_H
