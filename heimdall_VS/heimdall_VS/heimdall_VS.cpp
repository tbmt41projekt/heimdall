#include "heimdall_VS.h"
#include <iostream>
#include <QtMultimedia/QSound>
#include <QtMultimedia/QSoundEffect>

using namespace std;

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
	srand(time(NULL)); //SKA BORT, ENDAST FÖR TEST AV LARM

	//Skapar en timer så att klockan rullar
	timer1 = new QTimer(this);
	connect(timer1, SIGNAL(timeout()), this, SLOT(showTime()));
	timer1->start();

	//Skapar en timer för updaterandomnumber, tillfällig funktion
	//timer2 = new QTimer(this);
	//timer2->setInterval(2000);
	//connect(timer2, SIGNAL(timeout()), this, SLOT(updateRandomNumber()));
	//timer2->start();

	//Fixar bakgrundsfärg på samtliga rutor
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::white);
	ui.frame_1->setAutoFillBackground(true);
	ui.frame_1->setPalette(pal);
	ui.frame_2->setAutoFillBackground(true);
	ui.frame_2->setPalette(pal);
	ui.reselectROI->hide();


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
	saveRespFile.close();
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
//void heimdall_VS::alarm()
//{
//
//}

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
	dateString = date.toString("ddMMyy hh:mm:ss");
	ui.labelDateTime->setText(dateString);
	ui.labelDateTime_2->setText(dateString);
}


//__________Start - klickfunktion_____________________________________________________________________
void heimdall_VS::on_pushStart_clicked()
{
	pnr = ui.inputPnr->text();
	QDateTime time = QDateTime::currentDateTime();

	string dateString = time.toString("ddMMyy").toStdString();//"ddMMyy hh:mm:ss"
	string timeString = time.toString("hh-mm-ss").toStdString();
	cout << timeString << endl;
	saveRespFile.open("Save files/" + pnr.toStdString() + "_" + dateString + "_" + timeString + ".txt");

	if (!saveRespFile.is_open())
	{
		cout << "Save file could not be opened!" << endl;
	}

	/*saveRespFile << "----------" << time.toString("ddMMyy hh:mm:ss").toStdString()
		<< "----------" << endl;*/

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
		ui.labelNoHR->hide();
		ui.labelNoRR->hide();
		ui.reselectROI->show();

		//Kör igång kameran och placerar den på frame_2
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

	/*QSound sound("C:/Qt/Tools/QtCreator/bin/sounds/beep.wav");
	sound.play();*/
	
	/*QSound::play("beep.wav");*/

	/*QSoundEffect sound;
	sound.setSource(QUrl::fromLocalFile("beep.wav"));
	sound.setVolume(0.25f);
	sound.play();*/



	if (ui.calendarWidget->isVisible() == true)
	{
		ui.calendarWidget->setVisible(false);
		ui.pushLog->setText("Log by date");
	}
	else
	{
		ui.calendarWidget->setVisible(true);
		ui.pushLog->setText("Close calendar");
	}
}

//___________Logg - klickfunktion____________________________________________________________
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

//___________Notis - klickfunktion__________________________________________________________________
void heimdall_VS::on_pushAddNote_clicked()
{
	AddNoteWindow addNoteWindow(dateString, pnr);
	addNoteWindow.exec();
}

//___________Restart - klickfunktion_________________________________________________________________
void heimdall_VS::on_pushRestart_clicked()
{
	readyToMeasure = false; 
	ui.frame_2->hide();
	ui.frame_1->show();
}

//_________Calendar - klickfunktion__________________________________________________________________
void heimdall_VS::on_calendarWidget_clicked()
{
	ui.pushLog->setText("Log by date");
	QString dateStringnotis = ui.calendarWidget->selectedDate().toString("ddMMyy"); 
	findSelectedDate(dateStringnotis);
	
	LogbydateWindow LogbydateWindow;
	//LogbydateWindow.setModal(true);
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

void heimdall_VS::on_reselectROI_clicked()
{

	roiWindow.show();

}

void heimdall_VS::on_muteFaceAlarm_clicked()
{
	if (mutedFaceError)
	{
		ui.muteFaceAlarm->setText("Mute face alarm");
		mutedFaceError = false;
	}
	else
	{
		ui.muteFaceAlarm->setText("Enable face alarm");
		mutedFaceError = true;
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

void heimdall_VS::setPulse(int pulse)
{
	if (!mutedFaceError && pulse == -2)
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

		checkLarm("heart rate", pulse, ui.labelMinHR_2->text(), ui.labelMaxHR_2->text(), ui.labellowHR, ui.labelhighHR, ui.labelNoHR);
	}

}

void heimdall_VS::setResp(int resp)
{	
	if (resp == 0)
	{
		
	}
	QString respString = QString::number(resp);
	ui.RRNumber->setText(respString);

	checkLarm("respiratory rate", resp, ui.labelMinRR_2->text(), ui.labelMaxRR_2->text(), ui.labellowRR, ui.labelhighRR, ui.labelNoRR);

	QDateTime time = QDateTime::currentDateTime();

	saveRespFile << resp << " " << time.toString("dd-MMM-yy hh:mm:ss").toStdString() << endl;


}

void heimdall_VS::checkLarm(QString rateType, int measurement, QString & minQString, QString & maxQString, QLabel * lowLabel, QLabel * highLabel, QLabel * noRateLabel)
{
	QString logString;
	QString warning;
	int minRate = minQString.toInt();
	int maxRate = maxQString.toInt();

	if (measurement == 0)
	{
		lowLabel->hide();
		highLabel->hide();
		noRateLabel->show();
		ui.labelWARNING->show();
		warning = "No";
	}
	else if (measurement < minRate)		//Low rate warning
	{
		noRateLabel->hide();
		highLabel->hide();
		lowLabel->show();
		ui.labelWARNING->show();
		warning = "Low";
	}
	else if (measurement > maxRate)		//High rate warning
	{
		noRateLabel->hide();
		lowLabel->hide();
		highLabel->show();
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

