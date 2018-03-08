#pragma once

#include <QtWidgets/QMainWindow>
#include <QDateTime>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QMessageBox>
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
};
