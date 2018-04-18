#include "Matlab.h"

using namespace std;

Matlab::Matlab()
{
	if (!heimdallMatlabInitialize()) 
	{
		cerr << "Could not initialize the library properly" << endl;
		initialized = false;
	}
	else
	{
		initialized = true;
	}
}


Matlab::~Matlab()
{
	heimdallMatlabTerminate(); //Kanske kan tas bort om programmet blir l�ngsamt.
}

double Matlab::filterCalc(std::vector<double> signal, double lowLimit, double highLimit, double frameRate)
{
	try 
	{
		
		mwArray signalMat(1, signal.size(), mxDOUBLE_CLASS);
		signalMat.SetData(&signal[0], signal.size());

		double data[2] = {lowLimit, highLimit};
		mwArray passBand(1, 2, mxDOUBLE_CLASS);
		passBand.SetData(data, 2);

		mwArray frameRateMat(1, 1, mxDOUBLE_CLASS);
		frameRateMat.SetData(&frameRate, 1);

		mwArray frequency;

		filterAndCalcFreq(1, frequency, signalMat, passBand, frameRateMat);

		return frequency;

		
	}
	catch (const mwException& e) 
	{
		std::cerr << "MATLAB exception" << e.what() << std::endl;
		return -2;
	}
	catch (...) 
	{
		std::cerr << "Unexpected error thrown (from MATLAB)" << std::endl;
		return -3;
	}

}

double Matlab::findPeaks(std::vector<double> input, double lowLim,
	double highLim, double frameRate, double peakLimit, double ampLimit)
{
	try
	{
		mwArray inputMat(1, input.size(), mxDOUBLE_CLASS);
		inputMat.SetData(&input[0], input.size());

		double data[2] = { lowLim, highLim };
		mwArray passBand(1, 2, mxDOUBLE_CLASS);
		passBand.SetData(data, 2);

		mwArray frameRateMat(1, 1, mxDOUBLE_CLASS);
		frameRateMat.SetData(&frameRate, 1);
	
		mwArray peakLimitMat(1, 1, mxDOUBLE_CLASS);
		peakLimitMat.SetData(&peakLimit, 1);

		mwArray ampLimitMat(1, 1, mxDOUBLE_CLASS);
		ampLimitMat.SetData(&ampLimit, 1);

		mwArray output;
	
		peakFinder(1, output, inputMat, passBand, frameRateMat, peakLimitMat, ampLimitMat);

		return output;
	}
	catch (const mwException& e)
	{
		std::cerr << "MATLAB exception" << e.what() << std::endl;
		return -2;
	}
	catch (...)
	{
		std::cerr << "Unexpected error thrown (from MATLAB)" << std::endl;
		return -3;
	}
}
