#pragma once

#include <QDialog>
#include <QPushButton>
#include "ui_AddNoteWindow.h"
#include "heimdall_VS.h"

class AddNoteWindow : public QDialog
{
	Q_OBJECT

public:
	AddNoteWindow(QString dateString, QString pnr, QDialog *parent = Q_NULLPTR);
	~AddNoteWindow();
	QString Pnr;
	QString DateString;
	
private:
	Ui::AddNoteWindow ui;

private slots:
	void on_pushAdd_clicked();
	void on_pushFalseAlarm_clicked();
	void on_pushGivenPatient_clicked();
	void on_pushSleep_clicked();
};
