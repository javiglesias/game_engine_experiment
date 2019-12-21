#include "Circle.hpp"

std::vector<Point> Circle::CreateCircle(Point center, float radius) {
	float origin = center.Position[1] + radius; //0º
	float quarter = center.Position[0] + radius;
	float half = center.Position[1] - radius;
	float thirdQuarter = center.Position[0] - radius; 
	float nPoints = 0;
	std::vector<Point> circleVector;
	while (nPoints < 360)
	{
		Point temp;
		temp.Position[0] = center.Position[0] + radius * cos(nPoints);
		temp.Position[1] = center.Position[1] + radius * sin(nPoints);
		circleVector.push_back(temp);
		nPoints += 0.1;
	}
	return circleVector;
}
