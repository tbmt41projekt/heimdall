#include "LogbydateWindow.h"

LogbydateWindow::LogbydateWindow(QDialog *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QString filename = "output.txt";
	QFile Logbydate(filename);

	if (!Logbydate.exists())
	{
		qDebug() << "No such file: " << filename;
	}
	else
	{
		qDebug() << filename << " OK.";
	}

	QString contAct;

	if (Logbydate.open(QIODevice::ReadOnly))
	{
		QTextStream read(&Logbydate);
		contAct.append(read.readAll());
		Logbydate.close();
	}

	ui.logText->setText(contAct);
	//ui.logTextEdit->verticalScrollBar->setValue(ui.logTextEdit->verticalScrollBar->maximum());


}

LogbydateWindow::~LogbydateWindow()
{
}








