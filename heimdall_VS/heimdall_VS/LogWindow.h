#pragma once

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "ui_LogWindow.h"
//#include "heimdall_VS.h"

class LogWindow : public QDialog
{
	Q_OBJECT

public:
	LogWindow(QString pnr, QString dateString, QDialog *parent = Q_NULLPTR);
	~LogWindow();

	QString pnr;

	void start();

private:
	Ui::LogWindow ui;

};
