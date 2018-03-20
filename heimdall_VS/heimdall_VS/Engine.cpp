#include "Engine.h"

#include <thread>
#include <iostream>


#include <opencv2\objdetect.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv\cv.h>

#include <iostream>

#include <stdint.h>
#include <stdio.h>

using namespace cv;


using namespace std;


//__________~Engine()_____________________________________________________________________________

//Destruktor

Engine::~Engine()
{
	delete aPtr;
	delete windowPtr;
}

//________________________________________________________________________________________________



//__________run()_________________________________________________________________________________

//Denna funktion fungerar som main, den k�r allt
//threads som skapas k�rs parallellt med programmet, dvs att ber�kningar f�r t.ex. pulsen kan g�ras
//samtidigt som f�nstret kan ta emot instruktioner (t.ex. musklickningar, inl�ggning av ny notis).

int Engine::run()
{
	//Visar f�nstret
	windowPtr->show();



	//runCameraThread k�r ig�ng funktionen runCamera som hittas l�ngre ner i filen
	thread runCameraThread(&Engine::runCamera, this);

	//calcPulseThread k�r ig�ng funktionen calcPulse som hittas l�ngre ner i filen
	thread calcPulseThread(&Engine::calcPulse, this);

	//calcRespThread k�r ig�ng funktionen calcResp som hittas l�ngre ner i filen
	thread calcRespThread(&Engine::calcResp, this);

	//Denna if-sats �r f�r n�r programmet st�ngs av, eftersom dom olika threadsen k�rs separat m�ste
	//man v�nta p� att allt k�rs klart innan programmet st�ngs av helt
	if (aPtr->exec() == 0)
	{
		isProgramRunning = false;
		runCameraThread.join();
		calcPulseThread.join();
		calcRespThread.join();
		return 0;
	}
	return -1;
}

//________________________________________________________________________________________________



//__________calcPulse()___________________________________________________________________________

//Denna funktion f�r ett nytt v�rde p� pulsen varje g�ng som pulse.calculate() har k�rts klart.
//Skickar sedan till window(?) att uppdatera det nya v�rdet.

void Engine::calcPulse()
{
	while (isProgramRunning)
	{
		while (!readyToCalc)
		{
		}
		//H�r kallar vi p� pulse.calculate()
		//Den returnerar det ber�knade v�rdet p� pulsen som en float

		//vector<Mat>::const_iterator first = framesVector.begin();
		//vector<Mat>::const_iterator last = framesVector.begin() + 20; //Antalet frames som v�ljs �r 20 f�r tillf�llet
		vector<Mat> pulseFrames;

		for (int i = 0; i < (int)fps * pulse.time; i++) //fps * antalet sekunder
		{
			pulseFrames.push_back(framesVector.at(i));
		}

		float test = pulse.calculate(pulseFrames, fps);
		//cout << test << endl;
		waitKey(1000 * pulse.time); //millisekunder
	}
}

//________________________________________________________________________________________________



//__________calcResp()____________________________________________________________________________

//Denna funktion f�r ett nytt v�rde p� andningen varje g�ng som resp.calculate() har k�rts klart.
//Skickar sedan till window(?) att uppdatera det nya v�rdet.

void Engine::calcResp()
{
	while (!readyToCalc)
	{
	}

	while (isProgramRunning)
	{
		while (!readyToCalc)
		{
		}
		//H�r kallar vi p� resp.calculate()
		//Den returnerar det ber�knade v�rdet p� andningen som en float
	}
}

//________________________________________________________________________________________________



//__________runCamera()___________________________________________________________________________

//Denna funktion h�mtar frames fr�n kameran och visar dom i ett f�nster.
//Den sk�ter �ven videoQueue d�r frames lagras. Antalet frames som lagras best�ms i Engine.h.

void Engine::runCamera()
{
	while (isProgramRunning)
	{
		VideoCapture cap(0);
		namedWindow("Video");

		int i = 0;
		if (!cap.isOpened())
		{
			cout << "Cam could not be opened" << endl;
			readyToCalc = false;
		}

		
		while (cap.isOpened() && isProgramRunning && char(waitKey(1)) != 'q')
		{
			Mat frame;
			cap >> frame;

			if (frame.empty())
			{
				cout << "Video over" << endl;
				break;
			}

			if (i < timeStored*fps)
			{
				i++;
				if (i == timeStored * fps)
				{
					readyToCalc = true;
				}
			}

			//Tar bort sista framen i videoQueue och l�gger till den nya framen l�ngst fram.
			//(OBS ingen queue utan en vector)
			framesVector.pop_back();
			framesVector.insert(framesVector.begin(), frame);

			imshow("Video", frame);

			//loopen v�ntar i 1000/fps millisekunder innan den k�r vidare.
			//Dvs att vi s�ger till programmet vilken fps vi �nskar.
			waitKey(1000 / fps);
		}
	}
}

//________________________________________________________________________________________________
