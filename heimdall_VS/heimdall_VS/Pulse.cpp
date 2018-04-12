#include "Pulse.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

//__________Konstruktor()________________________________________________________________________

Pulse::Pulse()
	:
	time{ 5 }
{
	// Load the cascad
	if (!face_cascade.load("haarcascade_frontalface_alt.xml"))
	{
		printf("--(!)Error loading face cascade\n");
	}
}

//________________________________________________________________________________________________

//__________calculate()___________________________________________________________________________

float Pulse::calculate(vector<Mat> pulseFrames, float fps)
{
	vector<Mat> framesROI = getROI(pulseFrames, fps);
	if (!framesROI.empty())
	//if (true)
	{
		vector<Mat> greenFrames = getColorFrames(framesROI, "green");
		vector<Mat> redFrames = getColorFrames(framesROI, "red");

		//vector<Mat> greenFrames = getColorFrames(pulseFrames, "green");
		//vector<Mat> redFrames = getColorFrames(pulseFrames, "red");


		Mat greenMeanValues = getMeanValues(greenFrames);
		Mat redMeanValues = getMeanValues(redFrames);
		Mat greenNormValues = normalizeMatrix(greenMeanValues);
		Mat redNormValues = normalizeMatrix(redMeanValues);
		Mat redMinusGreen = getRedMinusGreen(redNormValues, greenNormValues);
		Mat normRMG = normalizeMatrix(redMinusGreen);


		ofstream myfile1;
		myfile1.open("normRMG16.txt");
		for (int r = 0; r < normRMG.rows; r++)
		{
			myfile1 << normRMG.at<float>(r, 0) << " ";
			myfile1 << endl;
		}
		myfile1.close();



		//Mat bpFilteredValues = bandpassFilter(meanValues, fps);
		//float value = getPulse(greenMeanValues, fps);

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
		return 90.0f;
	}
	return -1.0f;
}

vector<Mat> Pulse::getColorFrames(vector<Mat> pulseFrames, String color)
{
	int i;
	if (color == "green")
	{
		i = 1;
	}
	if (color == "red")
	{
		i = 2;
	}
	vector<Mat> colorFrames;
	for (Mat currentFrame : pulseFrames)
	{
		Mat splitChannels[3];
		split(currentFrame, splitChannels);

		colorFrames.push_back(splitChannels[i]);
	}

	return colorFrames;
}


vector<Mat> Pulse::noiseReduction(vector<Mat> greenFrames)
{
	vector<Mat> noiseRedFrames;
	int i = 0;
	for (Mat currentFrame : greenFrames)
	{
		Mat temp;
		fastNlMeansDenoising(currentFrame, temp, 30.0, 7, 21);
		noiseRedFrames.push_back(temp);
		cout << i++ << endl;
	}

	return noiseRedFrames;
}

Mat Pulse::normalizeMatrix(Mat meanValuesMatrix)
{
	Mat normValuesMatrix;
	normalize(meanValuesMatrix, normValuesMatrix, 0, 1, CV_MINMAX);

	return normValuesMatrix;
}

Mat Pulse::getMeanValues(vector<Mat> framesVector)
{
	Mat meanValues(framesVector.size(), 1, CV_32F);
	int i = 0;
	for (Mat currentFrame : framesVector)
	{
		meanValues.at<float>(i++, 0) = (float)mean(currentFrame).val[0];
	}
	return meanValues;
}

