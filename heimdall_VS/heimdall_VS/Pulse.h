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
#include <fstream>

#include "filt.h"
#include "Matlab.h"

/*
Pulse-klassen �r den klass som �r ansvarig f�r att ber�kna pulsen.
Tanken �r att den ska ta in en videosekvens, bearbeta den och sedan returnera ett uppdaterat
v�rde f�r pulsen.
*/


class Pulse
{
public:
	~Pulse() = default;
	Pulse();

	float calculate(std::vector<cv::Mat> & pulseFrames, float fps);

	int time;
	float currentPulse;			//OBS!!!!!!!!!

private:
	std::vector<cv::Mat> getROI(std::vector<cv::Mat> & frames, float fps);
	std::vector<cv::Mat> getColorFrames(std::vector<cv::Mat> & pulseFrames, cv::String color);
	cv::Mat getMeanValues(std::vector<cv::Mat> & framesVector);
	cv::Mat normalizeMatrix(cv::Mat & meanValuesMatrix);
	cv::Mat getRedMinusGreen(cv::Mat & redMatrix, cv::Mat & greenMatrix);
	
	cv::CascadeClassifier face_cascade;
	Matlab matlab;
};

