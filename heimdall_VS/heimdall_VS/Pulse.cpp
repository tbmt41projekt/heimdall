#include "Pulse.h"


using namespace std;
using namespace cv;



//__________calculate()___________________________________________________________________________

float Pulse::calculate(vector<Mat> pulseFrames)
{
	vector<Mat> greenFrames = getGreenFrames(pulseFrames);



	return 0.0f;
}

vector<Mat> Pulse::getGreenFrames(vector<Mat> pulseFrames)
{
	vector<Mat> greenFrames;
	for (Mat currentFrame : pulseFrames)
	{
		Mat splitChannels[3];
		split(currentFrame, splitChannels);

		greenFrames.push_back(splitChannels[1]);	
	}

	return greenFrames;
}

vector<float> Pulse::getMeanValues(vector<Mat> greenFrames)
{
	vector<float> meanValues;

	for (Mat currentFrame : greenFrames)
	{
		meanValues.push_back(mean(currentFrame).val[0]);
		cout << mean(currentFrame).val[0];
	}

	return meanValues;
}

/*

Tänker typ att den här funktionen ser ut på följande sett. Använder exemplen från h-filen

float Pulse::calculate(Videosekvens Vid)
{
	Videosekvens filtVid = filterVideo(Vid);
	signal newSignal = calcSignal(filtVid);
	float value = calcValue(newSignal);
	return value;
}

Skulle även kunna skrivas på följande sett:

float Pulse::calculate(Videosekvens Vid)
{
	return calcValue(calcSignal(filterVideo(Vid)));
}

*/

//________________________________________________________________________________________________