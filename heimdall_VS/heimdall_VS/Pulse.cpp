#include "Pulse.h"

using namespace std;
using namespace cv;

//__________Pulse()_______________________________________________________________________________

Pulse::Pulse()
	:
	time{ 3 },
	currentPulse{80.0f}		//OBS!!!!!!! Denna ska s�ttas manuellt n�r programmet startas
{
	//Inl�sning av mallen f�r ansiktsigenk�nning
	String filepath = "C:/Users/nilge293/Documents/haarcascade_frontalface_alt.xml";
	if (!face_cascade.load(filepath))
	{
		printf("--(!)Error loading face cascade\n");
	}
}

//================================================================================================

//__________calculate()___________________________________________________________________________

/*
Funktionen calculate() anv�nds f�r att k�ra hela processen f�r att ber�kna pulsen. Den f�r in 
en sekvens med bilder som sedan bearbetas av olika funktioner. Returv�rdet �r pulsen.
*/

float Pulse::calculate(vector<Mat> & pulseFrames, float fps)
{
	vector<Mat> framesROI = getROI(pulseFrames, fps);
	if (!framesROI.empty())
	{
		vector<Mat> greenFrames = getColorFrames(framesROI, "green");
		vector<Mat> redFrames = getColorFrames(framesROI, "red");
		Mat greenMeanValues = getMeanValues(greenFrames);
		Mat redMeanValues = getMeanValues(redFrames);
		Mat greenNormValues = normalizeMatrix(greenMeanValues);
		Mat redNormValues = normalizeMatrix(redMeanValues);
		Mat redMinusGreen = getRedMinusGreen(redNormValues, greenNormValues);
		Mat normRMG = normalizeMatrix(redMinusGreen);

		vector<double> signal;

		for (int r = 0; r < normRMG.rows; r++)
		{
			signal.push_back((double)normRMG.at<float>(r, 0));
		}

		float expectedPulse = currentPulse;
		//currentPulse = (float)(matlab.filterCalc(signal, (double)(expectedPulse - 20.0f), (double)(expectedPulse + 10.0f), (double)(fps)));
		//cout << currentPulse << endl;

		////Kod f�r att skriva ut de normaliserade v�rden f�r R�d-Gr�n kanal, Beh�vs ej sen
		//ofstream myfile1;
		//myfile1.open("normRMG23.txt");
		//for (int r = 0; r < normRMG.rows; r++)
		//{
		//	myfile1 << normRMG.at<float>(r, 0) << " ";
		//	myfile1 << endl;
		//}
		//myfile1.close();
		//cout << "*************************KLART**********************" << endl;
		////===============================================================

		return currentPulse;
	}
	return -1.0f;		//returnerar -1 ifall det inte g�r att hitta n�got ansikte
}

//================================================================================================

//__________getROI()_____________________________________________________________________________

/*
Funktionen getROI() anv�nder ansiktsigenk�nning f�r att hitta ett omr�de i pannan p� objektet.
F�r varje frame tas ett s�dant omr�de ut. Returv�rdet blir en vektor med frames d�r enbart pannan
finns med.
*/

