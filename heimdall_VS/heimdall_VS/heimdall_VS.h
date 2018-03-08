#pragma once

#include <QtWidgets/QMainWindow>
#include <QDateTime>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <Qt>
#include "ui_heimdall_VS.h"
#include <QPushButton>
#include <opencv2\opencv.hpp>
#include <opencv2\objdetect.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv\cv.h>
#include <iostream>

#include <stdint.h>
#include <stdio.h>

using namespace cv;

class QPushButton;

class heimdall_VS : public QMainWindow
{
	Q_OBJECT

public:
	heimdall_VS(QWidget *parent = Q_NULLPTR);
	
private:
	Ui::heimdall_VSClass ui;

	

	private slots:
	void on_pushStart_clicked();
	void on_pushSelectROI_clicked();
	void alarm();

	void on_pushStart_clicked();
	//heimdall_VS();

};
