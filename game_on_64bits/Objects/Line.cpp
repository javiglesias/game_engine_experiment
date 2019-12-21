
#include "Line.hpp"

std::vector<Point> Line::CreateLine(Point _start, Point _end)
{
	/*
	DDA Algorithm
	*/
	std::vector<Point> lineSegment;
	Point temp = _start;
	int dx = 0, dy = 0;
	float steps = 0.0, Xinc = 0.0, Yinc = 0.0;
	dx = _end.Position[0] - _start.Position[0];
	dy = _end.Position[1] - _start.Position[1];
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	Xinc = dx / steps;
	Yinc = dy / steps;
	while (temp.Position[0] != _end.Position[0] &&
		temp.Position[1] != _end.Position[1]) {
		lineSegment.push_back(temp);
		temp.Position[0] = round(temp.Position[0] + Xinc);
		temp.Position[1] = round(temp.Position[1] + Yinc);
	}
	lineSegment.push_back(_end);
	return lineSegment;
}
