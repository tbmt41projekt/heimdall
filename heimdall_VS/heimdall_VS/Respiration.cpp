#include "Respiration.h"


using namespace std;



//__________calculate()___________________________________________________________________________

float Respiration::calculate()
{
	return 0.0f;
}

/*

Tänker typ att den här funktionen ser ut på följande sett. Använder exemplen från h-filen

float Pulse::calculate(Videosekvens Vid)
{
Videosekvens filtVid = filterVideo(Vid);
signal newSignal = calcSignal(filtVid);
float value = calcValue(newSignal);
return value;
}

Skulle även kunna skrivas på följande sett:

float Pulse::calculate(Videosekvens Vid)
{
return calcValue(calcSignal(filterVideo(Vid)));
}

*/

//________________________________________________________________________________________________