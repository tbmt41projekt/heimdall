#include "Pulse.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;



//__________calculate()___________________________________________________________________________

float Pulse::calculate(vector<Mat> pulseFrames, float fps)
{
	vector<Mat> greenFrames = getGreenFrames(pulseFrames);
	vector<Mat> normFrames = normalizeFrames(greenFrames);
	Mat meanValues = getMeanValues(normFrames);
	Mat bpFilteredValues = bandpassFilter(meanValues, fps);

	//ofstream myfile1;
	//myfile1.open("example.txt");
	//for (float value : meanValues)
	//{
	//	myfile1 << value << " ";
	//}
	//myfile1.close();

	//ofstream myfile;
	//myfile.open("exampleFilt.txt");
	//for (float value : bpFilteredValues)
	//{
	//	myfile << value << " ";
	//}
	//myfile.close();

	//return getPulse(bpFilteredValues, fps);
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

vector<Mat> Pulse::normalizeFrames(vector<Mat> greenFrames)
{
	vector<Mat> normalizedFrames;
	for (Mat frame : greenFrames)
	{
		Mat normFrame;
		normalize(frame, normFrame, 0, 1, CV_MINMAX);
		normalizedFrames.push_back(normFrame);
	}
	return normalizedFrames;
}

Mat Pulse::getMeanValues(vector<Mat> greenFrames)
{
	Mat meanValues(greenFrames.size(), 1, CV_32F);
	int i = 0;
	for (Mat currentFrame : greenFrames)
	{
		//meanValues.push_back(mean(currentFrame).val[0]);
		meanValues.at<float>(i++, 0) = (float)mean(currentFrame).val[0];
	}
	return meanValues;
}


Mat Pulse::bandpassFilter(Mat realValues, float fps)
{
	vector<float> bpValuesReal;

	//dft(realArray, dftArray, DFT_ROWS | DFT_COMPLEX_OUTPUT);


	Mat originalComplex[2] = { realValues, Mat::zeros(realValues.size(), CV_32F) };

	Mat dftReady;

	merge(originalComplex, 2, dftReady);

	Mat dftOfOriginal;

	dft(dftReady, dftOfOriginal, DFT_COMPLEX_OUTPUT);

/*
	ofstream myfile1;
	myfile1.open("example6.txt");*/
	//for (int i = 0; i < dftOfOriginal.rows + 1; i++)
	//{
	//	for (int j = 0; j < dftOfOriginal.cols + 1; j++)
	//	{
	//		myfile1 << dftOfOriginal.at<float>(i, j) << " ";
	//	}
	//	myfile1 << endl;
	//}
	//myfile1.close();

	Mat p1((dftOfOriginal.rows / 2) + 1, 1, CV_32F);
	Mat p2(dftOfOriginal.rows, 1, CV_32F);

	for (int i = 0; i < p2.rows; i++)
	{
		p2.at<float>(i, 0) = sqrt(powf(dftOfOriginal.at<float>(i, 0), 2) + powf(dftOfOriginal.at<float>(i, 1), 2));
	}

	for (int i = 0; i < p1.rows; i++)
	{
		p1.at<float>(i, 0) = p2.at<float>(i, 0);
	}

	for (int i = 1; i < p1.rows - 1; i++)
	{
		p1.at<float>(i, 0) = 2 * p1.at<float>(i, 0);
	}

	Mat frequency(p1.rows, 1, CV_32F);

	for (int i = 0; i < frequency.rows; i++)
	{
		frequency.at<float>(i, 0) = i * fps / dftOfOriginal.rows;
	}

	for (int i = 0; i < p1.rows; i++)
	{
		if (frequency.at<float>(i, 0) < 0.6 || frequency.at<float>(i, 0) > 2.5)
		{
			p1.at<float>(i, 0) = 0.0f;
		}
	}

	ofstream myfile1;
	myfile1.open("p1.txt");
	for (int i = 0; i < p1.rows; i++)
	{
		myfile1 << p1.at<float>(i, 0) << " ";
		myfile1 << endl;
	}
	myfile1.close();

	ofstream myfile2;
	myfile2.open("freq.txt");
	for (int i = 0; i < frequency.rows; i++)
	{
		myfile2 << frequency.at<float>(i, 0) << " ";
		myfile2 << endl;
	}
	myfile2.close();


	//TAGIT FRAM P1 OCH FREQ, NÄSTA STEG ATT TESTA OM DET ÄR RÄTT
	//METOD: Skriv dftOfOriginal till textfil som innan och jämför


	//Filter bpFilter(BPF, realValues.rows(), fps, 0.6, 2.8);

	//for (float value : realValues)
	//{
	//	bpValuesReal.push_back((float)bpFilter.do_sample((double)value));
	//}

	//ofstream myfile1;
	//myfile1.open("example.txt");
	//for (float value : bpValuesReal)
	//{
	//	myfile1 << value << " ";
	//}
	//myfile1.close();
	return dftOfOriginal;
}




float Pulse::getPulse(vector<float> filteredValues, float fps)
{
	const int NOISE = -1;               // Level up to and including which peaks will be excluded
	int wideStart = -1;                 // The start of any current wide peak

	int grad = -1;                      // Sign of gradient (almost)
										//    =  1 for increasing
										//    =  0 for level AND PREVIOUSLY INCREASING (so potential wide peak)
										//    = -1 for decreasing OR level, but previously decreasing
										// A sharp peak is identified by grad=1 -> grad=-1
										// A wide  peak is identified by grad=0 -> grad=-1

	vector<float> peakPosVector;

	for (int i = 0; i < filteredValues.size() - 1; i++)
	{
		if (filteredValues.at(i + 1) < filteredValues.at(i))         // Only possibility of a peak
		{
			if (grad == 1 && filteredValues.at(i) > NOISE)
			{
				//cout << "Sharp peak of " << filteredValues.at(i) << " at i = " << i << '\n';
				peakPosVector.push_back((float)i);
			}
			else if (grad == 0 && filteredValues.at(i) > NOISE)
			{
				//cout << "Wide peak of " << filteredValues.at(i) << " from i = " << wideStart << " to " << i << '\n';
			}
			grad = -1;
		}
		else if (filteredValues.at(i + 1) == filteredValues.at(i))   // Check for start of a wide peak
		{
			if (grad == 1)
			{
				wideStart = i;
				grad = 0;
			}
		}
		else
		{
			grad = 1;
		}
	}
	//ofstream myfile1;
	//myfile1.open("example1.txt");
	//for (float value : peakPosVector)
	//{
	//	myfile1 << value << " ";
	//}
	//myfile1.close();

	//vector<float> peakPeriodTime;

	//if (peakPosVector.size() > 1)
	//{
	//	for (int i = peakPosVector.size() - 1; i > 0; i--)
	//	{
	//		peakPeriodTime.push_back(peakPosVector.at(i) - peakPosVector.at(i - 1));
	//	}

	//	return (fps / mean(peakPeriodTime).val[0]) * 60.0f;
	//}
	//else
	//{
	//	return -1.0f;
	//}
	return (peakPosVector.size() / (filteredValues.size() / fps)) * 60.0f;
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