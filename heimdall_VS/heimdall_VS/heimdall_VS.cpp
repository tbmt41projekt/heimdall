#include "heimdall_VS.h"

//________________________________________________________________________________________________

heimdall_VS::heimdall_VS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.inputPnr->setFocus();
	ui.inputPnr->setPlaceholderText("YYMMDD-XXXX");
	readyToMeasure = false;
	srand(time(NULL)); //SKA BORT, ENDAST FÖR TEST AV LARM
		
	//Skapar en timer så att klockan rullar
	timer1 = new QTimer(this);
	connect(timer1, SIGNAL(timeout()), this, SLOT(showTime()));
	timer1->start();
	
	//Skapar en timer för updaterandomnumber, tillfällig funktion
	timer2 = new QTimer(this);
	timer2->setInterval(2000);
	connect(timer2, SIGNAL(timeout()), this, SLOT(updateRandomNumber()));
	timer2->start();

	//Fixar bakgrundsfärg på samtliga rutor
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::white);
	ui.frame_1->setAutoFillBackground(true);
	ui.frame_1->setPalette(pal);
	ui.frame_2->setAutoFillBackground(true);
	ui.frame_2->setPalette(pal);


	//Startruta
	ui.frame_2->setVisible(false);
	ui.calendarWidget->setVisible(false);
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

//__________Destruktor____________________________________________________________________________

heimdall_VS::~heimdall_VS()
{
	//delete ui;
}

//__________setLog(QString)_______________________________________________________________________________
void heimdall_VS::setLog(QString logstr)
{
	QString contAnt;
	QFile log(pnr + "_logg.txt");

	if (log.open(QIODevice::ReadOnly))
		{
			QTextStream read(&log);
			contAnt.append(read.readAll());
			log.close();
		}
	if (log.open(QIODevice::WriteOnly))
	{
		QTextStream write(&log);
		write << contAnt;
		write << logstr;
		log.close();
	}
}


//__________alarm()_______________________________________________________________________________

void heimdall_VS::alarm()
{
	
}

//__________processFrameAndUpdateGUI()_____________________________________________________________
void heimdall_VS::processFrameAndUpdateGUI()
{
	Mat originalImage;
	capCamera.read(originalImage);

	if (originalImage.empty() == true) return;

	QImage qOriginalImage((uchar*)originalImage.data, originalImage.cols, originalImage.rows, originalImage.step, QImage::Format_RGB888);
	ui.labelVideo->setPixmap(QPixmap::fromImage(qOriginalImage));
}

//__________showTime()______________________________________________________________________________
void heimdall_VS::showTime()
{
	QDateTime date = QDateTime::currentDateTime();
	dateString = date.toString("ddMMyy hh:mm:ss");
	ui.labelDateTime->setText(dateString);
	ui.labelDateTime_2->setText(dateString);
}


