#pragma once

#include "heimdallMatlab.h"
#include<cstdlib>
#include<stdio.h>
#include <vector>


double filterCalc(std::vector<double> data, double lowLimit, double highLimit, double frameRate);
