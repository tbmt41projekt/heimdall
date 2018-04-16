#pragma once
#include "heimdallMatlab.h"
#include <vector>

class Matlab
{
public:
	Matlab();
	~Matlab();

	double filterCalc(std::vector<double> data, double lowLimit, double highLimit, double frameRate);
	bool initialized;
};

