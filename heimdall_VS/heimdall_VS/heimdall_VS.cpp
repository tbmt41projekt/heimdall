#include "heimdall_VS.h"
#include <iostream>

//________________________________________________________________________________________________

heimdall_VS::heimdall_VS(QWidget *parent)
	:
	QMainWindow(parent),
	onDisplayWindow{ false },
	showSelectROI{ false }
{
	ui.setupUi(this);
	ui.inputPnr->setFocus();
	ui.inputPnr->setPlaceholderText("YYMMDD-XXXX");
	srand(time(NULL)); //SKA BORT, ENDAST F�R TEST AV LARM

	//Skapar en timer s� att klockan rullar
	timer1 = new QTimer(this);
	connect(timer1, SIGNAL(timeout()), this, SLOT(showTime()));
	timer1->start();

	//Skapar en timer f�r updaterandomnumber, tillf�llig funktion
	//timer2 = new QTimer(this);
	//timer2->setInterval(2000);
	//connect(timer2, SIGNAL(timeout()), this, SLOT(updateRandomNumber()));
	//timer2->start();

	//Fixar bakgrundsf�rg p� samtliga rutor
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::white);
	ui.frame_1->setAutoFillBackground(true);
	ui.frame_1->setPalette(pal);
	ui.frame_2->setAutoFillBackground(true);
	ui.frame_2->setPalette(pal);


	//Startruta
	ui.frame_2->setVisible(false);
	ui.calendarWidget->setVisible(false);
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

//__________Destruktor____________________________________________________________________________

heimdall_VS::~heimdall_VS()
{
	//delete ui;
}

void heimdall_VS::setLog(QString logstr)
{
	QString contAnt;
	QString contAct;

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
	if (log.open(QIODevice::ReadOnly))
	{
		QTextStream read(&log);
		contAct.append(read.readAll());
		log.close();
	}
}






//__________alarm()_______________________________________________________________________________

void heimdall_VS::alarm()
{

}

//__________updateFrame()__________________________________________________________________________

void heimdall_VS::updateFrame(Mat & frame)
{
	Mat frameCopy;
	cv::cvtColor(frame, frameCopy, CV_BGR2RGB);
	QImage qOriginalImage((uchar*)frameCopy.data, frameCopy.cols, frameCopy.rows,
		frameCopy.step, QImage::Format_RGB888);

	if (onDisplayWindow)
	{
		//QPixmap pixMap{ui.labelVideo->width, ui.labelVideo->height};
		ui.labelVideo->setPixmap(QPixmap::fromImage(qOriginalImage));

		ui.labelVideo->setScaledContents(true);

		ui.labelVideo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	}
	if (roiWindow.isVisible())
	{
		roiWindow.ui.labelROIVideo->setPixmap(QPixmap::fromImage(qOriginalImage));
		roiWindow.ui.labelROIVideo->setScaledContents(true);
		roiWindow.ui.labelROIVideo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
		//imshow("Select ROI", frame);

		//HWND hwnd = (HWND)cvGetWindowHandle("Select ROI");
		//if (!IsWindowVisible(hwnd))
		//{
		//	showSelectROI = false;
		//}
	}
}

//__________showTime()______________________________________________________________________________
void heimdall_VS::showTime()
{
	QDateTime date = QDateTime::currentDateTime();
	QString dateString = date.toString("ddMMyy hh:mm:ss");
	ui.labelDateTime->setText(dateString);
	ui.labelDateTime_2->setText(dateString);
}


//__________Start - klickfunktion_____________________________________________________________________
void heimdall_VS::on_pushStart_clicked()
{
	pnr = ui.inputPnr->text();
	//QString pnr = ui.inputPnr->text();
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
		//Visa n�sta frame, dvs m�trutan
		ui.frame_2->setVisible(true);
		ui.frame_1->setVisible(false);
		ui.calendarWidget->setVisible(false);
		//Flytta �ver inputv�rden till r�tt plats
		ui.labelPnr_2->setText(pnr);
		ui.labelMaxHR_2->setText(maxHR);
		ui.labelMinHR_2->setText(minHR);
		ui.labelMaxRR_2->setText(maxRR);
		ui.labelMinRR_2->setText(minRR);

		//H�mtar v�rden fr�n puls- och andningsklasserna
		getValues();
		ui.labelWARNING->hide();
		ui.labellowHR->hide();
		ui.labelhighHR->hide();
		ui.labellowRR->hide();
		ui.labelhighRR->hide();

		//K�r ig�ng kameran och placerar den p� frame_2
		//readyForCamera = true;

		//capCamera.open(0);
		//if (capCamera.isOpened() == false)
		//{
		//	qDebug() << "Camera can't open";
		//	ui.labelVideo->setText("No camera connected");
		//	return;
		//}
		//QTimer *timer = new QTimer(this);
		//connect(timer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
		//timer->start(20);
		logWindow.pnr = pnr;
		onDisplayWindow = true;
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


	/*LogWindow logWindow;
	logWindow.setModal(true);
	logWindow.exec();
*/
}
void heimdall_VS::on_pushLog_2_clicked()
{
	//delete logWindow;
	//QDialog * temp = logWindow;
	//logWindow = new LogWindow(pnr);
	//delete temp;
	//logWindow->setModal(true);
	//QTimer *logTimer = new QTimer(this);
	//connect(logTimer, SIGNAL(timeout()), this, SLOT(updateLogWindow()));
	//logTimer->start(20);
	logWindow.start();
	logWindow.show();
}

