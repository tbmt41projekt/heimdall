#include "RoiLabel.h"

using namespace std;

RoiLabel::RoiLabel(QWidget *parent)
	: QLabel(parent)
{
	
}

RoiLabel::~RoiLabel()
{
}

void RoiLabel::mousePressEvent(QMouseEvent * ev)
{
	//xPos = ev->x();
	//yPos = ev->y();
	//newPoint = true;
	emit sendPoint(ev->pos());

}
