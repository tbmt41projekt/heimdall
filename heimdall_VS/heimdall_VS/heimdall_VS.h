#pragma once

#include <QtWidgets/QMainWindow>
#include <QDateTime>
#include <QString>
#include <Qt>
#include "ui_heimdall_VS.h"
#include <QPushButton>

class heimdall_VS : public QMainWindow
{
	Q_OBJECT

public:
	heimdall_VS(QWidget *parent = Q_NULLPTR);
	
private:
	Ui::heimdall_VSClass ui;
	

	private slots:
	void on_pushStart_clicked();
};
