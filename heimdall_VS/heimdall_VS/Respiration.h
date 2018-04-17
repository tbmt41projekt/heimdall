#pragma once

#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <cmath>
#include "Matlab.h"

//Respiration-klassen är den klass som är ansvarig för att beräkna andningen.
//Tanken är att den ska ta in en videosekvens, bearbeta den och sedan returnera ett uppdaterat
//värde för andningen.

class Respiration
{
public:
	Respiration() = default;
	~Respiration() = default;

	void onMouse(int event, int x, int y);
	static void onMouse(int event, int x, int y, int /*flags*/, void* userdata);

	void track(cv::Mat &frame);
	void calculateRF();
	
private:
	cv::Point2f mousePoint;
	bool addRemovePt = false;
	std::vector<cv::Point2f> rfBuffer;
	int bufferSize = 20;
	cv::Mat gray, prevGray, image;
	std::vector<cv::Point2f> prevPoints, nextPoints;
	cv::TermCriteria termCriteria{ cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 20, 0.03 };
	cv::Size subPixWinSize{ 10, 10 }, winSize{ 31, 31 };
	Matlab matlab;
	double frameRate = 20;
	double currentFrequency;


};

