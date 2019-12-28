
#include "Line.hpp"

std::vector<Point> Line::CreateLine(Point _start, Point _end) {
	/*
	Bresenham algorithm
	*/
	std::vector<Point> lineSegment;
	Point temp = _start;
	int dx = 0, dy = 0, sx = 0, sy = 0, err = 0;
	dx = _end.Position[0] - _start.Position[0];
	dy = _end.Position[1] - _start.Position[1];
	sx = dx < 0 ? -1 : 1;
	sy = dy < 0 ? -1 : 1;
	err = dx - dy;
	while (temp.Position[0] != _end.Position[0] && 
		temp.Position[1] != _end.Position[1]) {
		int err2 = err * 2;
		if (err2 >= dy) {
			err -= dy;
			temp.Position[0] += sx;
		}
		if(err2 < dx){
			err += dx;
			temp.Position[1] += sy;
		}
		lineSegment.push_back(temp);
	}
	lineSegment.push_back(_end);
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
