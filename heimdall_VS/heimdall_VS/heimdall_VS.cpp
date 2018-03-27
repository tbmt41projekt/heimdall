#include "heimdall_VS.h"


heimdall_VS::heimdall_VS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.inputPnr->setFocus();
	ui.inputPnr->setPlaceholderText("YYMMDD-XXXX");
	srand(time(NULL)); //SKA BORT, ENDAST F�R TEST AV LARM

	

	//Skapar en timer s� att klockan rullar
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
	timer->start();
	
	//Skapar en timer f�r updaterandomnumber, tillf�llig funktion
	QTimer *timer2 = new QTimer(this);
	timer2->setInterval(2000);
	connect(timer2, SIGNAL(timeout()), this, SLOT(updateRandomNumber()));
	timer2->start();

	//Fixar bakgrundsf�rg p� samtliga rutor
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::white);
	ui.frame_1->setAutoFillBackground(true);
	ui.frame_1->setPalette(pal);
	ui.frame_2->setAutoFillBackground(true);
	ui.frame_2->setPalette(pal);


	//Startruta
	ui.frame_2->setVisible(false);

	////S�tter till�tna inputv�rden f�r textrutorna

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
		//Visa n�sta frame, dvs m�trutan
		ui.frame_2->setVisible(true);
		ui.frame_1->setVisible(false);

		//Flytta �ver inputv�rden till r�tt plats
		ui.labelPnr_2->setText(pnr);
		ui.labelMaxHR_2->setText(maxHR);
		ui.labelMinHR_2->setText(minHR);
		ui.labelMaxRR_2->setText(maxRR);
		ui.labelMinRR_2->setText(minRR);

		//H�mtar v�rden fr�n puls- och andningsklasserna
		getValues();
		ui.labellowHR->hide();
		ui.labelhighHR->hide();
		ui.labellowRR->hide();
		ui.labelhighRR->hide();

		//Hur man kan visa en bild p� en label. 
		//Ej klart men n�got liknande kan g�ras med film
		/*QPixmap babypic("\\ad.liu.se\home\idabj741\bild.jpg");
	    ui.labelvideo->setPixmap(babypic);
		ui.labelvideo->show();

		bool stop = false;
		cv::VideoCapture capture("\\ad.liu.se\home\idabj741\babymovie.mp4");
		cv::Mat cur_frame;
		
		while (!stop) {
		              
			capture.read(cur_frame);
			              
			QImage img = QImage((const unsigned char*)(cur_frame.data),
				cur_frame.cols, cur_frame.rows,
				QImage::Format_RGB888);
			ui.labelvideo->setPixmap(QPixmap::fromImage(img));
			// resize the label to fit the image
			ui.labelvideo->resize(ui.labelvideo->pixmap()->size());
			
			//cv::waitkey(50);
		}
		*/
		/*cv::Mat babypic = cv::imread("\\ad.liu.se\home\linab920\Desktop\Kandidatprojekt\heimdall\babypng.png");
		cvtColor(babypic, babypic, CV_BGR2RGB);
		QImage Image(babypic.data, babypic.cols, babypic.rows, babypic.step, QImage::Format_RGB888);
		ui.labelvideo->resize(Image.size());
		ui.labelvideo->setPixmap(QPixmap::fromImage(Image));*/
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


//Funktion som h�mtar v�rden fr�n puls- och andningsklasserna
void heimdall_VS::getValues()
{
	//De tre raderna nedan funkar ej, men visa ex p� vad som borde funka
	//QFont numFont ("Arial", 5, QFont::Bold);
	//ui.HRNumber->setFont(numFont);
	//ui.RRNumber->setFont(numFont);

	/*Pulse pulse;
	QString pulseString = QString::number(pulse.calculate());
	ui.HRNumber->setText(pulseString);

	Respiration respiration;
	QString respString = QString::number(respiration.calculate());
	ui.RRNumber->setText(respString);*/

	//G�mmer varningstexten p� frame 2
	/*ui.labellowHR->hide();
	ui.labelhighHR->hide();
	ui.labellowRR->hide();
	ui.labelhighRR->hide();*/
}

void heimdall_VS::updateRandomNumber()
{
	qsrand((unsigned)time(0));
	//G�r om alla strings till ints f�r enklare j�mf�relse
	//Detta beh�ver fixas f�r inputs fr�n puls- och andningsklasser
	int RRNum = qrand() % 30; //v�rde f�r andningsfrekvens
	int HRNum = qrand() % 30; //v�rde f�r hj�rtfrekvens
	ui.RRNumber->setText(QString::number(RRNum));
	ui.HRNumber->setText(QString::number(HRNum));

//--------Koden nedan ska in i larmfunktionen-----------//

	//G�r om alla strings till ints f�r enklare j�mf�relse
	QString MaxRRstring = ui.labelMaxRR_2->text();
	QString MaxHRstring = ui.labelMaxHR_2->text();
	QString MinRRstring = ui.labelMinRR_2->text();
	QString MinHRstring = ui.labelMinHR_2->text();
	int MaxRR = MaxRRstring.toInt();
	int MaxHR = MaxHRstring.toInt();
	int MinRR = MinRRstring.toInt();
	int MinHR = MinHRstring.toInt();

	//Visar larmtext om v�rdet g�r utanf�r intervallen - fungerar!
	
	if (HRNum > MaxHR)
	{
		ui.labelhighHR->show();
		ui.labellowHR->hide();

		if (RRNum > MaxRR)
		{
			ui.labelhighRR->show();
			ui.labellowRR->hide();
		}
		else if (RRNum < MinRR)
		{
			ui.labellowRR->show();
			ui.labelhighRR->hide();
		}
		else
		{
			ui.labelhighRR->hide();
			ui.labellowRR->hide();
		}
	}
	else if (HRNum < MinHR)
	{
		ui.labellowHR->show();
		ui.labelhighHR->hide();

		if (RRNum > MaxRR)
		{
			ui.labelhighRR->show();
			ui.labellowRR->hide();
		}
		else if (RRNum < MinRR)
		{
			ui.labellowRR->show();
			ui.labelhighRR->hide();
		}
		else
		{
			ui.labelhighRR->hide();
			ui.labellowRR->hide();
		}
	}
	else 
	{
		ui.labelhighHR->hide();
		ui.labellowHR->hide();

		if (RRNum > MaxRR)
		{
			ui.labelhighRR->show();
			ui.labellowRR->hide();
		}
		else if (RRNum < MinRR)
		{
			ui.labellowRR->show();
			ui.labelhighRR->hide();
		}
		else
		{
			ui.labelhighRR->hide();
			ui.labellowRR->hide();
		}
	}
}
