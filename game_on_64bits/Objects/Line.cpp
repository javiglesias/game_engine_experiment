
#include "Line.hpp"

std::vector<Point> Line::CreateLine(Point _start, Point _end) {
	/*
	Bresenham algorithm
	*/
	std::vector<Point> lineSegment;
	Point temp = _start;
	int dx = 0, dy = 0, sx = 0, sy = 0;
	int slope = 0, pitch = 0;
	dx = _end.Position[0] - _start.Position[0];
	dy = _end.Position[1] - _start.Position[1];
	sx = dx < 0 ? -1 : 1;
	sx = dy < 0 ? -1 : 1;
	std::cout << "draw point from line.";
	lineSegment.push_back(temp);
	if (abs(dy) < abs(dx)) {
		slope = dy / dx;
		pitch = (temp.Position[1] - slope) * temp.Position[0];
		while (temp.Position[0] != _end.Position[0]) {
			Point xTemporal;
			xTemporal.Position[0] = temp.Position[0];
			xTemporal.Position[1] = round(slope * temp.Position[0] + pitch);
			lineSegment.push_back(xTemporal);
			temp.Position[0] += sx;
		}
	}
	else {
		slope = dx / dy;
		pitch = (temp.Position[0] - slope) * temp.Position[1];
		while (temp.Position[1] != _end.Position[1]) {
			Point yTemporal;
			yTemporal.Position[0] = round(slope * temp.Position[1] + pitch);
			yTemporal.Position[1] = temp.Position[1];
			lineSegment.push_back(yTemporal);
			temp.Position[1] += sy;
		}
	}
	return lineSegment;
}
std::vector<Point> Line::CreateLineDDA(Point _start, Point _end) {
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
