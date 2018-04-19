#include "Engine.h"

#include <thread>
#include <iostream>

#include <opencv2\objdetect.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\videoio.hpp>
#include <opencv\cv.h>

#include <stdint.h>
#include <stdio.h>

#include <chrono>

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

	while (windowPtr->isVisible())
	{
		aPtr->processEvents();

		if (newFrameReady)
		{
			windowPtr->updateFrame(framesVector.at(0));
			newFrameReady = false;
		}
		if (newPulseReady && windowPtr->onDisplayWindow)
		{
			windowPtr->setPulse(newPulse);
			newPulseReady = false;
		}
		if (newRespReady && windowPtr->onDisplayWindow)
		{
			windowPtr->setResp(newResp);
			newRespReady = false;
		}
	}

	isProgramRunning = false;
	runCameraThread.join();
	calcPulseThread.join();
	calcRespThread.join();

	return 0;
}

//________________________________________________________________________________________________


//__________calcPulse()___________________________________________________________________________

/*
Funktionen calcPulse() f�r ett nytt v�rde p� pulsen varje g�ng som pulse.calculate() har k�rts
klart. Skickar sedan till window(?) att uppdatera det nya v�rdet.
*/

void Engine::calcPulse()
{
	int tempPulse;
	while (isProgramRunning)
	{
		auto loopStart = chrono::high_resolution_clock::now();

		while (!readyToCalc)
		{
		}

		vector<Mat> pulseFrames;

		double firstFrameTime = timeVector.front();
		int i = 0;

		while (firstFrameTime - timeVector.at(i) <= pulse.time * 1000000)		//mikrosekunder
		{
			pulseFrames.insert(pulseFrames.begin(), framesVector.at(i));
			i++;
		}

		float fps = floor(pulseFrames.size() / pulse.time);

		tempPulse = (int)pulse.calculate(pulseFrames, fps);
		if (tempPulse != -1)		//tempPulse = -1 om inga toppar har hittats
		{
			newPulse = tempPulse;
			newPulseReady = true;
		}

		chrono::time_point<chrono::steady_clock> currentTime;
		chrono::microseconds loopTime;
		do
		{
			currentTime = chrono::high_resolution_clock::now();
			loopTime = chrono::duration_cast<chrono::microseconds>(currentTime - loopStart);
		} while (loopTime.count() < pulse.time * 1000000);		//mikrosekunder
	}
}

//________________________________________________________________________________________________



//__________calcResp()____________________________________________________________________________

/*
Funktionen calcResp() f�r ett nytt v�rde p� andningen varje g�ng som resp.calculate() har k�rts
klart. Skickar sedan till window(?) att uppdatera det nya v�rdet.
*/

void Engine::calcResp()
{
	vector<double> rfVector;

	while (isProgramRunning)
	{
		resp.calculateRF(rfVector);

		if (resp.rfFound)
		{
			cout << "RF = " << rfVector.back() << endl;
			resp.rfFound = false;
		}
	}
		

}

//________________________________________________________________________________________________

//__________runCamera()___________________________________________________________________________

/*
Funktion runCamera() h�mtar frames fr�n kameran och visar dom i ett f�nster. Den sk�ter �ven
framesVector d�r frames lagras och timeVector d�r tiden d� respektive frame h�mtades lagras.
Antalet frames som lagras best�ms i Engine.h.
*/

void Engine::runCamera()
{
	while (true)
	{
		VideoCapture cap(0);
		namedWindow("Video");
		cap.set(CV_CAP_PROP_FRAME_WIDTH, 960);
		cap.set(CV_CAP_PROP_FRAME_HEIGHT, 720);

		int numOfFrames = 0;
		if (!cap.isOpened())
		{
			//cout << "Cam could not be opened" << endl;
			readyToCalc = false;
		}

		Respiration * respPtr = &resp;
		setMouseCallback("Video", respPtr->onMouse, respPtr);

		auto startTime = std::chrono::high_resolution_clock::now();
		while (true)
		{
			auto loopStart = std::chrono::high_resolution_clock::now();

			if (!cap.isOpened() || !isProgramRunning)
			{
				break;
			}

			Mat frame;
			cap >> frame;
			auto currentTime = std::chrono::high_resolution_clock::now();
			auto frameTime = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - startTime);

			if (frame.empty())
			{
				cout << "Video over" << endl;
				break;
			}

			if (numOfFrames < timeStored*maxFPS)
			{
				numOfFrames++;
				if (numOfFrames == timeStored * maxFPS)
				{
					readyToCalc = true;
				}
			}	

			//Tar bort sista framen i framesVector och l�gger till den nya framen l�ngst fram.
			framesVector.pop_back();
			framesVector.insert(framesVector.begin(), frame);
			timeVector.pop_back();
			timeVector.insert(timeVector.begin(), frameTime.count());

			newFrameReady = true;

			resp.track(frame);
			resp.addTime(frameTime.count());

			waitKey(1);
			imshow("Video", frame);

			std::chrono::microseconds loopTime;
			do
			{
				currentTime = std::chrono::high_resolution_clock::now();
				loopTime = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - loopStart);
			} while (loopTime.count() < (1 / maxFPS) * 1000000);		//mikrosekunder
		}
	}

}

//________________________________________________________________________________________________
