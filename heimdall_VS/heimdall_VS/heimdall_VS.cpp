#include "heimdall_VS.h"

heimdall_VS::heimdall_VS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.inputPnr->setFocus();
	ui.inputPnr->setPlaceholderText("YYMMDD-XXXX");

	//Skriver ut dagens datum och klockslag, måste fixas till med rätt format
	QDateTime date = QDateTime::currentDateTime();
	QString dateString = date.toString("ddMMyy hh:mm:ss");
	ui.labelDateTime->setText(dateString);
	ui.labelDateTime_2->setText(dateString);
	//Fixar bakgrundsfärg på samtliga rutor
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::white);
	ui.frame_1->setAutoFillBackground(true);
	ui.frame_1->setPalette(pal);
	ui.frame_2->setAutoFillBackground(true);
	ui.frame_2->setPalette(pal);
	ui.frame_3->setAutoFillBackground(true);
	ui.frame_3->setPalette(pal);
	ui.frame_4->setAutoFillBackground(true);
	ui.frame_4->setPalette(pal);


	//Startruta
	ui.frame_2->setVisible(false);
	ui.frame_3->setVisible(false);
	ui.frame_4->setVisible(false);

	//Sätter tillåtna inputvärden för textrutorna
	
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

//heimdall_VS::heimdall_VS()
//{
//	delete ui;
//}

//void heimdall_VS::mousePressEvent(QMouseEvent *event)
//{ 
//	if (event->buttons() == Qt::LeftButton)
//	{
//		
//	}
//}

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
		ui.inputMinRR->hasAcceptableInput())
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
	}
	else
	{
		QMessageBox msgBoxError;
		msgBoxError.setIcon(QMessageBox::Warning);
		msgBoxError.setWindowTitle("Error message");
		msgBoxError.setText("Not valid ID-number and/or input values.");
		msgBoxError.setInformativeText("Please make sure to type the ID-number as YYMMDD-XXXX, and fill in all empty boxes.");
		msgBoxError.exec();
	}
	

	
}


