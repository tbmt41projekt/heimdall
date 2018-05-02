#pragma once

#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <cmath>
#include "Matlab.h"

//Respiration-klassen är den klass som är ansvarig för att beräkna andningen.
//Tanken är att den ska ta in en videosekvens, bearbeta den och sedan returnera ett uppdaterat
//värde för andningen.

class RespirationError : public std::logic_error
{
	using std::logic_error::logic_error;
};

class Respiration
{
public:
	Respiration() = default;
	~Respiration() = default;

	void onMouse(int event, int x, int y);
	static void onMouse(int event, int x, int y, int /*flags*/, void* userdata);

	void track(cv::Mat &frame);
	void calculateRF(std::vector<double> & output);
	std::vector<double> pointSummation();
	bool rfFound = false;
	void addTime(double time);
	void setAddRemovePt(bool bl);
	void setMousePoint(int x, int y);
	void clearPoints();
	
private:
	std::vector<cv::Point2f> rfBuffer;
	std::vector<double> timeBuffer;
	cv::Point2f mousePoint;
	bool addRemovePt = false;
	cv::Mat gray, prevGray, image;
	std::vector<cv::Point2f> prevPoints, nextPoints;
	cv::TermCriteria termCriteria{ cv::TermCriteria::COUNT | cv::TermCriteria::EPS, 20, 0.03 };
	cv::Size subPixWinSize{ 10, 10 }, winSize{ 31, 31 };
	Matlab matlab;
	double frameRate;


};

