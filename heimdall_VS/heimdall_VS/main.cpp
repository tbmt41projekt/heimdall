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


///**************MATLAB-DEMO*****************/
//#include "matlabLibrary.h"
//
//int main(int argc, char** argv) {
//
//	mclmcrInitialize();
//	if (!mclInitializeApplication(NULL, 0)) {
//
//		std::cerr << "could not initialize the application properly"
//			<< std::endl;
//		return -1;
//	}
//	if (!matlabLibraryInitialize()) {
//		std::cerr << "could not initialize the library properly"
//			<< std::endl;
//		return -1;
//	}
//	else {
//		try {
//			double data = 2;
//			mwArray in(1, 1, mxDOUBLE_CLASS, mxREAL);
//			in.SetData(&data, 1);
//
//			mwArray out;
//			divideBy2(1, out, in);
//			std::cout << "The value is " << out << std::endl;
//
//		}
//		catch (const mwException& e) {
//			std::cerr << e.what() << std::endl;
//			return -2;
//		}
//		catch (...) {
//			std::cerr << "Unexpected error thrown" << std::endl;
//			return -3;
//		}
//		matlabLibraryTerminate();
//	}
//	mclTerminateApplication();
//	return 0;
//}