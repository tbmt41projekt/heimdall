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

//Denna funktion fungerar som main, den kör allt
//threads som skapas körs parallellt med programmet, dvs att beräkningar för t.ex. pulsen kan göras
//samtidigt som fönstret kan ta emot instruktioner (t.ex. musklickningar, inläggning av ny notis).

int Engine::run()
{
	//Visar fönstret
	windowPtr->show();

	//calcPulseThread kör igång funktionen calcPulse som hittas längre ner i filen
	thread calcPulseThread(&Engine::calcPulse, this);

	//calcRespThread kör igång funktionen calcResp som hittas längre ner i filen
	thread calcRespThread(&Engine::calcResp, this);

	//Denna if-sats är för när programmet stängs av, eftersom dom olika threadsen körs separat måste
	//man vänta på att allt körs klart innan programmet stängs av helt
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
