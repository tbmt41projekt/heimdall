#pragma once


//Pulse-klassen �r den klass som �r ansvarig f�r att ber�kna pulsen.
//Tanken �r att den ska ta in en videosekvens, bearbeta den och sedan returnera ett uppdaterat
//v�rde f�r pulsen.

class Pulse
{
public:
	Pulse() = default;
	~Pulse() = default;

	float calculate();

private:
	/*
	H�r t�nker jag att vi skapar funktioner f�r dom olika momenten. Lite os�ker p� vad dom olika
	typerna heter men ni kanske f�rst�r vad jag menar med exemplen nedan.
	*/

	/*
	filterVideo �r en funktion som tar in en videosekvens, filtrerar den, och sedan returnerar den
	filtrerade videosekvensen.
	*/

	//Videosekvens filterVideo(Videosekvens);

	/*
	calcSignal �r en funktion som tar in en videosekvens, hittar en signal som g�r att r�kna p�,
	och sedan returnerar den signalen.
	*/

	//signal calcSignal(Videosekvens);

	/*
	calcValue �r en funktion som tar in en signal, ber�knar pulsen, och sedan
	returnerar ett v�rde som en float.
	En float �r typ som en double fast p� slutet l�gger man p� ett "f", t.ex 1.7f.
	Kan diskuteras om vi vill anv�nda double ist�llet.
	*/

	//float calcValue(signal);

	/*
	Detta �r som sagt bara lite exempel och exempel p� hur man kan g�ra det. Men tror att det
	kan va nice � dela upp alla dom olika momenten i separata funktioner.
	*/

};

