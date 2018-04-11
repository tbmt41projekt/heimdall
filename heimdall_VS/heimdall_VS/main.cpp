//#include "Engine.h"
//using namespace std;

//__________run()_________________________________________________________________________________



//Körs igång när programmet startas, dens uppgift är att skapa en ny Engine-klass och kalla på
//dess run-funktion. Den väntar sedan på att en int ska returneras, detta görs från run-funktionen.

//int main(int argc, char *argv[])
//{
//	/*Engine engine{ argc, argv };
//	engine.run();*/
//
//
//	return 0;
//}

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

/**************MATLAB-DEMO*****************/
#include "matlabLibrary.h"

int main(int argc, char** argv) {

	mclmcrInitialize();
	if (!mclInitializeApplication(NULL, 0)) {

		std::cerr << "could not initialize the application properly"
			<< std::endl;
		return -1;
	}
	if (!matlabLibraryInitialize()) {
		std::cerr << "could not initialize the library properly"
			<< std::endl;
		return -1;
	}
	else {
		try {
			double data = 2;
			mwArray in(1, 1, mxDOUBLE_CLASS, mxREAL);
			in.SetData(&data, 1);

			mwArray out;
			divideBy2(1, out, in);
			std::cout << "The value is " << out << std::endl;

		}
		catch (const mwException& e) {
			std::cerr << e.what() << std::endl;
			return -2;
		}
		catch (...) {
			std::cerr << "Unexpected error thrown" << std::endl;
			return -3;
		}
		matlabLibraryTerminate();
	}
	mclTerminateApplication();
	return 0;
}