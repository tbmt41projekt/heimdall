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

private:
	bool initialized;
};

