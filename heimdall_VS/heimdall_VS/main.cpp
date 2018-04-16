#include "Engine.h"


//__________run()_________________________________________________________________________________

//Körs igång när programmet startas, dens uppgift är att skapa en ny Engine-klass och kalla på
//dess run-funktion. Den väntar sedan på att en int ska returneras, detta görs från run-funktionen.

int main(int argc, char *argv[])
{
	Engine engine{ argc, argv };
	engine.run();
	return 0;
}