#include "Respiration.h"
#include <fstream>

using namespace cv;
using namespace std;



void Respiration::onMouse(int event, int x, int y)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		mousePoint = Point2f((float)x, (float)y);
		addRemovePt = true;
	}
}

void Respiration::onMouse(int event, int x, int y, int, void * userdata)
{
	if (userdata == nullptr)
	{
		cout << "Userdata i onMouse är nullptr" << endl;
	}

	Respiration * respiration = reinterpret_cast<Respiration*>(userdata);
	respiration->onMouse(event, x, y);
}


void Respiration::track(cv::Mat &frame)
{
	frame.copyTo(image);
	cvtColor(image, gray, COLOR_BGR2GRAY);

	if (!prevPoints.empty())
	{
		vector<uchar> status;
		vector<float> err;
		
		
		if (prevGray.empty())
		{
			gray.copyTo(prevGray);
		}

		calcOpticalFlowPyrLK(prevGray, gray, prevPoints, nextPoints, status, err, winSize,
			3, termCriteria, 0, 0.001);

		rfBuffer.push_back(nextPoints[0]);

		size_t i, k;
		for (i = k = 0; i < nextPoints.size(); i++)
		{
			if (addRemovePt)
			{
				if (norm(mousePoint - nextPoints[i]) <= 5)
				{
					addRemovePt = false;
					continue;
				}
			}

			if (!status[i])
				continue;

			nextPoints[k] = nextPoints[i];
			k++;
			circle(frame,nextPoints[i], 17, Scalar(0, 255, 0), -1, 8);
		}

		nextPoints.resize(k);
	}

	if (addRemovePt && nextPoints.size() < (size_t)500)
	{
		vector<Point2f> tmp;
		tmp.push_back(mousePoint);
		cornerSubPix(gray, tmp, winSize, Size(-1, -1), termCriteria);
		nextPoints.push_back(tmp[0]);
		addRemovePt = false;
	}

	char c = (char)waitKey(10);

	if (timeToClear)
	{
		prevPoints.clear();
		nextPoints.clear();
		timeToClear = false;
	}
	
	std::swap(nextPoints, prevPoints);
	cv::swap(prevGray, gray);

}

void Respiration::calculateRF(vector<double> & output)
{
	if (rfBuffer.size() > 36)
	{
		frameRate = timeBuffer.size() / ((timeBuffer.back() - timeBuffer.front()) / 1000000);

		double rf = matlab.findPeaks(pointSummation(), highLim, frameRate, 3, 0.3);
		double bandRadius = 20;
		//cout << rf << endl;

		if (rf >= 0)
		{
			output.push_back(rf);
			currentRF = rf;
			if (currentRF > 0)
			{
				//lowLim = (1 - bandRadius) * currentRF;
				highLim =  currentRF + bandRadius;
				
			}
			rfBuffer.clear();
			timeBuffer.clear();
			rfFound = true;
			counter++;
			cout << "Count = " << counter << endl;
		}
		
	}

}

std::vector<double> Respiration::pointSummation()
{
	vector<double> temp;
	for (Point2f i : rfBuffer)
	{
		temp.push_back(i.y + i.x);
	}

	return temp;
}

void Respiration::addTime(double time)
{
	timeBuffer.push_back(time);
}

void Respiration::setAddRemovePt(bool bl)
{
	addRemovePt = bl;
}


void Respiration::setMousePoint(int x, int y)
{
	Point2f point{(float)x, (float)y};
	mousePoint = point;
	addRemovePt = true;
}

void Respiration::clearPoints()
{
	for (Point2f i : prevPoints)
	{
		cout << "PrevPoints: " << i << endl;
	}
	for (Point2f i : nextPoints)
	{
		cout << "nextPoints: " << i << endl;
	}
	timeToClear = true;
}








