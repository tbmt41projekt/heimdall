#pragma once

#include <QWidget>
#include "ui_RoiWindow.h"


class RoiWindow : public QWidget
{
	Q_OBJECT

public:
	RoiWindow(QWidget *parent = Q_NULLPTR);
	~RoiWindow();
	Ui::RoiWindow ui;
	
	

};
