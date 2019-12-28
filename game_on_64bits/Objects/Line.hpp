#pragma once
#include "Point.hpp"
#include <vector>
#include <iostream>

class Line
{
public:
	std::vector<Point> CreateLine(Point, Point);
	std::vector<Point> CreateLineDDA(Point, Point);
};
 