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

double Matlab::findPeaks(std::vector<double> input, double cutoff,
	double frameRate, double peakLimit, double ampLimit)
{
	try
	{
		mwArray inputMat(1, input.size(), mxDOUBLE_CLASS);
		inputMat.SetData(&input[0], input.size());

		
		mwArray cutoffMat(1, 1, mxDOUBLE_CLASS);
		cutoffMat.SetData(&cutoff, 1);

		mwArray frameRateMat(1, 1, mxDOUBLE_CLASS);
		frameRateMat.SetData(&frameRate, 1);
	
		mwArray peakLimitMat(1, 1, mxDOUBLE_CLASS);
		peakLimitMat.SetData(&peakLimit, 1);

		mwArray ampLimitMat(1, 1, mxDOUBLE_CLASS);
		ampLimitMat.SetData(&ampLimit, 1);

		mwArray output;
	
		peakFinder(1, output, inputMat, cutoffMat, frameRateMat, peakLimitMat, ampLimitMat);

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

void Matlab::plot(std::vector<int> respData, std::vector<std::string> respTimeStamps,
	std::vector<int> pulseData, std::vector<std::string> pulseTimeStamps, std::string pnr)
{
	if (respData.empty())
	{
		cout << "No respiration data!" << endl;
	}
	else if (pulseData.empty())
	{
		cout << "No pulse data" << endl;
	}
	else
	{


		mwArray respDataMat(1, respData.size(), mxDOUBLE_CLASS);
		mwArray respTimeStampsMat;

		respDataMat.SetData(&respData[0], respData.size());

		std::vector<const char*> cstringsResp;
		for (size_t i = 0; i < respTimeStamps.size(); ++i)
		{
			cstringsResp.push_back(respTimeStamps[i].c_str());  //convert string to const char*
		}
		respTimeStampsMat = mwArray(cstringsResp.size(), cstringsResp.data());  //cstrings.data() is const char**


	/********************************************************/
		mwArray pulseDataMat(1, pulseData.size(), mxDOUBLE_CLASS);
		if (!pulseData.empty())
		{
			pulseDataMat.SetData(&pulseData[0], pulseData.size());
		}
		std::vector<const char*> cstringsPulse;
		for (size_t i = 0; i < pulseTimeStamps.size(); ++i)
		{
			cstringsPulse.push_back(pulseTimeStamps[i].c_str());  //convert string to const char*
		}
		mwArray pulseTimeStampsMat(cstringsPulse.size(), cstringsPulse.data());  //cstrings.data() is const char**
		/*****************************/
		const char * c = pnr.c_str();
		const mwArray pnrMat(c);

		plotValues(respDataMat, respTimeStampsMat, pulseDataMat, pulseTimeStampsMat, pnrMat);
	}
	

}
