#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Heimdall1.h"

class Heimdall1 : public QMainWindow
{
	Q_OBJECT

public:
	Heimdall1(QWidget *parent = Q_NULLPTR);

private:
	Ui::Heimdall1Class ui;
};
