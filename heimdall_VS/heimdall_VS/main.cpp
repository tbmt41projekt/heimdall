#include "Engine.h"


//__________run()_________________________________________________________________________________

//K�rs ig�ng n�r programmet startas, dens uppgift �r att skapa en ny Engine-klass och kalla p�
//dess run-funktion. Den v�ntar sedan p� att en int ska returneras, detta g�rs fr�n run-funktionen.

int main(int argc, char *argv[])
{
	Engine engine{ argc, argv };
	engine.run();
	return 0;
}