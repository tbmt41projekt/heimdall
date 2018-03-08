#pragma once

#include "heimdall_VS.h"
#include "Pulse.h"
#include "Respiration.h"

#include <QtWidgets/QApplication>


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
		isProgramRunning{true}
	{}

	int run();

	void calcPulse();
	void calcResp();

private:
	QApplication* aPtr;
	heimdall_VS* windowPtr;
	Pulse pulse;
	Respiration resp;

	bool isProgramRunning;
};

