#include "LogWindow.h"

LogWindow::LogWindow(QString pnr, QString dateString, QDialog *parent)
	:
	QDialog(parent)
{
	ui.setupUi(this);

	QString filename = pnr + "_logg.txt";
	QFile log(filename);

	/*if(!log.exists())
	{
		qDebug() << "No such file: " << filename;
	}
	else
	{
		qDebug() << filename << " OK.";
	}*/
	
	QString contAct;

	if (log.open(QIODevice::ReadOnly))
	{
		QTextStream read(&log);
		contAct.append(read.readAll());
		log.close();
	}

	ui.logText->setText(contAct);
	//ui.logTextEdit->verticalScrollBar->setValue(ui.logTextEdit->verticalScrollBar->maximum());
	
}

LogWindow::~LogWindow()
{
}
