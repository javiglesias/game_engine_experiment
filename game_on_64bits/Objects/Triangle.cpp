#include "Triangle.hpp"

void Triangle::CreateTriangle(SDL_Renderer * mainRenderer, Point p1, Point p2, Point p3)
{
	//std::vector<Point> triangle, lineVector;
	//Line 1
	l1.start.Position[0] = p1.Position[0];
	l1.start.Position[1] = p1.Position[1];
	l1.end.Position[0] = p2.Position[0];
	l1.end.Position[0] = p2.Position[1];
	//Line 2
	l2.start.Position[0] = p2.Position[0];
	l2.start.Position[0] = p2.Position[1];
	l2.end.Position[0] = p3.Position[0];
	l2.end.Position[0] = p3.Position[1];
	//line 3
	l3.start.Position[0] = p3.Position[0];
	l3.start.Position[0] = p3.Position[1];
	l3.end.Position[0] = p1.Position[0];
	l3.end.Position[0] = p1.Position[1];
	/*SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderDrawLine(mainRenderer, p1.Position[0], p1.Position[1],
		p2.Position[0], p2.Position[1]);
	SDL_RenderDrawLine(mainRenderer, p2.Position[0], p2.Position[1],
		p3.Position[0], p3.Position[1]);
	SDL_RenderDrawLine(mainRenderer, p1.Position[0], p1.Position[1],
		p3.Position[0], p3.Position[1]);
	SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);*/
	return;
}