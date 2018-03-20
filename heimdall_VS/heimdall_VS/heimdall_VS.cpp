#include "heimdall_VS.h"




heimdall_VS::heimdall_VS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.inputPnr->setFocus();
	ui.inputPnr->setPlaceholderText("YYMMDD-XXXX");

	//Skapar en timer s� att klockan rullar
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start();


	//Fixar bakgrundsf�rg p� samtliga rutor
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::white);
	ui.frame_1->setAutoFillBackground(true);
	ui.frame_1->setPalette(pal);
	ui.frame_2->setAutoFillBackground(true);
	ui.frame_2->setPalette(pal);
	//ui.frame_3->setAutoFillBackground(true);
	//ui.frame_3->setPalette(pal);
	//ui.frame_4->setAutoFillBackground(true);
	//ui.frame_4->setPalette(pal);

	//skriv in grejer

	


	//Startruta
	ui.frame_2->setVisible(false);
	//ui.frame_3->setVisible(false);
	//ui.frame_4->setVisible(false);

	//S�tter till�tna inputv�rden f�r textrutorna

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
		ui.inputMinRR->hasAcceptableInput())
	{
		//Visa n�sta frame, dvs m�trutan
		ui.frame_2->setVisible(true);
		ui.frame_1->setVisible(false);
		
		//Flytta �ver inputv�rden till r�tt plats
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
		msgBoxError.setInformativeText("Please make sure to type in the ID-number YYMMDD-XXXX, and fill in all empty boxes.");
		msgBoxError.exec();
	}

	//G�mmer varningstexten p� frame 2
	ui.labellowHR->hide();
	ui.labellowRR->hide();
	
	{
		if (ui.labellowHR->isHidden())
		{
			
			ui.labellowHR->show();
		}
		else
		{
			ui.labellowHR->hide();
			
		}
	}
}



//L�gg till kod fr�n team andning









