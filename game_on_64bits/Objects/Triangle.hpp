#pragma once
#include "Line.hpp"
#include <SDL.h>

class  Triangle
{
public:
	Line l1, l2, l3;
	void CreateTriangle(SDL_Renderer*,Point, Point, Point);
};
