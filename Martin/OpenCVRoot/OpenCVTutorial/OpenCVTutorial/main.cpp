#include <opencv2\opencv.hpp>
#include <..\..\..\..\OpenCV\include\opencv2\opencv.hpp>
#include <opencv2\objdetect.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv\cv.h>
#include <iostream>
#include <stdint.h>
#include <stdio.h>

#include "respi.h"
using namespace std;
using namespace cv;


//web-cam live
//int main()
//{
//	VideoCapture cap;
//	cap.open("baby.mp4");
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
//	return 0;
//}
//
//
//
////int main(int argv, char** argc)
////{
////	Mat testColor = imread("trump.jpg", CV_LOAD_IMAGE_COLOR);
////	Mat testGray = imread("trump.jpg", CV_LOAD_IMAGE_GRAYSCALE);
////
////
////	imshow("color", testColor);
////	imshow("gray", testGray);
////
////	imwrite("outputGray.jpg", testGray);
////
////	waitKey();
////}
//
////int main(int argv, char** argc)
////{
////	Mat file1 = imread("trump.jpg", CV_LOAD_IMAGE_UNCHANGED);
////	Mat file2 = imread("trump.jpg", CV_LOAD_IMAGE_GRAYSCALE);
////
////	namedWindow("Color", CV_WINDOW_FREERATIO);
////	namedWindow("Fixed", CV_WINDOW_AUTOSIZE);
////
////
////	imshow("Color", file1);
////	imshow("Fixed", file2);
////
////	//resizeWindow("Color", file1.cols/2, file1.rows/2);
////	//resizeWindow("Fixed", file1.cols/2, file1.rows/2);
////
////	moveWindow("Color", 500, 500);
////	moveWindow("Fixed", 500 + file2.cols + 5, 500);
////
////
////	waitKey();
////}
//
////int main(int argv, char** argc)
////{
////	Mat original = imread("trump.jpg", CV_LOAD_IMAGE_COLOR);
////	Mat modified = imread("trump.jpg", CV_LOAD_IMAGE_COLOR);
////
////	for (int r = 0; r < modified.rows; r++)
////	{
////		for (int c = 0; c < modified.cols; c++)
////		{
////			modified.at<Vec3b>(r, c)[0] = modified.at<Vec3b>(r,c)[0] * 0;
////		}
////	}
////
////	imshow("Original", original);
////	imshow("Modified", modified);
////	
////	waitKey();
////}
//
////int main(int argv, char** argc)
////{
////	Mat original = imread("trump.jpg", CV_LOAD_IMAGE_COLOR);
////
////	Mat splitChannels[3];
////
////	split(original, splitChannels);
////
////	imshow("Blue", splitChannels[0]);
////	imshow("Green", splitChannels[1]);
////	imshow("Red", splitChannels[2]);
////
////	splitChannels[2] = Mat::zeros(splitChannels[2].size(), CV_8UC1);
////
////	Mat output;
////
////	merge(splitChannels, 3, output);
////	imshow("Merged", output);
////
////	waitKey();
////}
//
//
//void takeDFT(Mat& source, Mat& destination)
//{
//	Mat originalComplex[2] = { source, Mat::zeros(source.size(), CV_32F) };
//
//	Mat dftReady;
//
//	merge(originalComplex, 2, dftReady);
//
//	Mat dftOfOriginal;
//
//	dft(dftReady, dftOfOriginal, DFT_COMPLEX_OUTPUT);
//
//	destination = dftOfOriginal;
//}
//
//void recenterDFT(Mat& source)
//{
//	int centerX = source.cols / 2;
//	int centerY = source.rows / 2;
//
//	Mat q1(source, Rect(0, 0, centerX, centerY));
//	Mat q2(source, Rect(centerX, 0, centerX, centerY));
//	Mat q3(source, Rect(0, centerY, centerX, centerY));
//	Mat q4(source, Rect(centerX, centerY, centerX, centerY));
//
//	Mat swapMat;
//
//	q1.copyTo(swapMat);
//	q4.copyTo(q1);
//	swapMat.copyTo(q4);
//
//	q2.copyTo(swapMat);
//	q3.copyTo(q2);
//	swapMat.copyTo(q3);
//}
//
//void showDFT(Mat& source)
//{
//	Mat splitArray[2] = { Mat::zeros(source.size(), CV_32F), Mat::zeros(source.size(), CV_32F) };
//
//	split(source, splitArray);
//
//	Mat dftMagnitude;
//
//	magnitude(splitArray[0], splitArray[1], dftMagnitude);
//
//	dftMagnitude += Scalar::all(1);
//
//	log(dftMagnitude, dftMagnitude);
//
//	normalize(dftMagnitude, dftMagnitude, 0, 1, CV_MINMAX);
//
//	recenterDFT(dftMagnitude);
//
//	imshow("DFT", dftMagnitude);
//
//}
//
//void invertDFT(Mat& source, Mat& destination)
//{
//	Mat inverse;
//
//	dft(source, inverse ,DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);
//
//	destination = inverse;
//}
//
////int main(int argv, char** argc)
////{
////	Mat original = imread("trump.jpg", CV_LOAD_IMAGE_GRAYSCALE);
////
////	Mat originalFloat;
////
////	original.convertTo(originalFloat, CV_32FC1, 1.0 / 255.0);
////
////	Mat dftOfOriginal;
////
////	takeDFT(originalFloat, dftOfOriginal);
////
////	showDFT(dftOfOriginal);
////
////	Mat invertedDFT;
////
////	invertDFT(dftOfOriginal, invertedDFT);
////
////	imshow("Inverterad dft", invertedDFT);
////	imshow("Original", original);
////	waitKey();
////}
//
//void createGaussian(Size& size, Mat& output, int uX, int uY, float sigmaX, float sigmaY, float amplitude = 1.0f)
//{
//	Mat temp = Mat(size, CV_32F);
//
//	for (int r = 0; r < size.height; r++)
//	{
//		for (int c = 0; c < size.width; c++)
//		{
//			float x = ((c - uX)*((float)c - uX)) / (2.0f * sigmaX * sigmaX);
//			float y = ((r - uY)*((float)r - uY)) / (2.0f * sigmaY * sigmaY);
//			float value = amplitude * exp(-(x + y));
//			temp.at<float>(r, c) = value;
//		}
//	}
//	normalize(temp, temp, 0.0f, 1.0f, NORM_MINMAX);
//	output = temp;
//}
//
////int main(int argv, char** argc)
////{
////	Mat output;
////
////	createGaussian(Size(256, 256), output, 256 / 2, 256 / 2, 10, 10);
////	imshow("Gaussian", output);
////	waitKey();
////}
//
//
////const int fps = 20;
////
////int main(int argv, char** argc)
////{
////	Mat frame;
////
////	VideoCapture vid(0);
////
////	if (!vid.isOpened())
////	{
////		return -1;
////	}
////
////	while (vid.read(frame))
////	{
////		imshow("Webcam", frame);
////
////		if (waitKey(1000/fps) >= 0)
////		{
////			break;
////		}
////	}
////	return 1;
////}
//
//
//
/** Function Headers */
void detectAndDisplay(Mat frame);

