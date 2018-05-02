#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <iostream>


class RoiLabel : public QLabel
{
	Q_OBJECT

public:
	RoiLabel(QWidget *parent);
	~RoiLabel();

	void mousePressEvent(QMouseEvent *ev);

	int xPos{};
	int yPos{};
	bool newPoint{false};

signals:
	void sendPoint(QPoint&);

};
