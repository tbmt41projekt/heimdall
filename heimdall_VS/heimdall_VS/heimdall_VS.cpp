#include "heimdall_VS.h"


heimdall_VS::heimdall_VS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.inputPnr->setFocus();
	ui.inputPnr->setPlaceholderText("YYMMDD-XXXX");
	srand(time(NULL)); //SKA BORT, ENDAST FÖR TEST AV LARM

	//Skapar en timer så att klockan rullar
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start();


	//Fixar bakgrundsfärg på samtliga rutor
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::white);
	ui.frame_1->setAutoFillBackground(true);
	ui.frame_1->setPalette(pal);
	ui.frame_2->setAutoFillBackground(true);
	ui.frame_2->setPalette(pal);


	//Startruta
	ui.frame_2->setVisible(false);

	////Sätter tillåtna inputvärden för textrutorna

	QRegExp rxPnr("\[0-9]{6}[-]\[0-9]{4}");
	QValidator *validatorPnr = new QRegExpValidator(rxPnr);
	ui.inputPnr->setValidator(validatorPnr);

	QRegExp rxMaxMin("\[0-9]{1,3}");
	QValidator *validatorMaxMin = new QRegExpValidator(rxMaxMin);
	ui.inputMaxHR->setValidator(validatorMaxMin);
	ui.inputMinHR->setValidator(validatorMaxMin);
	ui.inputMaxRR->setValidator(validatorMaxMin);
	ui.inputMinRR->setValidator(validatorMaxMin);
}

// Larmfunktionen
void heimdall_VS::alarm()
{

}

// Funktion som skapar och visar datum och tid
void heimdall_VS::showTime()
{
	QDateTime date = QDateTime::currentDateTime();
	QString dateString = date.toString("ddMMyy hh:mm:ss");
	ui.labelDateTime->setText(dateString);
	ui.labelDateTime_2->setText(dateString);
}

void heimdall_VS::on_pushSelectROI_clicked()
{

}

// Startknappen
void heimdall_VS::on_pushStart_clicked()
{
	QString pnr = ui.inputPnr->text();
	QString maxHR = ui.inputMaxHR->text();
	QString minHR = ui.inputMinHR->text();
	QString maxRR = ui.inputMaxRR->text();
	QString minRR = ui.inputMinRR->text();

	if (ui.inputPnr->hasAcceptableInput() &&
		ui.inputMaxHR->hasAcceptableInput() &&
		ui.inputMinHR->hasAcceptableInput() &&
		ui.inputMaxRR->hasAcceptableInput() &&
		ui.inputMinRR->hasAcceptableInput() &&
		maxHR > minHR &&
		maxRR > minRR)
	{
		//Visa nästa frame, dvs mätrutan
		ui.frame_2->setVisible(true);
		ui.frame_1->setVisible(false);

		//Flytta över inputvärden till rätt plats
		ui.labelPnr_2->setText(pnr);
		ui.labelMaxHR_2->setText(maxHR);
		ui.labelMinHR_2->setText(minHR);
		ui.labelMaxRR_2->setText(maxRR);
		ui.labelMinRR_2->setText(minRR);

		//Hämtar värden från puls- och andningsklasserna
		getValues();
		ui.labellowHR->hide();
		ui.labelhighHR->hide();
		ui.labellowRR->hide();
		ui.labelhighRR->hide();

		QTimer *timer2 = new QTimer(this);
		timer2->setInterval(0);
		connect(timer2, SIGNAL(timeout()), this, SLOT(updateRandomNumber()));
		timer2->start();
	}
	else
	{
		QMessageBox msgBoxError;
		msgBoxError.setIcon(QMessageBox::Warning);
		msgBoxError.setWindowTitle("Error message");
		msgBoxError.setText("Not valid ID-number and/or input values.");
		msgBoxError.setInformativeText("Please make sure to type in the ID-number YYMMDD-XXXX, and that your intervals are correct.");
		msgBoxError.exec();
	}

}

//Funktion som hämtar värden från puls- och andningsklasserna
void heimdall_VS::getValues()
{
	//De tre raderna nedan funkar ej, men visa ex på vad som borde funka
	//QFont numFont ("Arial", 5, QFont::Bold);
	//ui.HRNumber->setFont(numFont);
	//ui.RRNumber->setFont(numFont);

	/*Pulse pulse;
	QString pulseString = QString::number(pulse.calculate());
	ui.HRNumber->setText(pulseString);

	Respiration respiration;
	QString respString = QString::number(respiration.calculate());
	ui.RRNumber->setText(respString);*/

	//Gömmer varningstexten på frame 2
	/*ui.labellowHR->hide();
	ui.labelhighHR->hide();
	ui.labellowRR->hide();
	ui.labelhighRR->hide();*/

}

void heimdall_VS::updateRandomNumber()
{
	qsrand((unsigned)time(0));
	ui.RRNumber->setText(QString::number(qrand() % 60));
	ui.HRNumber->setText(QString::number(qrand() % 30));

	if (ui.RRNumber->text() > ui.inputMaxRR->text() &&
		ui.labelhighRR->isHidden())
	{
		ui.labelhighRR->show();
	}
	/*else if ((ui.RRNumber->text() > ui.inputMaxRR->text() && ui.labelhighHR->isVisible()) || 
		(ui.RRNumber->text() < ui.inputMaxRR->text() &&	ui.labelhighHR->isHidden()))
	{
		
	}*/
	else if ((ui.RRNumber->text() < ui.inputMinRR->text()) || (ui.RRNumber->text() < ui.inputMaxRR->text()))
	{
		ui.labelhighRR->hide();
	}
	
	/*else
	{
		ui.labellowRR->hide();
		ui.labelhighRR->hide();
	}*/


	/*if (ui.RRNumber->text() > ui.inputMaxRR->text())
	{
		ui.labellowRR->hide();
		ui.labelhighRR->show();

		if (ui.HRNumber->text() > ui.inputMaxHR->text())
		{
			ui.labellowHR->hide();
			ui.labelhighHR->show();
		}
		else if (ui.HRNumber->text() < ui.inputMinHR->text())
		{
			ui.labelhighHR->hide();
			ui.labellowHR->show();
		}
		else
		{
			ui.labellowHR->hide();
			ui.labelhighHR->hide();
		}
	}
	else if (ui.RRNumber->text() < ui.inputMinRR->text())
	{
		ui.labelhighRR->hide();
		ui.labellowRR->show();

		if (ui.HRNumber->text() > ui.inputMaxHR->text())
		{
			ui.labellowHR->hide();
			ui.labelhighHR->show();
		}
		else if (ui.HRNumber->text() < ui.inputMinHR->text())
		{
			ui.labelhighHR->hide();
			ui.labellowHR->show();
		}
		else
		{
			ui.labellowHR->hide();
			ui.labelhighHR->hide();
		}
	}
	else
	{
		ui.labellowRR->hide();
		ui.labelhighRR->hide();
	}*/


}