//__________Start - klickfunktion_____________________________________________________________________
void heimdall_VS::on_pushStart_clicked()
{
	readyToMeasure = true;
	pnr = ui.inputPnr->text();

	QString maxHR = ui.inputMaxHR->text();
	QString minHR = ui.inputMinHR->text();
	QString maxRR = ui.inputMaxRR->text();
	QString minRR = ui.inputMinRR->text();
	QString startString = ("\n   --- New measurement: " + pnr + " --- \n");
	setLog(startString);

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
		ui.calendarWidget->setVisible(false);
		//Flytta över inputvärden till rätt plats
		ui.labelPnr_2->setText(pnr);
		ui.labelMaxHR_2->setText(maxHR);
		ui.labelMinHR_2->setText(minHR);
		ui.labelMaxRR_2->setText(maxRR);
		ui.labelMinRR_2->setText(minRR);

		//Hämtar värden från puls- och andningsklasserna
		getValues();
		ui.labelWARNING->hide();
		ui.labellowHR->hide();
		ui.labelhighHR->hide();
		ui.labellowRR->hide();
		ui.labelhighRR->hide();

		//Kör igång kameran och placerar den på frame_2
		//readyForCamera = true;

		capCamera.open(0);
		if (capCamera.isOpened() == false)
		{
			qDebug() << "Camera can't open";
			ui.labelVideo->setText("No camera connected");
			return;
		}
		QTimer *timer = new QTimer(this);
		connect(timer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
		timer->start(20);
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


//__________Logg - klickfunktion_____________________________________________________________________
void heimdall_VS::on_pushLog_clicked() 
{
	ui.calendarWidget->setVisible(true);
}

void heimdall_VS::on_pushLog_2_clicked()
{
	LogWindow logWindow(pnr, dateString);
	logWindow.setModal(true);
	logWindow.exec();
}

//___________Notis - klickfunktion____________________________________________________________
void heimdall_VS::on_pushAddNote_clicked()
{
	AddNoteWindow addNoteWindow(dateString, pnr);
	addNoteWindow.setModal(true);
	addNoteWindow.exec();
}

//_________Calendar - klickfunktion_________________________________________________________________________________
void heimdall_VS::on_calendarWidget_clicked()
{
	QString dateStringnotis = ui.calendarWidget->selectedDate().toString("ddMMyy"); 
	findSelectedDate(dateStringnotis);
	
	LogbydateWindow LogbydateWindow;
	LogbydateWindow.setModal(true);
	LogbydateWindow.exec();
	ui.calendarWidget->setVisible(false);

}


//_________findSelectedDate()_____________________________________________________________________________

void heimdall_VS::findSelectedDate(QString search)
{
	//QString search("110418");
	QFile outputFile("output.txt");
	QFile inputFile(pnr + "_logg.txt");
	bool ifDate = false;

	outputFile.open(QFile::WriteOnly|QFile::Truncate);
	QTextStream out(&outputFile);

	if (inputFile.open(QIODevice::ReadOnly))
	{
		out << "Personal ID-number: " << pnr << "  ---  Date: " << search << "\n";
		QTextStream in(&inputFile);
		while (!in.atEnd())
		{
			QString line = in.readLine();

			if (line.contains(search, Qt::CaseInsensitive)) {
				
				out << line << "\n";
			}
		}
		inputFile.close();
		outputFile.close();
	}
	
	
}

//__________SelectROI - klickfunktion________________________________________________________________
void heimdall_VS::on_pushSelectROI_clicked()
{

	capCamera.open(0);
	namedWindow("Display window", 1);

	if (capCamera.isOpened())
	{
		qDebug() << "Camera is open";
	}


	while (1)
	{
		Mat frame;
		capCamera >> frame;
		if (frame.empty()) break;
		imshow("Display window", frame);

		char c = (char)waitKey(25);
		if (c == 27) break;

	}

	


}


//__________getValues()_____________________________________________________________________
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

//__________Tillfällig funktion_____________________________________________________________
void heimdall_VS::updateRandomNumber()
{
	if (readyToMeasure == true)
	{

		qsrand((unsigned)time(0));
		//Gör om alla strings till ints för enklare jämförelse
		//Detta behöver fixas för inputs från puls- och andningsklasser
		int RRNum = qrand() % 30; //värde för andningsfrekvens
		int HRNum = qrand() % 30; //värde för hjärtfrekvens
		ui.RRNumber->setText(QString::number(RRNum));
		ui.HRNumber->setText(QString::number(HRNum));

		//--------Koden nedan ska in i larmfunktionen-----------//

			//Gör om alla strings till ints för enklare jämförelse
		QString MaxRRstring = ui.labelMaxRR_2->text();
		QString MaxHRstring = ui.labelMaxHR_2->text();
		QString MinRRstring = ui.labelMinRR_2->text();
		QString MinHRstring = ui.labelMinHR_2->text();
		int MaxRR = MaxRRstring.toInt();
		int MaxHR = MaxHRstring.toInt();
		int MinRR = MinRRstring.toInt();
		int MinHR = MinHRstring.toInt();

		//Visar larmtext om värdet går utanför intervallen - fungerar!
		QString logString;

		QString HRNumString = QString::number(HRNum);
		QString RRNumString = QString::number(RRNum);


		if (HRNum > MaxHR)
		{
			ui.labelhighHR->show();
			ui.labellowHR->hide();
			ui.labelWARNING->show();

			logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
			logString.append("  -  ");
			logString.append("High heart rate, ");
			logString.append(HRNumString);
			logString.append("\r\n");
			setLog(logString);

			if (RRNum > MaxRR)
			{
				ui.labelhighRR->show();
				ui.labellowRR->hide();

				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
				logString.append("  -  ");
				logString.append("High respiratory rate, ");
				logString.append(RRNumString);
				logString.append("\r\n");
				setLog(logString);
			}
			else if (RRNum < MinRR)
			{
				ui.labellowRR->show();
				ui.labelhighRR->hide();

				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
				logString.append("  -  ");
				logString.append("Low respiratory rate, ");
				logString.append(RRNumString);
				logString.append("\r\n");
				setLog(logString);
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
			ui.labelWARNING->show();

			logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
			logString.append("  -  ");
			logString.append("Low heart rate, ");
			logString.append(HRNumString);
			logString.append("\r\n");
			setLog(logString);

			if (RRNum > MaxRR)
			{
				ui.labelhighRR->show();
				ui.labellowRR->hide();

				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
				logString.append("  -  ");
				logString.append("High respiratory rate, ");
				logString.append(RRNumString);
				logString.append("\r\n");
				setLog(logString);
			}
			else if (RRNum < MinRR)
			{
				ui.labellowRR->show();
				ui.labelhighRR->hide();

				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
				logString.append("  -  ");
				logString.append("Low respiratory rate.");
				logString.append(RRNumString);
				logString.append("\r\n");
				setLog(logString);
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
			ui.labelWARNING->hide();

			if (RRNum > MaxRR)
			{
				ui.labelhighRR->show();
				ui.labellowRR->hide();
				ui.labelWARNING->show();

				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
				logString.append("  -  ");
				logString.append("High respiratory rate.");
				logString.append(RRNumString);
				logString.append("\r\n");
				setLog(logString);
			}
			else if (RRNum < MinRR)
			{
				ui.labellowRR->show();
				ui.labelhighRR->hide();
				ui.labelWARNING->show();

				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
				logString.append("  -  ");
				logString.append("Low respiratory rate.");
				logString.append(RRNumString);
				logString.append("\r\n");
				setLog(logString);
			}
			else
			{
				ui.labelhighRR->hide();
				ui.labellowRR->hide();
				ui.labelWARNING->hide();
			}
		}
	}
}