#include "heimdall_VS.h"
#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <Qstring>


heimdall_VS::heimdall_VS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Skriver ut dagens datum och klockslag, m�ste fixas till med r�tt format
	QDateTime date = QDateTime::currentDateTime();
	QString dateString = date.toString();
	ui.labelDateTime->setText(dateString);
	ui.labelDateTime_2->setText(dateString);
	//Fixar bakgrundsf�rg p� samtliga rutor
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

	//skriv in grejer
	
	

	//Startruta
	ui.frame_2->setVisible(false);
	ui.frame_3->setVisible(false);
	ui.frame_4->setVisible(false);


	//QString pnrString = ui.inputPnr->text();
	//ui.labelHeartRate_2->setText(pnrString);

	
}


	



void heimdall_VS::alarm()
{

	
	

}
void heimdall_VS::on_pushStart_clicked()

{
	QString pnr;
	pnr = ui.inputPnr->text();

	if (pnr == "1")
	{
		ui.frame_2->setVisible(true);
		
	}
}


void heimdall_VS::on_pushSelectROI_clicked()

{

//heimdall_VS::heimdall_VS()
//{
//	delete ui;
//}

void heimdall_VS::on_pushStart_clicked()
{
	
	ui.frame_2->setVisible(true);
	ui.frame_1->setVisible(false);
	ui.labelPnr->setText("Pnr");
	


	//L�gg till kod fr�n team andning
		
	
}



}

