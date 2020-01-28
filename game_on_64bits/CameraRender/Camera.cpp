#include "Camera.hpp"
#include <queue>

void Camera::Init(int Width, int Height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
		return;
	mainWindow = SDL_CreateWindow("mysterious-hat-engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		Width, Height, SDL_WINDOW_SHOWN);
	mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_TARGETTEXTURE);
	while (playing) {
		SDL_PollEvent(&keyEvent);
		switch (keyEvent.type)
		{
		case SDL_MOUSEMOTION:
			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);
			light.Position[0] = 0;
			light.Position[1] = 0;
			Ilumination = light.CalculateLight(mouseX, mouseY);
			break;
		case SDL_MOUSEBUTTONDOWN: {
			/*int mouseX, mouseY;
			Point T;
			SDL_GetMouseState(&mouseX, &mouseY);
			T.Position[0] = mouseX;
			T.Position[1] = mouseY;
			T.Position[2] = 0;
			quarter = circleObject.CreateCircle(T, 100);
			Points.insert(Points.end(), quarter.begin(), quarter.end());*/
			break;
		}
		case SDL_KEYDOWN:
			if (keyEvent.key.keysym.sym == SDLK_ESCAPE) {
				QuitNicely();
				return;
			}
			if (keyEvent.key.keysym.sym == SDLK_g)
			{
				//Generate the map
				SDL_RenderDrawLine(mainRenderer, 0, 0, 100, 100);
				
				
			}
			/*
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
			if (keyEvent.key.keysym.sym == SDLK_f)
			{
				Triangle triangle;
				std::vector<Point> trianglePoints;
				int mouseX = 0, mouseY = 0;
				Point X, T, S;
				SDL_GetMouseState(&mouseX, &mouseY);
				X.Position[0] = mouseX;
				X.Position[1] = mouseY;
				X.Position[2] = 0;
				T.Position[0] = X.Position[0]+10;
				T.Position[1] = X.Position[1]+10;
				T.Position[2] = 0;
				S.Position[0] = T.Position[0]-20;
				S.Position[1] = T.Position[1];
				S.Position[2] = 0;
				triangle.CreateTriangle(mainRenderer, X, T, S);
				//Points.insert(Points.end(), trianglePoints.begin(), trianglePoints.end());
			}
			if (keyEvent.key.keysym.sym == SDLK_w)
			{
				Point T, S;
				int mouseX, mouseY;
				SDL_GetMouseState(&mouseX, &mouseY);
				std::vector<Point> lineConverted;
				T.Position[0] = mouseX - OO.Position[0];
				T.Position[1] = mouseY - OO.Position[1];
				S.Position[0] = 0;
				S.Position[1] = 0;
				line = lineSegment.CreateLine(S, T);
				Points.insert(Points.end(), line.begin(), line.end());
			}
			*/
			break;
		default:
			break;
		}
		/*if (!quarter.empty())
			RenderCircle(quarter);*/
		RenderScene();
	}
}
/*void Camera::RenderCircle(std::vector<Point> circleToRender) {
	SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0x00);
	for each (auto circlePoint in circleToRender)
	{
		SDL_RenderDrawPoint(mainRenderer, circlePoint.Position[0], circlePoint.Position[1]);
	}
	SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}*/
void Camera::RenderScene() {
	//SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0x00);
	/*if(points.size() > 0)
		for each (auto item in points)
		{
			SDL_RenderDrawPoint(mainRenderer, item.Position[0], item.Position[1]);	
		}
	if(lines.size() > 0)
		for each (auto item in lines)
		{
			SDL_RenderDrawLine(mainRenderer, item.start.Position[0], item.start.Position[1],
				item.end.Position[0], item.end.Position[1]);
		}
	if(triangles.size() > 0)
		for each (auto item in triangles)
		{
			SDL_RenderDrawLine(mainRenderer,  item.l1.start.Position[0], item.l1.start.Position[1],
				item.l1.end.Position[0], item.l1.end.Position[0]);
			SDL_RenderDrawLine(mainRenderer, item.l2.start.Position[0], item.l2.start.Position[1],
				item.l2.end.Position[0], item.l2.end.Position[0]);
			SDL_RenderDrawLine(mainRenderer, item.l3.start.Position[0], item.l3.start.Position[1],
				item.l3.end.Position[0], item.l3.end.Position[0]);
		}*/
	SDL_SetRenderDrawColor(mainRenderer, 0xFF*Ilumination, 0xFF*Ilumination, 0xFF*Ilumination, 0xFF);
	SDL_RenderPresent(mainRenderer);
}
void ClearRenderer(SDL_Renderer *mainRenderer)
{
	SDL_RenderClear(mainRenderer);
}
void Camera::QuitNicely() {
	SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}