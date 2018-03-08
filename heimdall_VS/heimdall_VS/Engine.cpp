#include "Engine.h"

#include <thread>
#include <iostream>

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

	//calcPulseThread k�r ig�ng funktionen calcPulse som hittas l�ngre ner i filen
	thread calcPulseThread(&Engine::calcPulse, this);

	//calcRespThread k�r ig�ng funktionen calcResp som hittas l�ngre ner i filen
	thread calcRespThread(&Engine::calcResp, this);

	//Denna if-sats �r f�r n�r programmet st�ngs av, eftersom dom olika threadsen k�rs separat m�ste
	//man v�nta p� att allt k�rs klart innan programmet st�ngs av helt
	if (aPtr->exec() == 0)
	{
		isProgramRunning = false;
		calcPulseThread.join();
		calcRespThread.join();
		return 0;
	}
}

//________________________________________________________________________________________________



//__________calcPulse()___________________________________________________________________________

//Denna funktion f�r ett nytt v�rde p� pulsen varje g�ng som pulse.calculate() har k�rts klart.
//Skickar sedan till window(?) att uppdatera det nya v�rdet.

void Engine::calcPulse()
{
	while (isProgramRunning)
	{
		//H�r kallar vi p� pulse.calculate()
		//Den returnerar det ber�knade v�rdet p� pulsen som en float
	}
}

//________________________________________________________________________________________________



//__________calcResp()____________________________________________________________________________

//Denna funktion f�r ett nytt v�rde p� andningen varje g�ng som resp.calculate() har k�rts klart.
//Skickar sedan till window(?) att uppdatera det nya v�rdet.

void Engine::calcResp()
{
	while (isProgramRunning)
	{
		//H�r kallar vi p� resp.calculate()
		//Den returnerar det ber�knade v�rdet p� andningen som en float
	}
}

//________________________________________________________________________________________________
