#pragma once
#include <SDL.h>
//#include "../Objects/Point.hpp"
#include "../Objects/Circle.hpp"
#include "../Objects/Line.hpp"
#include <vector>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <string>
#if _WIN32
#include <windows.h>
#define SLEEP(X) Sleep(X)
#else
#include <unistd.h>
#define SLEEP(X) sleep(X)
#endif

class Camera
{
private:
	float minX, maxX;
	float minY, maxY;
	float minZ, maxZ;
	SDL_Event keyEvent;
	SDL_Renderer* mainRenderer, * oldRenderer;
	SDL_Window* mainWindow;
	Point OO;
	void RenderCircle(std::vector<Point>);
	std::vector<Point> temp;
	bool playing = true;
	void QuitNicely();
public:	
	void RenderScene(std::vector<Point>);
	void Init(int, int);
};