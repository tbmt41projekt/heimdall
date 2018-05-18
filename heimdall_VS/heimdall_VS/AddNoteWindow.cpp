#include "AddNoteWindow.h"

AddNoteWindow::AddNoteWindow(QString dateString, QString pnr, QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	Pnr = pnr;
	DateString = dateString;
}

AddNoteWindow::~AddNoteWindow()
{
}

void AddNoteWindow::on_pushAdd_clicked()
{
	QString filename = "Log files/" + Pnr + "_logg.txt";
	QFile log(filename);
	QString noteString = (DateString + "  -  NOTE: " + ui.lineNote->text() + " \n");

	if (log.open(QIODevice::Append))
	{
		QTextStream write(&log);
		write << noteString;
		log.close();
	}

	this->close();
}


void AddNoteWindow::on_pushFalseAlarm_clicked()
{
	ui.lineNote->setText("False alarm.");
}

void AddNoteWindow::on_pushGivenPatient_clicked()
{
	ui.lineNote->setText("Patient has been given: ");
}

void AddNoteWindow::on_pushSleep_clicked()
{
	ui.lineNote->setText("Patient is asleep.");
}
