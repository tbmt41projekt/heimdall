#include "Pulse.h"


using namespace std;



//__________calculate()___________________________________________________________________________

float Pulse::calculate()
{
	return 0.0f;
}

/*

T�nker typ att den h�r funktionen ser ut p� f�ljande sett. Anv�nder exemplen fr�n h-filen

float Pulse::calculate(Videosekvens Vid)
{
	Videosekvens filtVid = filterVideo(Vid);
	signal newSignal = calcSignal(filtVid);
	float value = calcValue(newSignal);
	return value;
}

Skulle �ven kunna skrivas p� f�ljande sett:

float Pulse::calculate(Videosekvens Vid)
{
	return calcValue(calcSignal(filterVideo(Vid)));
}

*/

//________________________________________________________________________________________________