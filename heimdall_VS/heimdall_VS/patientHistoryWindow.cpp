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
			"Tid: " + QString::fromStdString(replace(i.time, '-', ':')) + "\n";
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

	for (fs::directory_iterator iter{ path }; iter != end; ++iter)
	{
		filename = iter->path().filename().string();
		stringstream ss{filename};

		getline(ss, pnr, '_');
		getline(ss, date, '_');
		getline(ss, time, '.');

		measurements.push_back(Measurement{ filename, pnr, date, time });
	}

	for (Measurement i : measurements)
	{
		
		cout << i.pnr << " " << i.date << " " << replace(i.time, '-', ':') << endl;
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

void patientHistoryWindow::on_DoubleClick(QModelIndex index)
{
	int indexInt = index.row();

	for (Measurement & i : measurements)
	{
		if (i.index == indexInt)
		{
			cout << i.time << endl;
		}
	}

}

