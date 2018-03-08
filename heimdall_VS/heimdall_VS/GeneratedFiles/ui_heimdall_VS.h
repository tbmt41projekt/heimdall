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
    QLabel *HeartRate;
    QLabel *RespRate;
    QLabel *HRNumber;
    QLabel *RRNumber;
    QLabel *MinHR;
    QLabel *MinRR;
    QLabel *MaxHR;
    QLabel *MaxRR;
    QLabel *bpm1;
    QLabel *bpm2;
    QLabel *labelDateTime_2;
    QLabel *labelPnr_2;
    QLabel *labelMinHR_2;
    QLabel *labelMaxHR_2;
    QLabel *labelMinRR_2;
    QLabel *labelMaxRR_2;
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
        heimdall_VSClass->resize(1123, 900);
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
        HeartRate = new QLabel(frame_2);
        HeartRate->setObjectName(QStringLiteral("HeartRate"));
        HeartRate->setGeometry(QRect(60, 140, 131, 31));
        HeartRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        RespRate = new QLabel(frame_2);
        RespRate->setObjectName(QStringLiteral("RespRate"));
        RespRate->setGeometry(QRect(30, 250, 201, 31));
        RespRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        HRNumber = new QLabel(frame_2);
        HRNumber->setObjectName(QStringLiteral("HRNumber"));
        HRNumber->setGeometry(QRect(50, 170, 121, 61));
        RRNumber = new QLabel(frame_2);
        RRNumber->setObjectName(QStringLiteral("RRNumber"));
        RRNumber->setGeometry(QRect(50, 280, 121, 61));
        MinHR = new QLabel(frame_2);
        MinHR->setObjectName(QStringLiteral("MinHR"));
        MinHR->setGeometry(QRect(40, 230, 41, 21));
        MinRR = new QLabel(frame_2);
        MinRR->setObjectName(QStringLiteral("MinRR"));
        MinRR->setGeometry(QRect(40, 340, 41, 21));
        MaxHR = new QLabel(frame_2);
        MaxHR->setObjectName(QStringLiteral("MaxHR"));
        MaxHR->setGeometry(QRect(120, 230, 41, 21));
        MaxRR = new QLabel(frame_2);
        MaxRR->setObjectName(QStringLiteral("MaxRR"));
        MaxRR->setGeometry(QRect(120, 340, 41, 21));
        bpm1 = new QLabel(frame_2);
        bpm1->setObjectName(QStringLiteral("bpm1"));
        bpm1->setGeometry(QRect(170, 200, 61, 31));
        bpm2 = new QLabel(frame_2);
        bpm2->setObjectName(QStringLiteral("bpm2"));
        bpm2->setGeometry(QRect(170, 310, 61, 31));
        labelDateTime_2 = new QLabel(frame_2);
        labelDateTime_2->setObjectName(QStringLiteral("labelDateTime_2"));
        labelDateTime_2->setGeometry(QRect(10, 0, 191, 21));
        labelDateTime_2->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        labelPnr_2 = new QLabel(frame_2);
        labelPnr_2->setObjectName(QStringLiteral("labelPnr_2"));
        labelPnr_2->setGeometry(QRect(180, 0, 151, 31));
        labelMinHR_2 = new QLabel(frame_2);
        labelMinHR_2->setObjectName(QStringLiteral("labelMinHR_2"));
        labelMinHR_2->setGeometry(QRect(80, 230, 41, 21));
        labelMaxHR_2 = new QLabel(frame_2);
        labelMaxHR_2->setObjectName(QStringLiteral("labelMaxHR_2"));
        labelMaxHR_2->setGeometry(QRect(160, 230, 41, 21));
        labelMinRR_2 = new QLabel(frame_2);
        labelMinRR_2->setObjectName(QStringLiteral("labelMinRR_2"));
        labelMinRR_2->setGeometry(QRect(80, 340, 41, 21));
        labelMaxRR_2 = new QLabel(frame_2);
        labelMaxRR_2->setObjectName(QStringLiteral("labelMaxRR_2"));
        labelMaxRR_2->setGeometry(QRect(160, 340, 41, 21));
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
        labelRespRate->setGeometry(QRect(30, 190, 191, 31));
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
        labelHeartRate->setGeometry(QRect(30, 130, 121, 31));
        labelHeartRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        labelPnr = new QLabel(frame_1);
        labelPnr->setObjectName(QStringLiteral("labelPnr"));
        labelPnr->setGeometry(QRect(30, 50, 271, 31));
        labelPnr->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));
        inputPnr = new QLineEdit(frame_1);
        inputPnr->setObjectName(QStringLiteral("inputPnr"));
        inputPnr->setGeometry(QRect(300, 50, 111, 31));
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

        QMetaObject::connectSlotsByName(heimdall_VSClass);
    } // setupUi

    void retranslateUi(QMainWindow *heimdall_VSClass)
    {
        heimdall_VSClass->setWindowTitle(QApplication::translate("heimdall_VSClass", "heimdall_VS", 0));
        HeartRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Heart rate:</span></p></body></html>", 0));
        RespRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Respiratory rate:</span></p></body></html>", 0));
        HRNumber->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:400;\">120</span></p></body></html>", 0));
        RRNumber->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">60</span></p></body></html>", 0));
        MinHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Min: </p></body></html>", 0));
        MinRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Min: </p></body></html>", 0));
        MaxHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Max: </p></body></html>", 0));
        MaxRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Max: </p></body></html>", 0));
        bpm1->setText(QApplication::translate("heimdall_VSClass", "bpm", 0));
        bpm2->setText(QApplication::translate("heimdall_VSClass", "bpm", 0));
        labelDateTime_2->setText(QApplication::translate("heimdall_VSClass", "Date and Time", 0));
        labelPnr_2->setText(QApplication::translate("heimdall_VSClass", "Personal ID number", 0));
        labelMinHR_2->setText(QApplication::translate("heimdall_VSClass", "130", 0));
        labelMaxHR_2->setText(QApplication::translate("heimdall_VSClass", "130", 0));
        labelMinRR_2->setText(QApplication::translate("heimdall_VSClass", "130", 0));
        labelMaxRR_2->setText(QApplication::translate("heimdall_VSClass", "130", 0));
        pushSelectROI->setText(QApplication::translate("heimdall_VSClass", "Select resp.ROI", 0));
        pushStart->setText(QApplication::translate("heimdall_VSClass", "Start measurement", 0));
        labelMinRR->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        labelRespRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Respiratory rate:</span></p></body></html>", 0));
        labelMaxRR->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        labelMaxHR->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        labelMinHR->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        labelHeartRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Heart rate:</span></p></body></html>", 0));
        labelPnr->setText(QApplication::translate("heimdall_VSClass", "Personal identification number:", 0));
        inputPnr->setText(QApplication::translate("heimdall_VSClass", "XXXXXX-XXXX", 0));
        inputMinHR->setText(QApplication::translate("heimdall_VSClass", "XXX", 0));
        inputMinRR->setText(QApplication::translate("heimdall_VSClass", "XXX", 0));
        inputMaxRR->setText(QApplication::translate("heimdall_VSClass", "XXX", 0));
        inputMaxHR->setText(QApplication::translate("heimdall_VSClass", "XXX", 0));
        labelDateTime->setText(QApplication::translate("heimdall_VSClass", "Date and Time", 0));
    } // retranslateUi

};

namespace Ui {
    class heimdall_VSClass: public Ui_heimdall_VSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIMDALL_VS_H
