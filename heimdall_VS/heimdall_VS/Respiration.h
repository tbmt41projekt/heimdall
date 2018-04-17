#pragma once

#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <cmath>
#include "Matlab.h"

//Respiration-klassen �r den klass som �r ansvarig f�r att ber�kna andningen.
//Tanken �r att den ska ta in en videosekvens, bearbeta den och sedan returnera ett uppdaterat
//v�rde f�r andningen.

class Respiration
{
public:
	Respiration() = default;
	~Respiration() = default;

	void onMouse(int event, int x, int y);
	static void onMouse(int event, int x, int y, int /*flags*/, void* userdata);

	void track(cv::Mat &frame, double dt);
	double calculateRF();
	
private:
	cv::Point2f mousePoint;
	bool addRemovePt = false;
	std::vector<cv::Point2f> toCalc;
	cv::Mat gray, prevGray, image;
	std::vector<cv::Point2f> prevPoints, nextPoints;
	cv::TermCriteria termCriteria{ cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 20, 0.03 };
	cv::Size subPixWinSize{ 10, 10 }, winSize{ 31, 31 };
	double time;
	double prevTime;
	double sampleTime = 5;
	double frameRate;
	double currentFrequency;
	Matlab matlab;

};

