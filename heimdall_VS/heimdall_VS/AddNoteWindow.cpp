#include "AddNoteWindow.h"

AddNoteWindow::AddNoteWindow(QString dateString, QString pnr, QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	Pnr = pnr;
	DateString = dateString;
}

void AddNoteWindow::on_pushAdd_clicked()
{
	QString filename = Pnr + "_logg.txt";
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


AddNoteWindow::~AddNoteWindow()
{
}