Mat Pulse::getRedMinusGreen(Mat redMatrix, Mat greenMatrix)
{
	Mat redMinusGreen(redMatrix.rows, redMatrix.cols, CV_32F);
	redMinusGreen = redMatrix - greenMatrix;

	return redMinusGreen;
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

	ofstream myfile1;
	myfile1.open("example8.txt");
	for (int i = 0; i < dftOfOriginal.rows; i++)
	{
		for (int j = 0; j < dftOfOriginal.cols; j++)
		{
			myfile1 << dftOfOriginal.at<float>(i, j) << " ";
		}
		myfile1 << endl;
	}
	myfile1.close();

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

	//Bandpass-filter typ kanske
	for (int i = 0; i < p1.rows; i++)
	{
		if (frequency.at<float>(i, 0) < 0.6 || frequency.at<float>(i, 0) > 2.5)
		{
			p1.at<float>(i, 0) = 0.0f;
		}
	}

	//ofstream myfile1;
	//myfile1.open("p1.txt");
	//for (int i = 0; i < p1.rows; i++)
	//{
	//	myfile1 << p1.at<float>(i, 0) << " ";
	//	myfile1 << endl;
	//}
	//myfile1.close();

	//ofstream myfile2;
	//myfile2.open("freq.txt");
	//for (int i = 0; i < frequency.rows; i++)
	//{
	//	myfile2 << frequency.at<float>(i, 0) << " ";
	//	myfile2 << endl;
	//}
	//myfile2.close();


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


float Pulse::getPulse(Mat filteredValues, float fps)
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

	for (int r = 0; r < filteredValues.rows - 1; r++)
	{
		if (filteredValues.at<float>(r + 1, 0) < filteredValues.at<float>(r, 0))         // Only possibility of a peak
		{
			if (grad == 1 && filteredValues.at<float>(r, 0) > NOISE)
			{
				//cout << "Sharp peak of " << filteredValues.at(i) << " at i = " << i << '\n';
				peakPosVector.push_back((float)r);
			}
			else if (grad == 0 && filteredValues.at<float>(r, 0) > NOISE)
			{
				//cout << "Wide peak of " << filteredValues.at(i) << " from i = " << wideStart << " to " << i << '\n';
			}
			grad = -1;
		}
		else if (filteredValues.at<float>(r + 1, 0) == filteredValues.at<float>(r, 0))   // Check for start of a wide peak
		{
			if (grad == 1)
			{
				wideStart = r;
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
	return (peakPosVector.size() / (filteredValues.rows / fps)) * 60.0f;
}

//________________________________________________________________________________________________


vector<Mat> Pulse::getROI(vector<Mat> frames, float fps)
{
	vector<Mat> framesROI;
	vector<Rect> faces;

	for (int i = 0; i < frames.size() / fps; i++)
	{
		int k = i * fps;
		vector<Rect> newFace;
		do
		{
			Mat grayFrame;

			cvtColor(frames.at(k), grayFrame, COLOR_BGR2GRAY);
			equalizeHist(grayFrame, grayFrame);
			//-- Detect faces
			face_cascade.detectMultiScale(grayFrame, newFace, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(60, 60));
			k++;
		} while (newFace.empty() && k < (i + 1) * fps);

		if (!newFace.empty())
		{
			faces.push_back(newFace.front());
		}

	}

	if (!faces.empty())
	{
		int facePos = 0;
		int frameNumber = 0;
		for (Mat currentFrame : frames)
		{

			Mat ROI((int)(faces.at(facePos).height / 4) - (int)(faces.at(facePos).height / 20), (int)(faces.at(facePos).width / 1.3) - (int)(faces.at(facePos).width / 5.5), CV_8UC3);

			int r = 0;

			for (int i = (int)(faces.at(facePos).y + faces.at(facePos).height / 20); i < (int)(faces.at(facePos).y + faces.at(facePos).height / 4); i++)
			{
				int k = 0;

				for (int j = (int)(faces.at(facePos).x + faces.at(facePos).width / 5.5); j < (int)(faces.at(facePos).x + faces.at(facePos).width / 1.3); j++)
				{
					ROI.at<Vec3b>(r, k) = currentFrame.at<Vec3b>(i, j);
					k++;
				}
				r++;
			}

			framesROI.push_back(ROI);

			frameNumber++;
			if (frameNumber == (facePos + 1) * fps && facePos < faces.size() - 1)
			{
				facePos++;
			}
		}

	}
	return framesROI;
}