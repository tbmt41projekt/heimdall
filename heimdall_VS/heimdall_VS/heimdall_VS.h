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

class QPushButton;

class heimdall_VS : public QMainWindow
{
	Q_OBJECT

public:
	heimdall_VS(QWidget *parent = Q_NULLPTR);

private:
	Ui::heimdall_VSClass ui;
	void on_pushStart_clicked();

	//heimdall_VS();

};
