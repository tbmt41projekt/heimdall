#pragma once

#include <QtWidgets/QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QMessageBox>
#include <QMouseEvent>
#include <QValidator>
#include <QRegExp>
#include <Qt>
#include <QtCore>
#include <QtGui>
#include <QFont>
#include <QFile>
#include <QTextStream>
#include <opencv2\opencv.hpp>
#include <opencv2\objdetect.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\core.hpp>
#include <opencv\cv.h>
#include <iostream>
#include <random>
#include <QPixmap>
#include <QImage>
#include <QApplication>
#include <stdint.h>
#include <stdio.h>
#include "ui_heimdall_VS.h"
#include "Pulse.h"
#include "Respiration.h"
#include "LogWindow.h"
#include "ui_LogWindow.h"
#include "LogbydateWindow.h"
#include "ui_LogbydateWindow.h"
#include <windows.h>
#include "ui_RoiWindow.h"
#include "RoiWindow.h"

using namespace cv;

class heimdall_VS : public QMainWindow
{
	Q_OBJECT

public:
	heimdall_VS(QWidget *parent = Q_NULLPTR);
	~heimdall_VS();
	void setLog(QString logstr);
	QString pnr;
	bool onDisplayWindow;

	void setPulse(int pulse);
	void setResp(int resp);
	void updateFrame(Mat & frame);


private:
	Ui::heimdall_VSClass ui;
	QTimer *timer1;
	QTimer *timer2;
	//bool readyForCamera;
	bool showSelectROI;
	Mat newFrame;
	//LogWindow *logWindow = nullptr;
	QMessageBox faceError;
	LogWindow logWindow{};
	RoiWindow roiWindow{};

	void findSelectedDate(QString search);
	void checkLarm(QString rateType, int measurement, QString & minQString, QString & maxQString, QLabel * lowLabel, QLabel * highLabel);
	cv::VideoCapture capCamera;

	private slots:
	void on_pushStart_clicked();
	//void processFrameAndUpdateGUI();
	void showTime();
	void on_pushSelectROI_clicked();
	void on_pushLog_clicked();
	void getValues();
	//void updateRandomNumber();
	void alarm();
	void on_calendarWidget_clicked();
	void on_pushLog_2_clicked();
	//void updateLogWindow();
};