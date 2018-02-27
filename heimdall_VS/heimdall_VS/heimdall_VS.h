#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_heimdall_VS.h"

class heimdall_VS : public QMainWindow
{
	Q_OBJECT

public:
	heimdall_VS(QWidget *parent = Q_NULLPTR);

private:
	Ui::heimdall_VSClass ui;
};
