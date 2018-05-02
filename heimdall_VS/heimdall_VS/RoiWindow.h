#pragma once

#include <QWidget>
#include "ui_RoiWindow.h"
#include "RoiLabel.h"


class RoiWindow : public QWidget
{
	Q_OBJECT

public:
	RoiWindow(QWidget *parent = Q_NULLPTR);
	~RoiWindow();
	Ui::RoiWindow ui;
	bool newPoint{ false };
	bool clearPoints{false};
	int getX();
	int getY();

private slots:
void on_SaveROIButton_clicked();
void on_ClearPointButton_clicked();
void onMousePressEvent(QPoint& point);

private:
	int x, y;
	
	
	

};
