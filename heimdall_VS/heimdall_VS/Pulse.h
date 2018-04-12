#pragma once
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect.hpp"
#include <opencv/cv.h>
#include <stdint.h>
#include <stdio.h>

#include <vector>
#include <iostream>

#include "filt.h"
using namespace std;
using namespace cv;


//Pulse-klassen �r den klass som �r ansvarig f�r att ber�kna pulsen.
//Tanken �r att den ska ta in en videosekvens, bearbeta den och sedan returnera ett uppdaterat
//v�rde f�r pulsen.

class Pulse
{
public:
	~Pulse() = default;
	Pulse();

	int time;

	float calculate(std::vector<cv::Mat> pulseFrames, float fps);



private:
	std::vector<cv::Mat> getColorFrames(std::vector<cv::Mat> pulseFrames, cv::String color);
	std::vector<cv::Mat> noiseReduction(std::vector<cv::Mat> greenFrames);
	cv::Mat normalizeMatrix(cv::Mat meanValuesMatrix);
	cv::Mat getMeanValues(std::vector<cv::Mat> framesVector);
	cv::Mat getRedMinusGreen(cv::Mat redMatrix, cv::Mat greenMatrix);
	cv::Mat bandpassFilter(cv::Mat realValues, float fps);
	float getPulse(cv::Mat filteredValues, float fps);
	std::vector<cv::Mat> getROI(std::vector<cv::Mat> frames, float fps);

	cv::CascadeClassifier face_cascade;

	/*
	H�r t�nker jag att vi skapar funktioner f�r dom olika momenten. Lite os�ker p� vad dom olika
	typerna heter men ni kanske f�rst�r vad jag menar med exemplen nedan.
	*/

	/*
	filterVideo �r en funktion som tar in en videosekvens, filtrerar den, och sedan returnerar den
	filtrerade videosekvensen.
	*/

	//Videosekvens filterVideo(Videosekvens);

	/*
	calcSignal �r en funktion som tar in en videosekvens, hittar en signal som g�r att r�kna p�,
	och sedan returnerar den signalen.
	*/

	//signal calcSignal(Videosekvens);

	/*
	calcValue �r en funktion som tar in en signal, ber�knar pulsen, och sedan
	returnerar ett v�rde som en float.
	En float �r typ som en double fast p� slutet l�gger man p� ett "f", t.ex 1.7f.
	Kan diskuteras om vi vill anv�nda double ist�llet.
	*/

	//float calcValue(signal);

	/*
	Detta �r som sagt bara lite exempel och exempel p� hur man kan g�ra det. Men tror att det
	kan va nice � dela upp alla dom olika momenten i separata funktioner.
	*/

};

