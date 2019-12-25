#include "Camera.hpp"

void Camera::Init(int Width, int Height) {
	std::vector<Point> Points;
	Circle circleObject;
	Line lineSegment;
	std::vector<Point> quarter;
	std::vector<Point> line;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
		return;
	mainWindow = SDL_CreateWindow("mysterious-hat-engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		Width, Height, SDL_WINDOW_SHOWN);
	oldRenderer = mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_TARGETTEXTURE);
	OO.Position[0] = 0;
	OO.Position[1] = 0;
	OO.Position[2] = 0; //2-D
	Points.push_back(OO);
	temp = Points;
	while (playing) {
		SDL_PollEvent(&keyEvent);
		switch (keyEvent.type)
		{
		case SDL_MOUSEBUTTONDOWN: {
			int mouseX, mouseY;
			Point T;
			SDL_GetMouseState(&mouseX, &mouseY);
			T.Position[0] = mouseX;
			T.Position[1] = mouseY;
			T.Position[2] = 0;
			quarter = circleObject.CreateCircle(T, 100);
			Points.insert(Points.end(), quarter.begin(), quarter.end());
			//RenderCircle(quarter);
			break;
		}
		case SDL_KEYDOWN:
			if (keyEvent.key.keysym.sym == SDLK_ESCAPE) {
				QuitNicely();
				return;
			}
			if (keyEvent.key.keysym.sym == SDLK_d)
			{
				Points = temp;
			}
			if (keyEvent.key.keysym.sym == SDLK_a)
			{
				for (int i = 0; i < Points.size(); ++i)
				{
					Points[i] = Points[i].Scale(0.5, 0.5, 0);
				}
			}
			if (keyEvent.key.keysym.sym == SDLK_s)
			{
				for (int i = 0; i < Points.size(); ++i)
				{
					Points[i] = Points[i].Scale(2, 2, 0);
				}
			}
			if (keyEvent.key.keysym.sym == SDLK_r)
			{
				for (int i = 0; i < Points.size(); ++i)
				{
					Points[i] = Points[i].RotatePoint("XY", 15);
				}
			}
			if (keyEvent.key.keysym.sym == SDLK_w)
			{
				Point T;
				int mouseX, mouseY;
				SDL_GetMouseState(&mouseX, &mouseY);
				T.Position[0] = mouseX;
				T.Position[1] = mouseY;
				line = lineSegment.CreateLine(OO, T);
				Points.insert(Points.end(), line.begin(), line.end());
			}
			break;
		default:
			break;
		}
		if (!quarter.empty())
			RenderCircle(quarter);
		RenderScene(Points);
	}
}
void Camera::RenderCircle(std::vector<Point> circleToRender) {
	SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0x00);
	for each (auto circlePoint in circleToRender)
	{
		SDL_RenderDrawPoint(mainRenderer, circlePoint.Position[0], circlePoint.Position[1]);
	}
	SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}
void Camera::RenderScene(std::vector<Point> Points) {
	SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0x00);
	for each (auto item in Points)
	{
		SDL_RenderDrawPoint(mainRenderer, item.Position[0], item.Position[1]);	
	}
	SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderPresent(mainRenderer);
	SDL_RenderClear(mainRenderer);
}
void Camera::QuitNicely() {
	SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyRenderer(oldRenderer);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}