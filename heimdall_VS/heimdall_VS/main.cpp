#include "heimdall_VS.h"
#include <QtWidgets/QApplication>



using namespace std;


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	heimdall_VS w;
	w.show();


	return a.exec();
}


//Koden nedan behövs om man vill visa en videofil, tänkte att det kan va nice å spara den här tills vidare

//#include <opencv2\opencv.hpp>
//#include <opencv2\objdetect.hpp>
//#include <opencv2\highgui.hpp>
//#include <opencv2\imgproc.hpp>
//#include <opencv\cv.h>
//
//#include <iostream>
//
//#include <stdint.h>
//#include <stdio.h>
//
//using namespace cv;
//
//int main(int argc, char *argv[])
//{
//	QApplication a(argc, argv);
//	heimdall_VS w;
//	w.show();
//
//		VideoCapture cap;
//		cap.open("baby.mp4");
//		if (!cap.isOpened())
//		{
//			cout << "Cam could not be opened" << endl;
//			return -1;
//		}
//	
//		namedWindow("Video");
//		while (char(waitKey(1)) != 'q' && cap.isOpened())
//		{
//			Mat frame;
//			cap >> frame;
//	
//			if (frame.empty())
//			{
//				cout << "Video over" << endl;
//				break;
//			}
//	
//			imshow("Video", frame);
//		}
//
//	return a.exec();
//}
