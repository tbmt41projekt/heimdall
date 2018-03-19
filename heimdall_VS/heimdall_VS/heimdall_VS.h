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
#include "ui_heimdall_VS.h"



class heimdall_VS : public QMainWindow
{
	Q_OBJECT

public:
	heimdall_VS(QWidget *parent = Q_NULLPTR);

private: 
	Ui::heimdall_VSClass ui;

private slots:
	void on_pushStart_clicked();
	//heimdall_VS();

	void showTime();

	//protected:
//	virtual void mousePressEvent(QMouseEvent *);
};
