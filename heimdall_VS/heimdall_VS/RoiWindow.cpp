#include "RoiWindow.h"

using namespace std;

RoiWindow::RoiWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.labelROIVideo, SIGNAL(sendPoint(QPoint&)), this, SLOT(onMousePressEvent(QPoint&)));

}

RoiWindow::~RoiWindow()
{
}

int RoiWindow::getX()
{
	return x;
}

int RoiWindow::getY()
{
	return y;
}

void RoiWindow::on_ClearPointButton_clicked()
{
	clearPoints = true;
}

void RoiWindow::onMousePressEvent(QPoint& point)
{
	x = point.x();
	y = point.y();
	newPoint = true;
}

void RoiWindow::on_SaveROIButton_clicked()
{
	this->close();
}
