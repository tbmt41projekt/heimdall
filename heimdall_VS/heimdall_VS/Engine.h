#pragma once

#include "heimdall_VS.h"
//#include "ui_heimdall_VS.h"
#include "Pulse.h"
#include "Respiration.h"
#include <vector>

#include <QtWidgets/QApplication>
#include <opencv2\opencv.hpp>


//Engine-klassen fungerar som en motor och uppgiftsuppdelare. Den s�ger till andra klassen vad
//dom ska g�ra.

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
		fps{ 10 },							//�ndra h�r om ni vill �ndra fps
		timeStored{ 10 },					//�ndra h�r om ni vill �ndra hur m�nga sekunders video som ska sparas undan
		isProgramRunning{ true },
		readyToCalc{false},
		videoQueue{ std::vector<cv::Mat>(fps * timeStored) }
	{}

	int run();

	void calcPulse();
	void calcResp();
	void runCamera();
	//QImage qimg;

private:
	QApplication * aPtr;
	heimdall_VS* windowPtr;
	Pulse pulse;
	Respiration resp;

	int fps;
	int timeStored;
	bool isProgramRunning;
	bool readyToCalc;
	std::vector<cv::Mat> videoQueue;
};

