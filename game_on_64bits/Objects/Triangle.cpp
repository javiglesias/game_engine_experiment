#include "Triangle.hpp"

std::vector<Point> Triangle::CreateTriangle(Point p1, Point p2, Point p3)
{
	std::vector<Point> triangle, lineVector;
	Line line;
	lineVector = line.CreateLine(p1, p2);
	triangle = lineVector;
	lineVector = line.CreateLine(p1, p3);
	triangle.insert(triangle.end(), lineVector.begin(), lineVector.end());
	lineVector = line.CreateLine(p2, p3);
	triangle.insert(triangle.end(), lineVector.begin(), lineVector.end());
	std::cout << "Creating triangle: P1(" 
		<< p1.Position[0]
		<< ","
		<< p1.Position[1]
		<< "), P2("
		<< p2.Position[0]
		<< ","
		<< p2.Position[1]
		<< "), P3("
		<< p3.Position[0]
		<< ","
		<< p3.Position[1]
		<< ");"
		<< std::endl;
	return triangle;
}