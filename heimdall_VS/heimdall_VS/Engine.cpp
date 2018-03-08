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

//Denna funktion fungerar som main, den kör allt
//threads som skapas körs parallellt med programmet, dvs att beräkningar för t.ex. pulsen kan göras
//samtidigt som fönstret kan ta emot instruktioner (t.ex. musklickningar, inläggning av ny notis).

int Engine::run()
{
	//Visar fönstret
	windowPtr->show();



	//runCameraThread kör igång funktionen runCamera som hittas längre ner i filen
	thread runCameraThread(&Engine::runCamera, this);

	//calcPulseThread kör igång funktionen calcPulse som hittas längre ner i filen
	thread calcPulseThread(&Engine::calcPulse, this);

	//calcRespThread kör igång funktionen calcResp som hittas längre ner i filen
	thread calcRespThread(&Engine::calcResp, this);

	//Denna if-sats är för när programmet stängs av, eftersom dom olika threadsen körs separat måste
	//man vänta på att allt körs klart innan programmet stängs av helt
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

//Denna funktion får ett nytt värde på pulsen varje gång som pulse.calculate() har körts klart.
//Skickar sedan till window(?) att uppdatera det nya värdet.

void Engine::calcPulse()
{
	while (isProgramRunning)
	{
		//Här kallar vi på pulse.calculate()
		//Den returnerar det beräknade värdet på pulsen som en float
	}
}

//________________________________________________________________________________________________



//__________calcResp()____________________________________________________________________________

//Denna funktion får ett nytt värde på andningen varje gång som resp.calculate() har körts klart.
//Skickar sedan till window(?) att uppdatera det nya värdet.

void Engine::calcResp()
{
	while (isProgramRunning)
	{
		//Här kallar vi på resp.calculate()
		//Den returnerar det beräknade värdet på andningen som en float
	}
}

//________________________________________________________________________________________________



//__________runCamera()___________________________________________________________________________

//Denna funktion hämtar frames från kameran och visar dom i ett fönster.
//Den sköter även videoQueue där frames lagras. Antalet frames som lagras bestäms i Engine.h.

void Engine::runCamera()
{
	while (isProgramRunning)
	{
		VideoCapture cap(0);
		namedWindow("Video");

		if (!cap.isOpened())
		{
			cout << "Cam could not be opened" << endl;
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

			//Tar bort sista framen i videoQueue och lägger till den nya framen längst fram.
			//(OBS ingen queue utan en vector)
			videoQueue.pop_back();
			videoQueue.insert(videoQueue.begin(), frame);

			imshow("Video", frame);

			//loopen väntar i 1000/fps millisekunder innan den kör vidare.
			//Dvs att vi säger till programmet vilken fps vi önskar.
			waitKey(1000 / fps);
		}
	}
}

//________________________________________________________________________________________________