//void heimdall_VS::updateLogWindow()
//{
//	logWindow->exec();
//}

//_________Calendar_________________________________________________________________________________
void heimdall_VS::on_calendarWidget_clicked()
{
	QString dateStringnotis = ui.calendarWidget->selectedDate().toString("ddMMyy");

	findSelectedDate(dateStringnotis);
	//qDebug() << dateStringnotis;

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
	QString semi(":");

	bool ifDate = false;

	outputFile.open(QFile::WriteOnly | QFile::Truncate);
	QTextStream out(&outputFile);

	if (inputFile.open(QIODevice::ReadOnly))
	{
		out << "Personal code number: " << pnr << "  ---  Date: " << search << "\n";
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
	//showSelectROI = true;

	//roiWindow.start();
	roiWindow.show();

	//capCamera.open(0);
	//namedWindow("Display window", 1);

	//if (capCamera.isOpened())
	//{
	//	qDebug() << "Camera is open";
	//}


	//while (1)
	//{
	//	Mat frame;
	//	capCamera >> frame;
	//	if (frame.empty()) break;
	//	imshow("Display window", frame);

	//	char c = (char)waitKey(25);
	//	if (c == 27) break;

	//}

}







//__________getValues()_____________________________________________________________________
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

void heimdall_VS::setPulse(int pulse)
{
	if (pulse == -2)
	{
		faceError.setIcon(QMessageBox::Warning);
		faceError.setWindowTitle("Error message");
		faceError.setText("Trouble detecting patient's face.");
		faceError.setInformativeText("The program is having trouble detecting the patient's face.");
		faceError.show();
		std::cout << "Hittar inget ansikte" << std::endl;
	}
	else
	{
		QString pulseString = QString::number(pulse);
		ui.HRNumber->setText(pulseString);

		checkLarm("heart rate", pulse, ui.labelMinHR_2->text(), ui.labelMaxHR_2->text(), ui.labellowHR, ui.labelhighHR);
	}

}

void heimdall_VS::setResp(int resp)
{	
	
	QString respString = QString::number(resp);
	ui.RRNumber->setText(respString);

	checkLarm("respiratory rate", resp, ui.labelMinRR_2->text(), ui.labelMaxRR_2->text(), ui.labellowRR, ui.labelhighRR);

}

void heimdall_VS::checkLarm(QString rateType, int measurement, QString & minQString, QString & maxQString, QLabel * lowLabel, QLabel * highLabel)
{
	QString logString;
	QString warning;
	int minRate = minQString.toInt();
	int maxRate = maxQString.toInt();

	if (measurement < minRate)		//Low rate warning
	{
		lowLabel->show();
		highLabel->hide();
		ui.labelWARNING->show();
		warning = "Low";
	}
	else if (measurement > maxRate)		//High rate warning
	{
		highLabel->show();
		lowLabel->hide();
		ui.labelWARNING->show();
		warning = "High";
	}
	if (!warning.isEmpty())
	{
		logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
		logString.append("  -  ");
		logString.append(warning);
		logString.append(" ");
		logString.append(rateType);
		logString.append(", ");
		logString.append(QString::number(measurement));
		logString.append("\r\n");
		setLog(logString);
	}
}

//__________Tillf�llig funktion_____________________________________________________________
//void heimdall_VS::updateRandomNumber()
//{
//	if (readyToMeasure == true)
//	{
//
//		qsrand((unsigned)time(0));
//		//G�r om alla strings till ints f�r enklare j�mf�relse
//		//Detta beh�ver fixas f�r inputs fr�n puls- och andningsklasser
//		int RRNum = qrand() % 30; //v�rde f�r andningsfrekvens
//		int HRNum = qrand() % 30; //v�rde f�r hj�rtfrekvens
//		ui.RRNumber->setText(QString::number(RRNum));
//		ui.HRNumber->setText(QString::number(HRNum));
//
//		//--------Koden nedan ska in i larmfunktionen-----------//
//
//			//G�r om alla strings till ints f�r enklare j�mf�relse
//		QString MaxRRstring = ui.labelMaxRR_2->text();
//		QString MaxHRstring = ui.labelMaxHR_2->text();
//		QString MinRRstring = ui.labelMinRR_2->text();
//		QString MinHRstring = ui.labelMinHR_2->text();
//		int MaxRR = MaxRRstring.toInt();
//		int MaxHR = MaxHRstring.toInt();
//		int MinRR = MinRRstring.toInt();
//		int MinHR = MinHRstring.toInt();
//
//		//Visar larmtext om v�rdet g�r utanf�r intervallen - fungerar!
//		QString logString;
//
//		QString HRNumString = QString::number(HRNum);
//		QString RRNumString = QString::number(RRNum);
//
//
//		if (HRNum > MaxHR)
//		{
//			ui.labelhighHR->show();
//			ui.labellowHR->hide();
//			ui.labelWARNING->show();
//
//			logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
//			logString.append("  -  ");
//			logString.append("High heart rate, ");
//			logString.append(HRNumString);
//			logString.append("\r\n");
//			setLog(logString);
//
//			if (RRNum > MaxRR)
//			{
//				ui.labelhighRR->show();
//				ui.labellowRR->hide();
//
//				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
//				logString.append("  -  ");
//				logString.append("High respiratory rate, ");
//				logString.append(RRNumString);
//				logString.append("\r\n");
//				setLog(logString);
//			}
//			else if (RRNum < MinRR)
//			{
//				ui.labellowRR->show();
//				ui.labelhighRR->hide();
//
//				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
//				logString.append("  -  ");
//				logString.append("Low respiratory rate, ");
//				logString.append(RRNumString);
//				logString.append("\r\n");
//				setLog(logString);
//			}
//			else
//			{
//				ui.labelhighRR->hide();
//				ui.labellowRR->hide();
//			}
//		}
//		else if (HRNum < MinHR)
//		{
//			ui.labellowHR->show();
//			ui.labelhighHR->hide();
//			ui.labelWARNING->show();
//
//			logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
//			logString.append("  -  ");
//			logString.append("Low heart rate, ");
//			logString.append(HRNumString);
//			logString.append("\r\n");
//			setLog(logString);
//
//			if (RRNum > MaxRR)
//			{
//				ui.labelhighRR->show();
//				ui.labellowRR->hide();
//
//				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
//				logString.append("  -  ");
//				logString.append("High respiratory rate, ");
//				logString.append(RRNumString);
//				logString.append("\r\n");
//				setLog(logString);
//			}
//			else if (RRNum < MinRR)
//			{
//				ui.labellowRR->show();
//				ui.labelhighRR->hide();
//
//				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
//				logString.append("  -  ");
//				logString.append("Low respiratory rate.");
//				logString.append(RRNumString);
//				logString.append("\r\n");
//				setLog(logString);
//			}
//			else
//			{
//				ui.labelhighRR->hide();
//				ui.labellowRR->hide();
//			}
//		}
//		else
//		{
//			ui.labelhighHR->hide();
//			ui.labellowHR->hide();
//			ui.labelWARNING->hide();
//
//			if (RRNum > MaxRR)
//			{
//				ui.labelhighRR->show();
//				ui.labellowRR->hide();
//				ui.labelWARNING->show();
//
//				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
//				logString.append("  -  ");
//				logString.append("High respiratory rate.");
//				logString.append(RRNumString);
//				logString.append("\r\n");
//				setLog(logString);
//			}
//			else if (RRNum < MinRR)
//			{
//				ui.labellowRR->show();
//				ui.labelhighRR->hide();
//				ui.labelWARNING->show();
//
//				logString.append(QDateTime::currentDateTime().toString("ddMMyy hh:mm:ss"));
//				logString.append("  -  ");
//				logString.append("Low respiratory rate.");
//				logString.append(RRNumString);
//				logString.append("\r\n");
//				setLog(logString);
//			}
//			else
//			{
//				ui.labelhighRR->hide();
//				ui.labellowRR->hide();
//				ui.labelWARNING->hide();
//			}
//		}
//	}
//}
