#pragma once

#include <QDialog>
#include <QFile>
#include "ui_LogbydateWindow.h"
#include "heimdall_VS.h"

class LogbydateWindow : public QDialog
{
	Q_OBJECT

public:
	LogbydateWindow(QDialog *parent = Q_NULLPTR);
	~LogbydateWindow();

private:
	Ui::LogbydateWindow ui;
};



