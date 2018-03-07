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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_heimdall_VSClass
{
public:
    QWidget *centralWidget;
    QFrame *frame_2;
    QLabel *labelHeartRate_2;
    QLabel *labelRespRate_2;
    QLabel *labelHRNumber;
    QLabel *labelRRNumber;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *labelDateTime_2;
    QLabel *label_7;
    QFrame *frame_3;
    QFrame *frame_4;
    QFrame *frame_1;
    QPushButton *pushSelectROI;
    QPushButton *pushStart;
    QLabel *labelMinRR;
    QLabel *labelRespRate;
    QLabel *labelMaxRR;
    QLabel *labelMaxHR;
    QLabel *labelMinHR;
    QLabel *labelHeartRate;
    QLabel *labelPnr;
    QLineEdit *inputPnr;
    QLineEdit *inputMinHR;
    QLineEdit *inputMinRR;
    QLineEdit *inputMaxRR;
    QLineEdit *inputMaxHR;
    QLabel *labelDateTime;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *heimdall_VSClass)
    {
        if (heimdall_VSClass->objectName().isEmpty())
            heimdall_VSClass->setObjectName(QStringLiteral("heimdall_VSClass"));
        heimdall_VSClass->resize(1124, 900);
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
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(550, 0, 501, 371));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        labelHeartRate_2 = new QLabel(frame_2);
        labelHeartRate_2->setObjectName(QStringLiteral("labelHeartRate_2"));
        labelHeartRate_2->setGeometry(QRect(60, 140, 131, 31));
        labelHeartRate_2->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        labelRespRate_2 = new QLabel(frame_2);
        labelRespRate_2->setObjectName(QStringLiteral("labelRespRate_2"));
        labelRespRate_2->setGeometry(QRect(30, 250, 201, 31));
        labelRespRate_2->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        labelHRNumber = new QLabel(frame_2);
        labelHRNumber->setObjectName(QStringLiteral("labelHRNumber"));
        labelHRNumber->setGeometry(QRect(50, 170, 121, 61));
        labelRRNumber = new QLabel(frame_2);
        labelRRNumber->setObjectName(QStringLiteral("labelRRNumber"));
        labelRRNumber->setGeometry(QRect(50, 280, 121, 61));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 230, 41, 16));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 340, 41, 16));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 230, 41, 16));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 340, 41, 16));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 200, 61, 31));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 310, 61, 31));
        labelDateTime_2 = new QLabel(frame_2);
        labelDateTime_2->setObjectName(QStringLiteral("labelDateTime_2"));
        labelDateTime_2->setGeometry(QRect(10, 0, 221, 31));
        labelDateTime_2->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 0, 151, 31));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(550, 410, 501, 371));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(0, 410, 501, 371));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_1 = new QFrame(centralWidget);
        frame_1->setObjectName(QStringLiteral("frame_1"));
        frame_1->setGeometry(QRect(0, 0, 501, 371));
        pushSelectROI = new QPushButton(frame_1);
        pushSelectROI->setObjectName(QStringLiteral("pushSelectROI"));
        pushSelectROI->setGeometry(QRect(200, 270, 121, 31));
        pushSelectROI->setStyleSheet(QStringLiteral(""));
        pushStart = new QPushButton(frame_1);
        pushStart->setObjectName(QStringLiteral("pushStart"));
        pushStart->setEnabled(true);
        pushStart->setGeometry(QRect(170, 320, 181, 31));
        pushStart->setFont(font);
        pushStart->setMouseTracking(false);
        pushStart->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        labelMinRR = new QLabel(frame_1);
        labelMinRR->setObjectName(QStringLiteral("labelMinRR"));
        labelMinRR->setGeometry(QRect(220, 200, 47, 13));
        labelRespRate = new QLabel(frame_1);
        labelRespRate->setObjectName(QStringLiteral("labelRespRate"));
        labelRespRate->setGeometry(QRect(60, 190, 141, 31));
        labelRespRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        labelMaxRR = new QLabel(frame_1);
        labelMaxRR->setObjectName(QStringLiteral("labelMaxRR"));
        labelMaxRR->setGeometry(QRect(330, 200, 47, 13));
        labelMaxHR = new QLabel(frame_1);
        labelMaxHR->setObjectName(QStringLiteral("labelMaxHR"));
        labelMaxHR->setGeometry(QRect(330, 140, 47, 13));
        labelMinHR = new QLabel(frame_1);
        labelMinHR->setObjectName(QStringLiteral("labelMinHR"));
        labelMinHR->setGeometry(QRect(220, 140, 47, 13));
        labelHeartRate = new QLabel(frame_1);
        labelHeartRate->setObjectName(QStringLiteral("labelHeartRate"));
        labelHeartRate->setGeometry(QRect(60, 130, 91, 31));
        labelHeartRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        labelPnr = new QLabel(frame_1);
        labelPnr->setObjectName(QStringLiteral("labelPnr"));
        labelPnr->setGeometry(QRect(30, 50, 231, 21));
        labelPnr->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        inputPnr = new QLineEdit(frame_1);
        inputPnr->setObjectName(QStringLiteral("inputPnr"));
        inputPnr->setGeometry(QRect(260, 50, 201, 31));
        inputMinHR = new QLineEdit(frame_1);
        inputMinHR->setObjectName(QStringLiteral("inputMinHR"));
        inputMinHR->setGeometry(QRect(260, 130, 61, 31));
        inputMinRR = new QLineEdit(frame_1);
        inputMinRR->setObjectName(QStringLiteral("inputMinRR"));
        inputMinRR->setGeometry(QRect(260, 190, 61, 31));
        inputMaxRR = new QLineEdit(frame_1);
        inputMaxRR->setObjectName(QStringLiteral("inputMaxRR"));
        inputMaxRR->setGeometry(QRect(370, 190, 61, 31));
        inputMaxHR = new QLineEdit(frame_1);
        inputMaxHR->setObjectName(QStringLiteral("inputMaxHR"));
        inputMaxHR->setGeometry(QRect(370, 130, 61, 31));
        labelDateTime = new QLabel(frame_1);
        labelDateTime->setObjectName(QStringLiteral("labelDateTime"));
        labelDateTime->setGeometry(QRect(10, 0, 231, 31));
        labelDateTime->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        heimdall_VSClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(heimdall_VSClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        heimdall_VSClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(heimdall_VSClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        heimdall_VSClass->setStatusBar(statusBar);

        retranslateUi(heimdall_VSClass);
        QObject::connect(pushStart, SIGNAL(clicked()), frame_2, SLOT(show()));
        QObject::connect(pushStart, SIGNAL(clicked()), frame_1, SLOT(close()));

        QMetaObject::connectSlotsByName(heimdall_VSClass);
    } // setupUi

    void retranslateUi(QMainWindow *heimdall_VSClass)
    {
        heimdall_VSClass->setWindowTitle(QApplication::translate("heimdall_VSClass", "heimdall_VS", 0));
        labelHeartRate_2->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Heart rate:</span></p></body></html>", 0));
        labelRespRate_2->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Respiratory rate:</span></p></body></html>", 0));
        labelHRNumber->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:400;\">120</span></p></body></html>", 0));
        labelRRNumber->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">60</span></p></body></html>", 0));
        label->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Min: </p></body></html>", 0));
        label_2->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Min: </p></body></html>", 0));
        label_3->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Max: </p></body></html>", 0));
        label_4->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Max: </p></body></html>", 0));
        label_5->setText(QApplication::translate("heimdall_VSClass", "bpm", 0));
        label_6->setText(QApplication::translate("heimdall_VSClass", "bpm", 0));
        labelDateTime_2->setText(QApplication::translate("heimdall_VSClass", "Date and Time", 0));
        label_7->setText(QApplication::translate("heimdall_VSClass", "Personal ID number", 0));
        pushSelectROI->setText(QApplication::translate("heimdall_VSClass", "Select resp.ROI", 0));
        pushStart->setText(QApplication::translate("heimdall_VSClass", "Start measurement", 0));
        labelMinRR->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        labelRespRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-weight:600;\">Respiratory rate</span></p></body></html>", 0));
        labelMaxRR->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        labelMaxHR->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        labelMinHR->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        labelHeartRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-weight:600;\">Heart rate</span></p></body></html>", 0));
        labelPnr->setText(QApplication::translate("heimdall_VSClass", "Personal identification number:", 0));
        labelDateTime->setText(QApplication::translate("heimdall_VSClass", "Date and Time", 0));
    } // retranslateUi

};

namespace Ui {
    class heimdall_VSClass: public Ui_heimdall_VSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIMDALL_VS_H