/** Global variables */
String face_cascade_name, eyes_cascade_name;
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
String window_name = "Capture - Face detection";

/** @function main */
int main(int argc, const char** argv)
{
	CommandLineParser parser(argc, argv,
		"{help h||}"
		"{face_cascade|haarcascade_frontalface_alt.xml|}"
		"{eyes_cascade|haarcascade_eye_tree_eyeglasses.xml|}");

	parser.about("\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
		"You can use Haar or LBP features.\n\n");
	parser.printMessage();

	face_cascade_name = parser.get<String>("face_cascade");
	eyes_cascade_name = parser.get<String>("eyes_cascade");
	VideoCapture capture(0);
	Mat frame;

	//-- 1. Load the cascades
	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading face cascade\n"); return -1; };
	if (!eyes_cascade.load(eyes_cascade_name)) { printf("--(!)Error loading eyes cascade\n"); return -1; };

	//-- 2. Read the video stream
	//capture.open(0);
	if (!capture.isOpened()) { printf("--(!)Error opening video capture\n"); return -1; }

	while (capture.read(frame))
	{
		if (frame.empty())
		{
			printf(" --(!) No captured frame -- Break!");
			break;
		}

		//-- 3. Apply the classifier to the frame
		detectAndDisplay(frame);

		if (waitKey(10) == 27) { break; } // escape
	}
	return 0;
}

/** @function detectAndDisplay */
void detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(60, 60));

	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

		Mat faceROI = frame_gray(faces[i]);
		std::vector<Rect> eyes;

		//-- In each face, detect eyes
		//eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

		//for (size_t j = 0; j < eyes.size(); j++)
		//{
		//	Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
		//	int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
		//	circle(frame, eye_center, radius, Scalar(255, 0, 0), 4, 8, 0); 
		//}
	}
	//-- Show what you got
	imshow(window_name, frame);
}



//
//Mat toGray(Mat &m)
//{
//
//	Mat ret;
//
//	cvtColor(m, ret, COLOR_BGR2GRAY);
//
//	return ret;
//
//}

//int main2(int argc, const char *argv[])
//{
//
//	VideoCapture cap(0); // open the default camera
//	RealTimeVideo r(100, &cap);
//	r.runThreads();
//
//	return 0;
//}

int main(int argc, const char *argv[])
{

	if (argc > 1) {

		VideoCapture cap(argv[1]); // open the default camera
		RespiVision r(1000, &cap);
		r.runThreads();
	}
	else {

		VideoCapture cap("baby.mp4");
		//VideoCapture cap(0); // open the default camera
		RespiVision r(1000, &cap);
		r.runThreads();
	}

	return 0;
}
