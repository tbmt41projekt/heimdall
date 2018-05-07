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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_heimdall_VSClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *frame_1;
    QGridLayout *gridLayout_2;
    QLabel *labelDateTime;
    QLabel *labelHeartRate;
    QPushButton *pushStart;
    QLabel *labelRespRate;
    QLabel *labelPnr;
    QPushButton *pushSelectROI;
    QLabel *labelMaxRR;
    QLabel *labelMinHR;
    QLineEdit *inputMaxRR;
    QLabel *labelMaxHR;
    QLineEdit *inputMinHR;
    QLineEdit *inputMinRR;
    QLineEdit *inputPnr;
    QLabel *labelMinRR;
    QLineEdit *inputMaxHR;
    QPushButton *pushButton;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QPushButton *muteFaceAlarm;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelWARNING;
    QLabel *labelNoHR;
    QLabel *labellowHR;
    QLabel *labelhighRR;
    QLabel *labelNoRR;
    QLabel *labellowRR;
    QLabel *labelhighHR;
    QCalendarWidget *calendarWidget;
    QPushButton *reselectROI;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *HeartRate;
    QLabel *HRNumber;
    QLabel *bpm1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *MinHR;
    QLabel *labelMinHR_2;
    QLabel *MaxHR;
    QLabel *labelMaxHR_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *RespRate;
    QLabel *RRNumber;
    QLabel *bpm2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *MinRR;
    QLabel *labelMinRR_2;
    QLabel *MaxRR;
    QLabel *labelMaxRR_2;
    QLabel *labelVideo;
    QLabel *labelDateTime_2;
    QLabel *labelPnr_2;
    QPushButton *pushLog_2;
    QPushButton *pushRestart;
    QPushButton *pushLog;
    QPushButton *pushAddNote;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *heimdall_VSClass)
    {
        if (heimdall_VSClass->objectName().isEmpty())
            heimdall_VSClass->setObjectName(QStringLiteral("heimdall_VSClass"));
        heimdall_VSClass->resize(812, 1217);
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
        centralWidget->setEnabled(true);
        centralWidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_1 = new QFrame(centralWidget);
        frame_1->setObjectName(QStringLiteral("frame_1"));
        frame_1->setEnabled(true);
        gridLayout_2 = new QGridLayout(frame_1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelDateTime = new QLabel(frame_1);
        labelDateTime->setObjectName(QStringLiteral("labelDateTime"));
        labelDateTime->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(labelDateTime, 1, 0, 1, 1, Qt::AlignLeft|Qt::AlignTop);

        labelHeartRate = new QLabel(frame_1);
        labelHeartRate->setObjectName(QStringLiteral("labelHeartRate"));
        labelHeartRate->setMinimumSize(QSize(200, 30));
        labelHeartRate->setMaximumSize(QSize(200, 30));
        labelHeartRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(labelHeartRate, 16, 0, 1, 1, Qt::AlignRight);

        pushStart = new QPushButton(frame_1);
        pushStart->setObjectName(QStringLiteral("pushStart"));
        pushStart->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushStart->sizePolicy().hasHeightForWidth());
        pushStart->setSizePolicy(sizePolicy);
        pushStart->setMinimumSize(QSize(200, 30));
        pushStart->setMaximumSize(QSize(200, 30));
        pushStart->setFont(font);
        pushStart->setMouseTracking(false);
        pushStart->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        pushStart->setAutoDefault(false);

        gridLayout_2->addWidget(pushStart, 19, 0, 1, 1, Qt::AlignRight);

        labelRespRate = new QLabel(frame_1);
        labelRespRate->setObjectName(QStringLiteral("labelRespRate"));
        labelRespRate->setMinimumSize(QSize(200, 30));
        labelRespRate->setMaximumSize(QSize(200, 30));
        labelRespRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(labelRespRate, 17, 0, 1, 1, Qt::AlignRight);

        labelPnr = new QLabel(frame_1);
        labelPnr->setObjectName(QStringLiteral("labelPnr"));
        labelPnr->setMinimumSize(QSize(250, 30));
        labelPnr->setMaximumSize(QSize(280, 30));
        labelPnr->setStyleSheet(QStringLiteral("font: 14pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(labelPnr, 3, 0, 1, 1);

        pushSelectROI = new QPushButton(frame_1);
        pushSelectROI->setObjectName(QStringLiteral("pushSelectROI"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushSelectROI->sizePolicy().hasHeightForWidth());
        pushSelectROI->setSizePolicy(sizePolicy1);
        pushSelectROI->setMinimumSize(QSize(200, 30));
        pushSelectROI->setMaximumSize(QSize(200, 30));
        pushSelectROI->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(pushSelectROI, 18, 0, 1, 1, Qt::AlignRight);

        labelMaxRR = new QLabel(frame_1);
        labelMaxRR->setObjectName(QStringLiteral("labelMaxRR"));
        labelMaxRR->setMinimumSize(QSize(50, 30));
        labelMaxRR->setMaximumSize(QSize(50, 30));
        labelMaxRR->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(labelMaxRR, 17, 3, 1, 1);

        labelMinHR = new QLabel(frame_1);
        labelMinHR->setObjectName(QStringLiteral("labelMinHR"));
        labelMinHR->setMinimumSize(QSize(50, 30));
        labelMinHR->setMaximumSize(QSize(50, 30));

        gridLayout_2->addWidget(labelMinHR, 16, 1, 1, 1, Qt::AlignRight);

        inputMaxRR = new QLineEdit(frame_1);
        inputMaxRR->setObjectName(QStringLiteral("inputMaxRR"));
        inputMaxRR->setMinimumSize(QSize(100, 30));
        inputMaxRR->setMaximumSize(QSize(100, 30));

        gridLayout_2->addWidget(inputMaxRR, 17, 4, 1, 1);

        labelMaxHR = new QLabel(frame_1);
        labelMaxHR->setObjectName(QStringLiteral("labelMaxHR"));
        labelMaxHR->setMinimumSize(QSize(50, 30));
        labelMaxHR->setMaximumSize(QSize(50, 30));

        gridLayout_2->addWidget(labelMaxHR, 16, 3, 1, 1);

        inputMinHR = new QLineEdit(frame_1);
        inputMinHR->setObjectName(QStringLiteral("inputMinHR"));
        inputMinHR->setMinimumSize(QSize(100, 30));
        inputMinHR->setMaximumSize(QSize(100, 30));

        gridLayout_2->addWidget(inputMinHR, 16, 2, 1, 1, Qt::AlignLeft);

        inputMinRR = new QLineEdit(frame_1);
        inputMinRR->setObjectName(QStringLiteral("inputMinRR"));
        inputMinRR->setMinimumSize(QSize(100, 30));
        inputMinRR->setMaximumSize(QSize(100, 30));

        gridLayout_2->addWidget(inputMinRR, 17, 2, 1, 1, Qt::AlignLeft);

        inputPnr = new QLineEdit(frame_1);
        inputPnr->setObjectName(QStringLiteral("inputPnr"));
        inputPnr->setMinimumSize(QSize(100, 30));
        inputPnr->setMaximumSize(QSize(100, 30));
        inputPnr->setFont(font);
        inputPnr->setCursorPosition(0);

        gridLayout_2->addWidget(inputPnr, 3, 1, 1, 4);

        labelMinRR = new QLabel(frame_1);
        labelMinRR->setObjectName(QStringLiteral("labelMinRR"));
        labelMinRR->setMinimumSize(QSize(50, 30));
        labelMinRR->setMaximumSize(QSize(50, 30));

        gridLayout_2->addWidget(labelMinRR, 17, 1, 1, 1, Qt::AlignRight);

        inputMaxHR = new QLineEdit(frame_1);
        inputMaxHR->setObjectName(QStringLiteral("inputMaxHR"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(inputMaxHR->sizePolicy().hasHeightForWidth());
        inputMaxHR->setSizePolicy(sizePolicy2);
        inputMaxHR->setMinimumSize(QSize(100, 30));
        inputMaxHR->setMaximumSize(QSize(100, 30));

        gridLayout_2->addWidget(inputMaxHR, 16, 4, 1, 1);


        gridLayout->addWidget(frame_1, 0, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(200, 30));
        pushButton->setMaximumSize(QSize(200, 30));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setEnabled(true);
        frame_2->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
""));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        muteFaceAlarm = new QPushButton(frame_2);
        muteFaceAlarm->setObjectName(QStringLiteral("muteFaceAlarm"));

        gridLayout_3->addWidget(muteFaceAlarm, 24, 3, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelWARNING = new QLabel(frame_2);
        labelWARNING->setObjectName(QStringLiteral("labelWARNING"));
        labelWARNING->setMinimumSize(QSize(250, 70));
        labelWARNING->setMaximumSize(QSize(250, 70));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        labelWARNING->setFont(font1);
        labelWARNING->setFrameShape(QFrame::Box);
        labelWARNING->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_3->addWidget(labelWARNING, 0, Qt::AlignHCenter);

        labelNoHR = new QLabel(frame_2);
        labelNoHR->setObjectName(QStringLiteral("labelNoHR"));
        labelNoHR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));

        verticalLayout_3->addWidget(labelNoHR);

        labellowHR = new QLabel(frame_2);
        labellowHR->setObjectName(QStringLiteral("labellowHR"));
        labellowHR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));

        verticalLayout_3->addWidget(labellowHR);

        labelhighRR = new QLabel(frame_2);
        labelhighRR->setObjectName(QStringLiteral("labelhighRR"));
        labelhighRR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));

        verticalLayout_3->addWidget(labelhighRR);

        labelNoRR = new QLabel(frame_2);
        labelNoRR->setObjectName(QStringLiteral("labelNoRR"));
        labelNoRR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));

        verticalLayout_3->addWidget(labelNoRR);

        labellowRR = new QLabel(frame_2);
        labellowRR->setObjectName(QStringLiteral("labellowRR"));
        labellowRR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));

        verticalLayout_3->addWidget(labellowRR, 0, Qt::AlignHCenter);

        labelhighHR = new QLabel(frame_2);
        labelhighHR->setObjectName(QStringLiteral("labelhighHR"));
        labelhighHR->setStyleSheet(QLatin1String("font: 12pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 0, 0);\n"
""));

        verticalLayout_3->addWidget(labelhighHR);


        gridLayout_3->addLayout(verticalLayout_3, 10, 3, 4, 1);

        calendarWidget = new QCalendarWidget(frame_2);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setFont(font1);
        calendarWidget->setAutoFillBackground(true);
        calendarWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(true);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);

        gridLayout_3->addWidget(calendarWidget, 5, 3, 1, 1);

        reselectROI = new QPushButton(frame_2);
        reselectROI->setObjectName(QStringLiteral("reselectROI"));
        reselectROI->setMinimumSize(QSize(100, 30));
        reselectROI->setMaximumSize(QSize(100, 30));
        reselectROI->setStyleSheet(QLatin1String("font: 8pt \"MS Shell Dlg 2\";\n"
""));

        gridLayout_3->addWidget(reselectROI, 7, 0, 1, 1, Qt::AlignHCenter);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        HeartRate = new QLabel(frame_2);
        HeartRate->setObjectName(QStringLiteral("HeartRate"));
        HeartRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));

        horizontalLayout_6->addWidget(HeartRate);

        HRNumber = new QLabel(frame_2);
        HRNumber->setObjectName(QStringLiteral("HRNumber"));
        HRNumber->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(HRNumber->sizePolicy().hasHeightForWidth());
        HRNumber->setSizePolicy(sizePolicy3);
        HRNumber->setMinimumSize(QSize(120, 61));
        HRNumber->setSizeIncrement(QSize(0, 0));
        HRNumber->setBaseSize(QSize(0, 0));
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

        horizontalLayout_6->addWidget(HRNumber);

        bpm1 = new QLabel(frame_2);
        bpm1->setObjectName(QStringLiteral("bpm1"));

        horizontalLayout_6->addWidget(bpm1);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        MinHR = new QLabel(frame_2);
        MinHR->setObjectName(QStringLiteral("MinHR"));
        MinHR->setMinimumSize(QSize(70, 20));
        MinHR->setMaximumSize(QSize(70, 20));
        MinHR->setFrameShape(QFrame::Box);

        horizontalLayout_5->addWidget(MinHR);

        labelMinHR_2 = new QLabel(frame_2);
        labelMinHR_2->setObjectName(QStringLiteral("labelMinHR_2"));

        horizontalLayout_5->addWidget(labelMinHR_2);

        MaxHR = new QLabel(frame_2);
        MaxHR->setObjectName(QStringLiteral("MaxHR"));
        MaxHR->setMinimumSize(QSize(70, 20));
        MaxHR->setMaximumSize(QSize(70, 20));
        MaxHR->setFrameShape(QFrame::Box);

        horizontalLayout_5->addWidget(MaxHR);

        labelMaxHR_2 = new QLabel(frame_2);
        labelMaxHR_2->setObjectName(QStringLiteral("labelMaxHR_2"));

        horizontalLayout_5->addWidget(labelMaxHR_2);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        RespRate = new QLabel(frame_2);
        RespRate->setObjectName(QStringLiteral("RespRate"));
        RespRate->setStyleSheet(QLatin1String("font: 75 12pt \"MS Shell Dlg 2\";\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));

        horizontalLayout_7->addWidget(RespRate);

        RRNumber = new QLabel(frame_2);
        RRNumber->setObjectName(QStringLiteral("RRNumber"));
        RRNumber->setFont(font1);
        RRNumber->setTextFormat(Qt::RichText);
        RRNumber->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(RRNumber);

        bpm2 = new QLabel(frame_2);
        bpm2->setObjectName(QStringLiteral("bpm2"));

        horizontalLayout_7->addWidget(bpm2);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        MinRR = new QLabel(frame_2);
        MinRR->setObjectName(QStringLiteral("MinRR"));
        MinRR->setMinimumSize(QSize(70, 20));
        MinRR->setMaximumSize(QSize(70, 20));
        MinRR->setFrameShape(QFrame::Box);

        horizontalLayout_9->addWidget(MinRR);

        labelMinRR_2 = new QLabel(frame_2);
        labelMinRR_2->setObjectName(QStringLiteral("labelMinRR_2"));

        horizontalLayout_9->addWidget(labelMinRR_2);

        MaxRR = new QLabel(frame_2);
        MaxRR->setObjectName(QStringLiteral("MaxRR"));
        MaxRR->setMinimumSize(QSize(70, 20));
        MaxRR->setMaximumSize(QSize(70, 20));
        MaxRR->setFrameShape(QFrame::Box);

        horizontalLayout_9->addWidget(MaxRR);

        labelMaxRR_2 = new QLabel(frame_2);
        labelMaxRR_2->setObjectName(QStringLiteral("labelMaxRR_2"));

        horizontalLayout_9->addWidget(labelMaxRR_2);


        verticalLayout_7->addLayout(horizontalLayout_9);


        gridLayout_3->addLayout(verticalLayout_7, 10, 0, 1, 1);

        labelVideo = new QLabel(frame_2);
        labelVideo->setObjectName(QStringLiteral("labelVideo"));
        sizePolicy1.setHeightForWidth(labelVideo->sizePolicy().hasHeightForWidth());
        labelVideo->setSizePolicy(sizePolicy1);
        labelVideo->setMinimumSize(QSize(133, 100));
        labelVideo->setMaximumSize(QSize(400, 300));
        labelVideo->setAutoFillBackground(true);
        labelVideo->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelVideo, 5, 0, 1, 1);

        labelDateTime_2 = new QLabel(frame_2);
        labelDateTime_2->setObjectName(QStringLiteral("labelDateTime_2"));
        labelDateTime_2->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));

        gridLayout_3->addWidget(labelDateTime_2, 0, 0, 1, 1);

        labelPnr_2 = new QLabel(frame_2);
        labelPnr_2->setObjectName(QStringLiteral("labelPnr_2"));

        gridLayout_3->addWidget(labelPnr_2, 0, 2, 1, 1);

        pushLog_2 = new QPushButton(frame_2);
        pushLog_2->setObjectName(QStringLiteral("pushLog_2"));
        pushLog_2->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));

        gridLayout_3->addWidget(pushLog_2, 0, 5, 1, 1);

        pushRestart = new QPushButton(frame_2);
        pushRestart->setObjectName(QStringLiteral("pushRestart"));
        pushRestart->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));

        gridLayout_3->addWidget(pushRestart, 4, 5, 1, 1);

        pushLog = new QPushButton(frame_2);
        pushLog->setObjectName(QStringLiteral("pushLog"));
        pushLog->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));

        gridLayout_3->addWidget(pushLog, 1, 5, 1, 1);

        pushAddNote = new QPushButton(frame_2);
        pushAddNote->setObjectName(QStringLiteral("pushAddNote"));
        pushAddNote->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));

        gridLayout_3->addWidget(pushAddNote, 3, 5, 1, 1);


        gridLayout->addWidget(frame_2, 1, 0, 1, 1);

        heimdall_VSClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(heimdall_VSClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        heimdall_VSClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(heimdall_VSClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        heimdall_VSClass->setStatusBar(statusBar);

        retranslateUi(heimdall_VSClass);

        pushStart->setDefault(true);
        pushSelectROI->setDefault(true);


        QMetaObject::connectSlotsByName(heimdall_VSClass);
    } // setupUi

    void retranslateUi(QMainWindow *heimdall_VSClass)
    {
        heimdall_VSClass->setWindowTitle(QApplication::translate("heimdall_VSClass", "heimdall_VS", 0));
        labelDateTime->setText(QApplication::translate("heimdall_VSClass", "Date and Time", 0));
        labelHeartRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Heart rate:</span></p></body></html>", 0));
        pushStart->setText(QApplication::translate("heimdall_VSClass", "Start measurement", 0));
        labelRespRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Respiratory rate:</span></p></body></html>", 0));
        labelPnr->setText(QApplication::translate("heimdall_VSClass", "Personal identification number:", 0));
        pushSelectROI->setText(QApplication::translate("heimdall_VSClass", "Select resp.ROI", 0));
        labelMaxRR->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        labelMinHR->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        inputMaxRR->setText(QString());
        labelMaxHR->setText(QApplication::translate("heimdall_VSClass", "Max:", 0));
        inputMinHR->setText(QString());
        inputMinRR->setText(QString());
        inputPnr->setText(QString());
        labelMinRR->setText(QApplication::translate("heimdall_VSClass", "Min:", 0));
        inputMaxHR->setText(QString());
        pushButton->setText(QApplication::translate("heimdall_VSClass", "Load patient history", 0));
        muteFaceAlarm->setText(QApplication::translate("heimdall_VSClass", "Mute face alarm", 0));
        labelWARNING->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; color:#ff0000;\">WARNING</span></p></body></html>", 0));
        labelNoHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">No heart rate</span></p></body></html>", 0));
        labellowHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Low heart rate</span></p></body></html>", 0));
        labelhighRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">High respiratory rate</span></p></body></html>", 0));
        labelNoRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">No respiratory rate</span></p></body></html>", 0));
        labellowRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Low respiratory rate</span></p></body></html>", 0));
        labelhighHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">High heart rate</span></p></body></html>", 0));
        reselectROI->setText(QApplication::translate("heimdall_VSClass", "Reselect ROI", 0));
        HeartRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Heart rate:</span></p></body></html>", 0));
        bpm1->setText(QApplication::translate("heimdall_VSClass", "bpm", 0));
        MinHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Min: </p></body></html>", 0));
        labelMinHR_2->setText(QApplication::translate("heimdall_VSClass", "0", 0));
        MaxHR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Max: </p></body></html>", 0));
        labelMaxHR_2->setText(QApplication::translate("heimdall_VSClass", "0", 0));
        RespRate->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:400;\">Respiratory rate:</span></p></body></html>", 0));
        RRNumber->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">-</span></p></body></html>", 0));
        bpm2->setText(QApplication::translate("heimdall_VSClass", "bpm", 0));
        MinRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Min: </p></body></html>", 0));
        labelMinRR_2->setText(QApplication::translate("heimdall_VSClass", "0", 0));
        MaxRR->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p>Max: </p></body></html>", 0));
        labelMaxRR_2->setText(QApplication::translate("heimdall_VSClass", "0", 0));
        labelVideo->setText(QString());
        labelDateTime_2->setText(QApplication::translate("heimdall_VSClass", "Date and Time", 0));
        labelPnr_2->setText(QApplication::translate("heimdall_VSClass", "<html><head/><body><p align=\"center\">PNR: </p></body></html>", 0));
        pushLog_2->setText(QApplication::translate("heimdall_VSClass", "Log", 0));
        pushRestart->setText(QApplication::translate("heimdall_VSClass", "Restart", 0));
        pushLog->setText(QApplication::translate("heimdall_VSClass", "Log by date", 0));
        pushAddNote->setText(QApplication::translate("heimdall_VSClass", "Add note", 0));
    } // retranslateUi

};

namespace Ui {
    class heimdall_VSClass: public Ui_heimdall_VSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIMDALL_VS_H