vector<Mat> Pulse::getROI(vector<Mat> & frames, float fps)
{
	vector<Mat> framesROI;
	vector<Rect> faces;

	/*
	For-loop f�r att hitta ett objektets ansikte. Eftersom detta �r en kr�vande process f�r datorn
	s� har loopen begr�nsats s� att det r�cker att hitta ett ansikte i sekunden, dvs var fps:te
	frame.
	Ex 1. Om objektet �r n�gorlunda stilla, fps = 25, antalet frames = 75. D� kommer ett ansiktes
	position att hittas p� frame nummer 0, 25, 50. Dvs loopen beh�ver bara analysera 3 frames.
	Ex 2. Om objektet r�r sig MYCKET, fps = 25, antalet frames = 75. D� kommer loopen att f�rs�ka
	hitta ett ansikte p� dom 25:e f�rsta framesen. N�r den har g�tt igenom en sekunds frames
	kommer denna breaka loopen.
	*/
	for (int i = 0; i < time; i++)
	{
		int k = i * fps;
		vector<Rect> newFace;

		do
		{
			Mat grayFrame;

			cvtColor(frames.at(k), grayFrame, COLOR_BGR2GRAY);
			equalizeHist(grayFrame, grayFrame);
			//-- Detect faces
			face_cascade.detectMultiScale(grayFrame, newFace, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(60, 60));
			k++;
		} while (newFace.empty() && k < (i + 1) * fps);

		if (!newFace.empty())
		{
			faces.push_back(newFace.front());
		}
		else
		{
			break;		//Break om inget ansikte hittats p� en sekund
		}
	}

	if (!faces.empty())		//K�rs om ett ansikte per sekund har hittats
	{
		int facePos = 0;
		int frameNumber = 0;

		/*
		For-loop f�r att skala ner framesen s� att enbart pannan p� objektet �r med.
		Ex. fps = 25, antalet frames = 75. D� kommer antalet positioner f�r ansiktet som har
		hittats vara 3. frame 0-24 anv�nder position 1, frame 25-49 anv�nder positon 2, och frame
		50-74 anv�nder position 3. (Detta f�r att minimera processoranv�ndning)
		*/
		for (Mat currentFrame : frames)
		{
			Mat ROI((int)(faces.at(facePos).height / 4) - (int)(faces.at(facePos).height / 20), (int)(faces.at(facePos).width / 1.3) - (int)(faces.at(facePos).width / 5.5), CV_8UC3);

			int r = 0;

			for (int i = (int)(faces.at(facePos).y + faces.at(facePos).height / 20); i < (int)(faces.at(facePos).y + faces.at(facePos).height / 4); i++)
			{
				int k = 0;

				for (int j = (int)(faces.at(facePos).x + faces.at(facePos).width / 5.5); j < (int)(faces.at(facePos).x + faces.at(facePos).width / 1.3); j++)
				{
					ROI.at<Vec3b>(r, k) = currentFrame.at<Vec3b>(i, j);
					k++;
				}
				r++;
			}

			framesROI.push_back(ROI);

			frameNumber++;
			if (frameNumber == (facePos + 1) * fps && facePos < faces.size() - 1)
			{
				facePos++;
			}
		}

	}
	return framesROI;
}

//================================================================================================

//__________getColorFrames()______________________________________________________________________

/*
Funktionen getColorFrames() delar upp varje frame i en bl�, r�d och gr�n kanal. Med invariabeln
color best�mmer man vilken kanal som ska returneras. Returv�rdet blir en vektor med frames d�r 
endast en f�rgkanal finns.
*/

vector<Mat> Pulse::getColorFrames(vector<Mat> & pulseFrames, String color)
{
	int i;
	if (color == "green")
	{
		i = 1;
	}
	if (color == "red")
	{
		i = 2;
	}
	vector<Mat> colorFrames;
	for (Mat currentFrame : pulseFrames)
	{
		Mat splitChannels[3];
		split(currentFrame, splitChannels);

		colorFrames.push_back(splitChannels[i]);
	}

	return colorFrames;
}

//================================================================================================

//__________getMeanValues()_______________________________________________________________________

/*
Funktionen getMeanValues() ber�knar medelv�rdet �ver alla pixlar f�r varje frame.
Returv�rdet blir en Rx1 matris, dvs en matris med bara en kolumn d�r varje rad �r medelv�rdet f�r
respektive frame.
*/

Mat Pulse::getMeanValues(vector<Mat> & framesVector)
{
	Mat meanValues(framesVector.size(), 1, CV_32F);
	int i = 0;
	for (Mat currentFrame : framesVector)
	{
		meanValues.at<float>(i++, 0) = (float)mean(currentFrame).val[0];
	}
	return meanValues;
}

//================================================================================================

//__________normalizeMatrix()_____________________________________________________________________

/*
Funktionen normalizeMatrix() normaliserar en matris s� att alla v�rden hamnar mellan 0 och 1.
D�r det minsta v�rdet i matrisen g�rs om till 0 och det st�rsta till 1. Returv�rdet blir en Rx1
matris d�r varje rad har ett v�rde mellan 0 och 1.
*/

Mat Pulse::normalizeMatrix(Mat & meanValuesMatrix)
{
	Mat normValuesMatrix;
	normalize(meanValuesMatrix, normValuesMatrix, 0, 1, CV_MINMAX);

	return normValuesMatrix;
}

//================================================================================================

//__________getRedMinusGreen()____________________________________________________________________

/*
Funktionen getRedMinusGreen() ber�knar skillnaden f�r varje rad mellan tv� matriser. Returv�rdet
blir en Rx1 matris.
*/

Mat Pulse::getRedMinusGreen(Mat & redMatrix, Mat & greenMatrix)
{
	Mat redMinusGreen(redMatrix.rows, redMatrix.cols, CV_32F);
	redMinusGreen = redMatrix - greenMatrix;

	return redMinusGreen;
}

//================================================================================================