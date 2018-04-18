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

		ofstream myfile;
		myfile.open("andningsvarden.txt");
		for (double i : resp.pointSummation())
		{
			myfile << i << " ";
		}
		cout << "Sparning avslutad" << endl;
		return 0;
	}



	return -1;
}

//________________________________________________________________________________________________


//__________calcPulse()___________________________________________________________________________

/*
Funktionen calcPulse() får ett nytt värde på pulsen varje gång som pulse.calculate() har körts
klart. Skickar sedan till window(?) att uppdatera det nya värdet.
*/

void Engine::calcPulse()
{
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

		float test = pulse.calculate(pulseFrames, fps);

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
Funktionen calcResp() får ett nytt värde på andningen varje gång som resp.calculate() har körts
klart. Skickar sedan till window(?) att uppdatera det nya värdet.
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
Funktion runCamera() hämtar frames från kameran och visar dom i ett fönster. Den sköter även
framesVector där frames lagras och timeVector där tiden då respektive frame hämtades lagras.
Antalet frames som lagras bestäms i Engine.h.
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

			//Tar bort sista framen i framesVector och lägger till den nya framen längst fram.
			framesVector.pop_back();
			framesVector.insert(framesVector.begin(), frame);
			timeVector.pop_back();
			timeVector.insert(timeVector.begin(), frameTime.count());

			resp.track(frame);
			resp.addTime(frameTime.count());

			waitKey(1);
			imshow("Video", frame);

			//newFrame = true;
			
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
