#pragma once
#include "heimdallMatlab.h"
#include <vector>

class Matlab
{
public:
	Matlab();
	~Matlab();

	double filterCalc(std::vector<double> data, double lowLimit,
		double highLimit, double frameRate);

	double findPeaks(std::vector<double> input, double lowLim,
		double highLim, double frameRate, double peakLimit, double ampLimit);

	void plot(std::vector<int> respData, std::vector<std::string> respTimeStamps,
		std::vector<int> pulseData, std::vector<std::string> pulseTimeStamps, std::string pnr);

private:
	bool initialized;
};

