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
Pulse-klassen är den klass som är ansvarig för att beräkna pulsen.
Tanken är att den ska ta in en videosekvens, bearbeta den och sedan returnera ett uppdaterat
värde för pulsen.
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

