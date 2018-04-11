#include "Engine.h"

//#include "opencv2/core/core.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/opencv.hpp"
//#include "opencv2/objdetect.hpp"
//#include <opencv/cv.h>
//#include <stdint.h>
//#include <stdio.h>
//
//#include <vector>
//#include <iostream>
//
//using namespace std;
//using namespace cv;

//__________run()_________________________________________________________________________________


///** Function Headers */
//void getROI(Mat frame);
//
///** Global variables */
//String face_cascade_name, eyes_cascade_name;
//CascadeClassifier face_cascade;
//CascadeClassifier eyes_cascade;
//String window_name = "Capture - Face detection";
//String small_window = "Liten";
//
///** @function main */
//int main(int argc, const char** argv)
//{
//	CommandLineParser parser(argc, argv,
//		"{help h||}"
//		"{face_cascade|haarcascade_frontalface_alt.xml|}"
//		"{eyes_cascade|haarcascade_eye_tree_eyeglasses.xml|}");
//
//	parser.about("\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
//		"You can use Haar or LBP features.\n\n");
//	parser.printMessage();
//
//	face_cascade_name = parser.get<String>("face_cascade");
//	eyes_cascade_name = parser.get<String>("eyes_cascade");
//	VideoCapture capture(0);
//	Mat frame;
//
//	//-- 1. Load the cascades
//	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading face cascade\n"); return -1; };
//	if (!eyes_cascade.load(eyes_cascade_name)) { printf("--(!)Error loading eyes cascade\n"); return -1; };
//
//	//-- 2. Read the video stream
//	//capture.open(0);
//	if (!capture.isOpened()) { printf("--(!)Error opening video capture\n"); return -1; }
//
//	while (capture.read(frame))
//	{
//		if (frame.empty())
//		{
//			printf(" --(!) No captured frame -- Break!");
//			break;
//		}
//
//		//-- 3. Apply the classifier to the frame
//		getROI(frame);
//
//		if (waitKey(10) == 27) { break; } // escape
//	}
//	return 0;
//}
//
///** @function detectAndDisplay */
//void getROI(Mat frame)
//{
//	std::vector<Rect> faces;
//	Mat frame_gray;
//
//	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
//	equalizeHist(frame_gray, frame_gray);
//
//	//-- Detect faces
//	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(60, 60));
//
//	if (!faces.empty())
//	{
//		Mat ROI((int)(faces[0].height / 4) - (int)(faces[0].height / 20), (int)(faces[0].width / 1.3) - (int)(faces[0].width / 5.5), CV_8UC3);
//
//		int r = 0;
//
//	/*	Mat splitChannels[3];
//		split(frame, splitChannels);
//		Mat greenFrame = splitChannels[1];*/
//
//		for (int i = (int)(faces[0].y + faces[0].height / 20); i < (int)(faces[0].y + faces[0].height / 4); i++)
//		{
//			int k = 0;
//
//			for (int j = (int)(faces[0].x + faces[0].width / 5.5); j < (int)(faces[0].x + faces[0].width / 1.3); j++)
//			{
//				ROI.at<Vec3b>(r, k) = frame.at<Vec3b>(i, j);
//				//cout << ROI.type << endl;
//				//cout << greenFrame.type << endl;
//				k++;
//			}
//			r++;
//		}
//
//		//Mat ROI(150, 300, CV_8UC1);
//
//		//int r = 0;
//
//		//for (int i = 0; i < 150; i++)
//		//{
//		//	int k = 0;
//
//		//	for (int j = 0; j < 300; j++)
//		//	{
//		//		ROI.at<unsigned char>(r, k) = greenFrame.at<unsigned char>(i, j);
//		//		//cout << ROI.type << endl;
//		//		//cout << greenFrame.type << endl;
//		//		k++;
//		//	}
//		//	r++;
//		//}
//
//		//Mat faceROI = frame_gray(faces[0]);
//		//std::vector<Rect> eyes;
//
//		//-- Show what you got
//		imshow(window_name, ROI);
//
//	}
//	else
//	{
//		imshow(window_name, frame);
//	}
//
//
//}


//Körs igång när programmet startas, dens uppgift är att skapa en ny Engine-klass och kalla på
//dess run-funktion. Den väntar sedan på att en int ska returneras, detta görs från run-funktionen.
//
int main(int argc, char *argv[])
{
	Engine engine{ argc, argv };
	engine.run();
}

//________________________________________________________________________________________________



//int main(int argc, char *argv[])
//{
//	QApplication a(argc, argv);
//	heimdall_VS w;
//	w.show();
//	return a.exec();
//}


//Koden nedan behövs om man vill visa en videofil eller kamera, tänkte att det kan va nice å spara den här tills vidare
//
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
//using namespace std;
//
//int main(int argc, char *argv[])
//{
//	QApplication a(argc, argv);
//	heimdall_VS w;
//	w.show();
//
//	//Visa en video
//	VideoCapture cap;
//	cap.open("baby.mp4");
//
//	//Visa default-kameran
//	//Om det bara finns en kamera så är det lätt att visa usb-kameran
//	//Men på en laptop tex med inbyggd web-kamera så är det lurigare får då är "0" automatiskt web-kameran
//	/*VideoCapture cap(0);*/
//
//	if (!cap.isOpened())
//	{
//		cout << "Cam could not be opened" << endl;
//		return -1;
//	}
//
//	namedWindow("Video");
//	while (char(waitKey(1)) != 'q' && cap.isOpened())
//	{
//		Mat frame;
//		cap >> frame;
//
//		if (frame.empty())
//		{
//			cout << "Video over" << endl;
//			break;
//		}
//
//		imshow("Video", frame);
//	}
//
//	return a.exec();
//}

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
//#include <map>
//#include <iostream>
//
//#include "DeviceEnumerator.h"
//
//using namespace cv;
//
//int main()
//{
//
//	/*
//	The id field of the Device struct can be used with an OpenCV VideoCapture object
//	*/
//
//	DeviceEnumerator de;
//
//	// Audio Devices
//	std::map<int, Device> devices = de.getAudioDevicesMap();
//
//	// Print information about the devices
//	for (auto const &device : devices) {
//		std::cout << "== AUDIO DEVICE (id:" << device.first << ") ==" << std::endl;
//		std::cout << "Name: " << device.second.deviceName << std::endl;
//		std::cout << "Path: " << device.second.devicePath << std::endl;
//	}
//
//	// Video Devices
//	devices = de.getVideoDevicesMap();
//	int id;
//	// Print information about the devices
//	for (auto const &device : devices) {
//		std::cout << "== VIDEO DEVICE (id:" << device.first << ") ==" << std::endl;
//		std::cout << "Name: " << device.second.deviceName << std::endl;
//		std::cout << "Path: " << device.second.devicePath << std::endl;
//		string filename = device.second.devicePath;
//		id = device.first;
//	}
//
//		//Visa default-kameran
//		//Om det bara finns en kamera så är det lätt att visa usb-kameran
//		//Men på en laptop tex med inbyggd web-kamera så är det lurigare får då är "0" automatiskt web-kameran
//		VideoCapture cap(id);
//	
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
//	return 0;
//}