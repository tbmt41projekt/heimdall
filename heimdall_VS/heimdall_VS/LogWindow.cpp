#include "LogWindow.h"

LogWindow::LogWindow(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QString emptyString = "";
	setLog(emptyString);
	ui.logTextEdit->clear();
	ui.logText->clear();

	QString filename = "logg.txt";
	QFile log(filename);

	if(!log.exists())
	{
		qDebug() << "No such file: " << filename;
	}
	else
	{
		qDebug() << filename << "Hittad.";
	}
	
	QString contAct;

	if (log.open(QIODevice::ReadOnly))
	{
		QTextStream read(&log);
		contAct.append(read.readAll());
		log.close();
	}

	ui.logText->setText(contAct);

	
}

LogWindow::~LogWindow()
{
}

void LogWindow::setLog(QString logstr)
{
	QString contAct;
	QFile log("logg.txt");
	
	if (log.open(QIODevice::ReadOnly | QIODevice::Truncate))
	{
		QTextStream read(&log);
		contAct.append(read.readAll());
		QString line;

		while (!read.atEnd())
		{
			line = read.readLine();
			ui.logTextEdit->setPlainText(line + "\n");
			ui.logText->setText(line + "\n");
			//qDebug() << line;
		}

		log.close();
	}

	ui.logTextEdit->setPlainText(contAct);
	ui.logText->setText(contAct);

	//ui.logTextEdit->verticalScrollBar->setValue(ui.logTextEdit->verticalScrollBar->maximum());

}
