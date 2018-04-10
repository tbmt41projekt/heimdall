#include "LogWindow.h"

LogWindow::LogWindow(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	QString filename = "logg.txt";

	QFile log(filename);

	if(!log.exists())
	{
		qDebug() << "No such file: " << filename;
	}
	else
	{
		qDebug() << filename << "yes...";
	}
	ui.logTextEdit->clear();
	QString line;
	if (log.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream(&log);
		while (!stream.atEnd())
		{
			line = stream.readLine();
			ui.logTextEdit->setPlainText(ui.logTextEdit->toPlainText() + line + "\n");
			//qDebug() << line;
		}
	}
	log.close();


	QTextStream in(&log);

	ui.logTextEdit->setPlainText(in.readAll());
	

}

LogWindow::~LogWindow()
{
}
