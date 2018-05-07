#include "patientHistoryWindow.h"

namespace fs = std::experimental::filesystem;
using namespace std;



patientHistoryWindow::patientHistoryWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	fs::path path{ "C:/Users/nilge293/heimdall/heimdall_VS/heimdall_VS/Save files" };
	get_measurements(path);

	model = new QStringListModel(this);

	QStringList List;
	int counter{};

	for (Measurement &i : measurements)
	{
		i.index = counter;
		counter = counter + 1;
		List << "\n Patient: " + QString::fromStdString(i.pnr) + "\n"
			"Datum: " + QString::fromStdString(i.date) + "\n"
			"Starttid: " + QString::fromStdString(replace(i.time, '-', ':')) + "\n";
	}

	model->setStringList(List);

	ui.patientList->setModel(model);
	ui.patientList->setEditTriggers(QAbstractItemView::NoEditTriggers);

	connect(ui.patientList, SIGNAL(doubleClicked(QModelIndex)),
		this, SLOT(on_DoubleClick(QModelIndex)));
	
}

patientHistoryWindow::~patientHistoryWindow()
{
}

void patientHistoryWindow::get_measurements(std::experimental::filesystem::path path)
{
	const fs::directory_iterator end{};
	string filename;
	string pnr;
	string date;
	string time;
	string neutralFilename;
	string respFilename;
	string pulseFilename;

	for (fs::directory_iterator iter{ path }; iter != end; ++iter)
	{
		filename = iter->path().filename().string();
		stringstream ss{ filename };

		getline(ss, pnr, '_');
		getline(ss, date, '_');
		getline(ss, time, '_');

		neutralFilename = filename.substr(0, 27);
		respFilename = neutralFilename + "_resp.txt";
		pulseFilename = neutralFilename + "_pulse.txt";

		if (!exists(pnr, date, time))
		{
			measurements.push_back(Measurement{ respFilename, pulseFilename, pnr, date, time });
		}
		
	}
}

std::string patientHistoryWindow::replace(std::string str, char toReplace, char toInsert)
{
	string output{""};

	for (char i : str)
	{
		if (i == toReplace)
		{
			output = output + toInsert;
		}
		else
		{
			output = output + i;
		}
	}


	return output;
}

bool patientHistoryWindow::exists(std::string pnr, std::string date, std::string time)
{
	Measurement curr;
	int i{ 0 };
	while (i < measurements.size())
	{
		curr = measurements[i];

		if (curr.pnr == pnr && curr.date == date && curr.time == time)
		{
			return true;
		}
		i++;
	}
	return false;
}

void patientHistoryWindow::getMeasValues(vector<int>& values, vector<std::string>& timeStamps, std::ifstream & file)
{
	string line;
	string valueStr;
	string dateTimeStr;
	string month;

	while (getline(file, line))
	{
		cout << "hej" << endl;
		stringstream ss{ line };
		getline(ss, valueStr, ' ');
		values.push_back(stoi(valueStr));

		getline(ss, dateTimeStr);
		stringstream ss2{ dateTimeStr };
		ss2.ignore(3);
		getline(ss2, month, '-');
		if (month == "maj")
		{
			dateTimeStr = replace(dateTimeStr, 'maj', 'may');
		}

		timeStamps.push_back(dateTimeStr);
	}

}

void patientHistoryWindow::on_DoubleClick(QModelIndex index)
{
	int indexInt = index.row();

	for (Measurement & i : measurements)
	{
		if (i.index == indexInt)
		{
			ifstream respFile("Save files/" + i.respFilename);
			ifstream pulseFile("Save files/" + i.pulseFilename);
			if (!respFile.is_open())
			{
				cout << "Respiratory load file cannot be opened!" << endl;
			}
			if (!pulseFile.is_open())
			{
				cout << "Pulse load file cannot be opened!" << endl;
			}

			vector<int> respValues;
			vector<string> respTimeStamps;
			vector<int> pulseValues;
			vector<string> pulseTimeStamps;
		
			getMeasValues(respValues, respTimeStamps, respFile);
			getMeasValues(pulseValues, pulseTimeStamps, pulseFile);

			for (int i : pulseValues)
			{
				cout << i << " ";
			}
			cout << endl;

			matlab.plot(respValues, respTimeStamps, pulseValues, pulseTimeStamps, i.pnr);

			respFile.close();
			pulseFile.close();






		}
	}

}

