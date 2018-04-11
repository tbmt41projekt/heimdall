#pragma once

#include <QDialog>
#include <QFile>
#include "ui_LogWindow.h"
#include "heimdall_VS.h"

class LogWindow : public QDialog
{
	Q_OBJECT

public:
	LogWindow(QDialog *parent = Q_NULLPTR);
	~LogWindow();
	void setLog(QString logstr);

private:
	Ui::LogWindow ui;



};
