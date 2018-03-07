#include "Engine.h"



//__________run()_________________________________________________________________________________


//Körs igång när programmet startas, dens uppgift är att skapa en ny Engine-klass och kalla på
//dess run-funktion. Den väntar sedan på att en int ska returneras, detta görs från run-funktionen.



int main(int argc, char *argv[])
{
	/* Gammalt, ska bort

	//QApplication a(argc, argv);
	//heimdall_VS w;
	//w.show();
	//return a.exec();
	
	*/

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
//
//int main(int argc, char *argv[])
//{
//	QApplication a(argc, argv);
//	heimdall_VS w;
//	w.show();
//
//	//Visa en video
//	//VideoCapture cap;
//	//cap.open("baby.mp4");
//
//	//Visa default-kameran
//	//Om det bara finns en kamera så är det lätt att visa usb-kameran
//	//Men på en laptop tex med inbyggd web-kamera så är det lurigare får då är "0" automatiskt web-kameran
//	VideoCapture cap(0);
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