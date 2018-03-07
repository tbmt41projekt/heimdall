#include "heimdall_VS.h"

heimdall_VS::heimdall_VS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Skriver ut dagens datum och klockslag, måste fixas till med rätt format
	QDateTime date = QDateTime::currentDateTime();
	QString dateString = date.toString();
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


	//QString pnrString = ui.inputPnr->text();
	//ui.labelHeartRate_2->setText(pnrString);

	
}

//heimdall_VS::heimdall_VS()
//{
//	delete ui;
//}

void heimdall_VS::on_pushStart_clicked()
{
	
	ui.frame_2->setVisible(true);
	ui.frame_1->setVisible(false);
	ui.labelPnr->setText("Pnr");
	


}
