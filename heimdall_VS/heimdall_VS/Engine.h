#pragma once

#include "heimdall_VS.h"
#include "Pulse.h"
#include "Respiration.h"
#include <vector>

#include <QtWidgets/QApplication>
#include <opencv2\opencv.hpp>


//Engine-klassen fungerar som en motor och uppgiftsuppdelare. Den säger till andra klassen vad
//dom ska göra.

class Engine
{
public:
	~Engine();
	Engine(int argc, char *argv[])
		:
		aPtr{ new QApplication(argc,argv) },
		windowPtr{ new heimdall_VS() },
		pulse{ Pulse() },
		resp{ Respiration() },
		maxFPS{ 20.0f },							//Ändra här om ni vill ändra maxFPS
		timeStored{ 10 },					//Ändra här om ni vill ändra hur många sekunders video som ska sparas undan
		isProgramRunning{ true },
		readyToCalc{ false },
		framesVector{ std::vector<cv::Mat>(maxFPS*timeStored) },
		timeVector{ std::vector<double>(maxFPS*timeStored) }
	{}

	int run();

	void calcPulse();
	void calcResp();
	void runCamera();

private:
	QApplication * aPtr;
	heimdall_VS* windowPtr;
	Pulse pulse;
	Respiration resp;

	float maxFPS;
	int timeStored;
	bool isProgramRunning;
	bool readyToCalc;
	std::vector<cv::Mat> framesVector;
	std::vector<double> timeVector;
	//bool newFrame = false;
};

