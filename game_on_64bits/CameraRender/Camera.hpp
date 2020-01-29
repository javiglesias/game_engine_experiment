#pragma once
#include <SDL.h>
//#include "../Objects/Point.hpp"
//#include "../Objects/Circle.hpp"
//#include "../Objects/Line.hpp"
//#include "../Objects/Triangle.hpp"
#include "../Lighting/Lighting.hpp"
#include "../DungeonGame/Player.hpp"
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
	Player FirstPlayer;
	int Height, Width;
	//Circle circleObject;
	//std::vector<Point> quarter;
	//std::vector<Point> line;
	Lighting light;
	//Line lineSegment;
	SDL_Event keyEvent;
	SDL_Renderer* mainRenderer, *mapRenderer;
	SDL_Window* mainWindow;
	//Point OO;
	/*void RenderCircle(std::vector<Point>);
	std::vector<Point> Points;
	std::vector<Line> Lines;
	std::vector<Triangle> Triangles;
	std::vector<Point> temp;*/
	bool playing = true;
	bool mapGenerated = false;
	void QuitNicely();
	float Ilumination = 1.0;//At leas it has to be the color set
	void ClearRenderer();
	void GenerateMap();
public:	
	void RenderScene();
	void Init(int, int);
};