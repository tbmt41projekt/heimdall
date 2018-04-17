#include "Respiration.h"

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


void Respiration::track(cv::Mat &frame, double dt)
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

		if (time < sampleTime)
		{
			toCalc.push_back(nextPoints[0]);
			time = dt / 1000000 - prevTime;
		}
		else
		{
			frameRate = toCalc.size() / time;
			cout << "Respiratory Frequency: " << calculateRF() << endl;
			toCalc.clear();
			prevTime = dt / 1000000;
			time = 0;
			//sampleTime = (1 / currentFrequency) * 3;
		}

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
			circle(frame,nextPoints[i], 3, Scalar(0, 255, 0), -1, 8);
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

	if (c == 'c')
	{
		prevPoints.clear();
		nextPoints.clear();
	}

	std::swap(nextPoints, prevPoints);
	cv::swap(prevGray, gray);

}

double Respiration::calculateRF()
{
	vector<double> data;
	for (Point2f i : toCalc)
	{
		data.push_back(sqrt(pow(i.x, 2) + pow(i.y, 2)));
	}
	
	for (double i : data)
	{
		cout << i << " ";
	}

	//double freq = matlab.filterCalc(data, 5, 50, frameRate);
	//currentFrequency = freq;

	return 1;
	
}



