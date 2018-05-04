#pragma once

#include <QWidget>
#include "ui_patientHistoryWindow.h"
#include <QStringListModel>
#include <vector>
#include <string>
#include <experimental/filesystem>
#include <iostream>
#include <sstream>

struct Measurement
{
	std::string filename;
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

	void get_measurements(std::experimental::filesystem::path path);

private:
	Ui::patientHistoryWindow ui;
	QStringListModel * model;
	std::vector<Measurement> measurements;

	std::string replace(std::string str, char toReplace, char toInsert);

private slots:
	void on_DoubleClick(QModelIndex index);


};
