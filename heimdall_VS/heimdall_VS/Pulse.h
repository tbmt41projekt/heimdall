#pragma once


//Pulse-klassen är den klass som är ansvarig för att beräkna pulsen.
//Tanken är att den ska ta in en videosekvens, bearbeta den och sedan returnera ett uppdaterat
//värde för pulsen.

class Pulse
{
public:
	Pulse() = default;
	~Pulse() = default;

	float calculate();

private:
	/*
	Här tänker jag att vi skapar funktioner för dom olika momenten. Lite osäker på vad dom olika
	typerna heter men ni kanske förstår vad jag menar med exemplen nedan.
	*/

	/*
	filterVideo är en funktion som tar in en videosekvens, filtrerar den, och sedan returnerar den
	filtrerade videosekvensen.
	*/

	//Videosekvens filterVideo(Videosekvens);

	/*
	calcSignal är en funktion som tar in en videosekvens, hittar en signal som går att räkna på,
	och sedan returnerar den signalen.
	*/

	//signal calcSignal(Videosekvens);

	/*
	calcValue är en funktion som tar in en signal, beräknar pulsen, och sedan
	returnerar ett värde som en float.
	En float är typ som en double fast på slutet lägger man på ett "f", t.ex 1.7f.
	Kan diskuteras om vi vill använda double istället.
	*/

	//float calcValue(signal);

	/*
	Detta är som sagt bara lite exempel och exempel på hur man kan göra det. Men tror att det
	kan va nice å dela upp alla dom olika momenten i separata funktioner.
	*/

};

