#pragma once

#include <QWidget>
#include "ui_patientHistoryWindow.h"
#include <QStringListModel>
#include <vector>
#include <string>
#include <experimental/filesystem>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Matlab.h"

struct Measurement
{
	std::string respFilename;
	std::string pulseFilename;
	std::string pnr;
	std::string date;
	std::string time;
	int index{ 0 };
};

class patientHistoryWindow : public QWidget
{
	Q_OBJECT

public:
	patientHistoryWindow(QWidget *parent = Q_NULLPTR);
	~patientHistoryWindow();
	Matlab matlab;
	void get_measurements(std::experimental::filesystem::path path);

private:
	Ui::patientHistoryWindow ui;
	QStringListModel * model;
	std::vector<Measurement> measurements;


	std::string replace(std::string str, char toReplace, char toInsert);
	bool exists(std::string pnr, std::string date, std::string time);
	void getMeasValues(std::vector<int> & values, std::vector<std::string> & timeStamps, std::ifstream & file);

private slots:
	void on_DoubleClick(QModelIndex index);


};
