/********************************************************************************
** Form generated from reading UI file 'heimdall_VS.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEIMDALL_VS_H
#define UI_HEIMDALL_VS_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
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
    QLabel *labellowHR;
    QLabel *labellowRR;
    QLabel *labelhighHR;
    QLabel *labelhighRR;
    QLabel *labelVideo;
    QPushButton *pushLog;
    QPushButton *pushLog_2;
    QPushButton *pushAddNote;
    QLabel *labelWARNING;
    QPushButton *pushRestart;
    QCalendarWidget *calendarWidget;
    QPushButton *reselectROI;
    QPushButton *muteFaceAlarm;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *heimdall_VSClass)
    {
        if (heimdall_VSClass->objectName().isEmpty())
            heimdall_VSClass->setObjectName(QStringLiteral("heimdall_VSClass"));
        heimdall_VSClass->resize(580, 449);
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
        inputPnr->setGeometry(QRect(300, 50, 121, 31));
        inputPnr->setFont(font);
        inputPnr->setCursorPosition(0);
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
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 501, 361));
        frame_2->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        HeartRate = new QLabel(frame_2);
        HeartRate->setObjectName(QStringLiteral("HeartRate"));
        HeartRate->setGeometry(QRect(60, 160, 131, 31));
        HeartRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        RespRate = new QLabel(frame_2);
        RespRate->setObjectName(QStringLiteral("RespRate"));
        RespRate->setGeometry(QRect(30, 260, 201, 31));
        RespRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        HRNumber = new QLabel(frame_2);
        HRNumber->setObjectName(QStringLiteral("HRNumber"));
        HRNumber->setEnabled(true);
        HRNumber->setGeometry(QRect(50, 180, 120, 61));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(HRNumber->sizePolicy().hasHeightForWidth());
        HRNumber->setSizePolicy(sizePolicy);
        HRNumber->setMinimumSize(QSize(120, 61));
        HRNumber->setSizeIncrement(QSize(0, 0));
        HRNumber->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        HRNumber->setFont(font1);
        HRNumber->setFocusPolicy(Qt::NoFocus);
        HRNumber->setContextMenuPolicy(Qt::NoContextMenu);
        HRNumber->setText(QLatin1String("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:36px; margin-bottom:36px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:72;\">-</span></p></body></html>"));
        HRNumber->setTextFormat(Qt::AutoText);
        HRNumber->setScaledContents(false);
        HRNumber->setAlignment(Qt::AlignCenter);
        HRNumber->setMargin(0);
        HRNumber->setIndent(-1);
        RRNumber = new QLabel(frame_2);
        RRNumber->setObjectName(QStringLiteral("RRNumber"));
        RRNumber->setGeometry(QRect(50, 280, 121, 61));
        RRNumber->setFont(font1);
        RRNumber->setTextFormat(Qt::RichText);
        RRNumber->setAlignment(Qt::AlignCenter);
        MinHR = new QLabel(frame_2);
        MinHR->setObjectName(QStringLiteral("MinHR"));
        MinHR->setGeometry(QRect(40, 240, 71, 21));
        MinHR->setFrameShape(QFrame::Box);
        MinRR = new QLabel(frame_2);
        MinRR->setObjectName(QStringLiteral("MinRR"));
        MinRR->setGeometry(QRect(40, 340, 71, 21));
        MinRR->setFrameShape(QFrame::Box);
        MaxHR = new QLabel(frame_2);
        MaxHR->setObjectName(QStringLiteral("MaxHR"));
        MaxHR->setGeometry(QRect(120, 240, 71, 21));
        MaxHR->setFrameShape(QFrame::Box);
        MaxRR = new QLabel(frame_2);
        MaxRR->setObjectName(QStringLiteral("MaxRR"));
        MaxRR->setGeometry(QRect(120, 340, 71, 21));
        MaxRR->setFrameShape(QFrame::Box);
        bpm1 = new QLabel(frame_2);
        bpm1->setObjectName(QStringLiteral("bpm1"));
        bpm1->setGeometry(QRect(170, 210, 61, 31));
        bpm2 = new QLabel(frame_2);
        bpm2->setObjectName(QStringLiteral("bpm2"));
        bpm2->setGeometry(QRect(170, 310, 61, 31));
        labelDateTime_2 = new QLabel(frame_2);
        labelDateTime_2->setObjectName(QStringLiteral("labelDateTime_2"));
        labelDateTime_2->setGeometry(QRect(10, 0, 191, 31));
        labelDateTime_2->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        labelPnr_2 = new QLabel(frame_2);
        labelPnr_2->setObjectName(QStringLiteral("labelPnr_2"));
        labelPnr_2->setGeometry(QRect(190, 0, 151, 31));
        labelMinHR_2 = new QLabel(frame_2);
        labelMinHR_2->setObjectName(QStringLiteral("labelMinHR_2"));
        labelMinHR_2->setGeometry(QRect(80, 240, 41, 21));
        labelMaxHR_2 = new QLabel(frame_2);
        labelMaxHR_2->setObjectName(QStringLiteral("labelMaxHR_2"));
        labelMaxHR_2->setGeometry(QRect(160, 240, 41, 21));
        labelMinRR_2 = new QLabel(frame_2);
        labelMinRR_2->setObjectName(QStringLiteral("labelMinRR_2"));
        labelMinRR_2->setGeometry(QRect(80, 340, 41, 21));
        labelMaxRR_2 = new QLabel(frame_2);
        labelMaxRR_2->setObjectName(QStringLiteral("labelMaxRR_2"));
        labelMaxRR_2->setGeometry(QRect(160, 340, 41, 21));
        labellowHR = new QLabel(frame_2);
        labellowHR->setObjectName(QStringLiteral("labellowHR"));
        labellowHR->setGeometry(QRect(270, 200, 191, 31));
        labellowHR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));
        labellowRR = new QLabel(frame_2);
        labellowRR->setObjectName(QStringLiteral("labellowRR"));
        labellowRR->setGeometry(QRect(250, 300, 221, 31));
        labellowRR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));
        labelhighHR = new QLabel(frame_2);
        labelhighHR->setObjectName(QStringLiteral("labelhighHR"));
        labelhighHR->setGeometry(QRect(270, 200, 191, 31));
        labelhighHR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));
        labelhighRR = new QLabel(frame_2);
        labelhighRR->setObjectName(QStringLiteral("labelhighRR"));
        labelhighRR->setGeometry(QRect(250, 300, 221, 31));
        labelhighRR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));
        labelVideo = new QLabel(frame_2);
        labelVideo->setObjectName(QStringLiteral("labelVideo"));
        labelVideo->setGeometry(QRect(16, 32, 211, 131));
        labelVideo->setAutoFillBackground(true);
        labelVideo->setAlignment(Qt::AlignCenter);
        pushLog = new QPushButton(frame_2);
        pushLog->setObjectName(QStringLiteral("pushLog"));
        pushLog->setGeometry(QRect(410, 40, 71, 31));
        pushLog->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        pushLog_2 = new QPushButton(frame_2);
        pushLog_2->setObjectName(QStringLiteral("pushLog_2"));
        pushLog_2->setGeometry(QRect(410, 10, 71, 31));
        pushLog_2->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        pushAddNote = new QPushButton(frame_2);
        pushAddNote->setObjectName(QStringLiteral("pushAddNote"));
        pushAddNote->setGeometry(QRect(410, 70, 71, 31));
        pushAddNote->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        labelWARNING = new QLabel(frame_2);
        labelWARNING->setObjectName(QStringLiteral("labelWARNING"));
        labelWARNING->setGeometry(QRect(240, 140, 241, 221));
        labelWARNING->setFont(font1);
        labelWARNING->setFrameShape(QFrame::Box);
        labelWARNING->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        pushRestart = new QPushButton(frame_2);
        pushRestart->setObjectName(QStringLiteral("pushRestart"));
        pushRestart->setGeometry(QRect(410, 100, 71, 31));
        pushRestart->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        calendarWidget = new QCalendarWidget(frame_2);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(60, 60, 341, 221));
        calendarWidget->setFont(font1);
        calendarWidget->setAutoFillBackground(true);
        calendarWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(true);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);
        reselectROI = new QPushButton(frame_2);
        reselectROI->setObjectName(QStringLiteral("reselectROI"));
        reselectROI->setGeometry(QRect(230, 80, 81, 31));
        reselectROI->setStyleSheet(QLatin1String("font: 8pt \"MS Shell Dlg 2\";\n"
""));
        muteFaceAlarm = new QPushButton(frame_2);
        muteFaceAlarm->setObjectName(QStringLiteral("muteFaceAlarm"));
        muteFaceAlarm->setGeometry(QRect(300, 330, 121, 23));
        pushAddNote->raise();
        HeartRate->raise();
        RespRate->raise();
        HRNumber->raise();
        RRNumber->raise();
        MinHR->raise();
        MinRR->raise();
        MaxHR->raise();
        MaxRR->raise();
        bpm1->raise();
        bpm2->raise();
        labelDateTime_2->raise();
        labelPnr_2->raise();
        labelMinHR_2->raise();
        labelMaxHR_2->raise();
        labelMinRR_2->raise();
        labelMaxRR_2->raise();
        labellowHR->raise();
        labellowRR->raise();
        labelhighHR->raise();
        labelhighRR->raise();
        labelVideo->raise();
        pushLog->raise();
        pushLog_2->raise();
        labelWARNING->raise();
        pushRestart->raise();
        calendarWidget->raise();
        reselectROI->raise();
        muteFaceAlarm->raise();
        heimdall_VSClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(heimdall_VSClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        heimdall_VSClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(heimdall_VSClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        heimdall_VSClass->setStatusBar(statusBar);
        QWidget::setTabOrder(inputPnr, inputMinHR);
        QWidget::setTabOrder(inputMinHR, inputMaxHR);
        QWidget::setTabOrder(inputMaxHR, inputMinRR);
        QWidget::setTabOrder(inputMinRR, inputMaxRR);
        QWidget::setTabOrder(inputMaxRR, pushSelectROI);
        QWidget::setTabOrder(pushSelectROI, pushStart);
        QWidget::setTabOrder(pushStart, pushLog);
        QWidget::setTabOrder(pushLog, pushLog_2);
        QWidget::setTabOrder(pushLog_2, pushAddNote);
        QWidget::setTabOrder(pushAddNote, calendarWidget);

        retranslateUi(heimdall_VSClass);

        QMetaObject::connectSlotsByName(heimdall_VSClass);
    } // setupUi

    void retranslateUi(QMainWindow *heimdall_VSClass)
    {
        heimdall_VSClass->setWindowTitle(QApplication::translate("heimdall_VSClass", "heimdall_VS", 0));
        pushSelectROI->setText(QApplication::translate("heimdall_VSClass", "Select resp.ROI", 0));
        pushStart->setText(QApplication::translate("heimdall_VSClass", "Start measurement", 0));
        labelMinRR->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        labelRespRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Respiratory rate:</span></p></body></html>", 0));
        labelMaxRR->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        labelMaxHR->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        labelMinHR->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        labelHeartRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Heart rate:</span></p></body></html>", 0));
        labelPnr->setText(QApplication::translate("heimdall_VSClass", "Personal identification number:", 0));
        inputPnr->setText(QString());
        inputMinHR->setText(QString());
        inputMinRR->setText(QString());
        inputMaxRR->setText(QString());
        inputMaxHR->setText(QString());
        labelDateTime->setText(QApplication::translate("heimdall_VSClass", "Date and Time", 0));
        HeartRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Heart rate:</span></p></body></html>", 0));
        RespRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Respiratory rate:</span></p></body></html>", 0));
        RRNumber->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">-</span></p></body></html>", 0));
        MinHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Min: </p></body></html>", 0));
        MinRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Min: </p></body></html>", 0));
        MaxHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Max: </p></body></html>", 0));
        MaxRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Max: </p></body></html>", 0));
        bpm1->setText(QApplication::translate("heimdall_VSClass", "bpm", 0));
        bpm2->setText(QApplication::translate("heimdall_VSClass", "bpm", 0));
        labelDateTime_2->setText(QApplication::translate("heimdall_VSClass", "Date and Time", 0));
        labelPnr_2->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\">PNR: </p></body></html>", 0));
        labelMinHR_2->setText(QApplication::translate("heimdall_VSClass", "0", 0));
        labelMaxHR_2->setText(QApplication::translate("heimdall_VSClass", "0", 0));
        labelMinRR_2->setText(QApplication::translate("heimdall_VSClass", "0", 0));
        labelMaxRR_2->setText(QApplication::translate("heimdall_VSClass", "0", 0));
        labellowHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Low heart rate</span></p></body></html>", 0));
        labellowRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Low respiratory rate</span></p></body></html>", 0));
        labelhighHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">High heart rate</span></p></body></html>", 0));
        labelhighRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">High respiratory rate</span></p></body></html>", 0));
        labelVideo->setText(QString());
        pushLog->setText(QApplication::translate("heimdall_VSClass", "Log by date", 0));
        pushLog_2->setText(QApplication::translate("heimdall_VSClass", "Log", 0));
        pushAddNote->setText(QApplication::translate("heimdall_VSClass", "Add note", 0));
        labelWARNING->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; color:#ff0000;\">WARNING</span></p></body></html>", 0));
        pushRestart->setText(QApplication::translate("heimdall_VSClass", "Restart", 0));
        reselectROI->setText(QApplication::translate("heimdall_VSClass", "Reselect ROI", 0));
        muteFaceAlarm->setText(QApplication::translate("heimdall_VSClass", "Mute face alarm", 0));
    } // retranslateUi

};

namespace Ui {
    class heimdall_VSClass: public Ui_heimdall_VSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIMDALL_VS_H
