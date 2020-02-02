#include "Camera.hpp"

void Camera::Init(int _Width, int _Height)
{
	Width = _Width;
	Height = _Height;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 
		|| TTF_Init() == -1 
		|| (TitleFont = TTF_OpenFont("D:\\Documents\\Projects\\C++_Projects\\game_on_64bits_VS\\game_on_64bits\\resources\\Roboto-Bold.ttf", 16)) == nullptr
		|| IMG_Init(IMG_INIT_PNG) == 0)
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
			//Ilumination = light.CalculateLight(mouseX, mouseY);
			break;
		case SDL_MOUSEBUTTONDOWN: {
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
				ClearRenderer();
				GenerateMap();
				FirstPlayer.texture = "D:\\Documents\\Projects\\C++_Projects\\game_on_64bits_VS\\game_on_64bits\\resources\\elisa.png";
				FirstPlayer.SetStart(11.0, 11.0, 10.0, 10.0);
				mapGenerated = true;
			}
			
			if (keyEvent.key.keysym.sym == SDLK_a)
			{
				FirstPlayer.Move(3.0, 3);
			}
			if (keyEvent.key.keysym.sym == SDLK_s)
			{
				FirstPlayer.Move(3.0, 0);
			}
			if (keyEvent.key.keysym.sym == SDLK_w)
			{
				FirstPlayer.Move(3.0, 1);
			}
			if (keyEvent.key.keysym.sym == SDLK_d)
			{
				FirstPlayer.Move(3.0, 2);
			}
			break;
		default:
			break;
		}
		RenderScene();
	}
}
void Camera::RenderScene() {
	ClearRenderer();
	if(mapGenerated)
	{
		if(FirstPlayer.texture == "")
		{
			SDL_SetRenderDrawColor(mainRenderer, 0x00, 0xEE, 0x00, 0x00);
			float* player = FirstPlayer.CheckPosition();
			float* sizePlayer = FirstPlayer.GetSize();
			SDL_Rect* playerSize = new SDL_Rect;
			playerSize->w = sizePlayer[0];
			playerSize->h = sizePlayer[1];
			playerSize->x = player[0];
			playerSize->y = player[1];
			SDL_RenderFillRect(mainRenderer,playerSize);
			std::cout << player[0]
				<< ","
				<< player[1]
				<< std::endl;
			SDL_SetRenderDrawColor(mainRenderer, 0x00 * Ilumination, 0x00 * Ilumination, 0x00 * Ilumination, 0xFF);
		} else
		{
			SDL_Surface *playerSurface = IMG_Load(FirstPlayer.texture);
			SDL_Texture *playerTexture = SDL_CreateTextureFromSurface(mainRenderer, playerSurface);
			SDL_Rect playerOrigin;
			playerOrigin.w = playerSurface->w;
			playerOrigin.h = playerSurface->h;
			playerOrigin.x = 0;
			playerOrigin.y = 0;
			SDL_Rect playerPosition;
			playerPosition.w = 32;
			playerPosition.h = 32;
			playerPosition.x = FirstPlayer.CheckPosition()[0];
			playerPosition.y = FirstPlayer.CheckPosition()[1];
			SDL_RenderCopy(mainRenderer, playerTexture, &playerOrigin, &playerPosition);
			SDL_FreeSurface(playerSurface);
			SDL_DestroyTexture(playerTexture);
		}
	} else
	{
		GenerateTitleScreen();
		SDL_SetRenderDrawColor(mainRenderer, 0xFF * Ilumination, 0xFF * Ilumination, 0xFF * Ilumination, 0xFF);
	}
	SDL_RenderPresent(mainRenderer);
}
void Camera::ClearRenderer()
{
	SDL_RenderClear(mainRenderer);
	if(mapGenerated)
		GenerateMap();
	
}
void Camera::QuitNicely() {
	TTF_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}
void Camera::GenerateMap()
{
	SDL_SetRenderDrawColor(mainRenderer, 0x00, 0xEE, 0xEE, 0x00);
	SDL_RenderDrawLine(mainRenderer, 10, 10, Width - 10, 10);
	SDL_RenderDrawLine(mainRenderer, Width - 10, 10, Width - 10, Height - 10);
	SDL_RenderDrawLine(mainRenderer, Width - 10, Height - 10, 10, Height - 10);
	SDL_RenderDrawLine(mainRenderer, 10, Height - 10, 10, 10);
	SDL_RenderDrawLine(mainRenderer, Width / 2, 10, Width / 2, Height - 10);
	SDL_RenderDrawLine(mainRenderer, 10, Height / 2, Width - 10, Height / 2);
}
void Camera::GenerateTitleScreen()
{
	const SDL_Color titleColor = { 255,0,0 };
	SDL_Surface* title = TTF_RenderText_Solid(TitleFont, "mysterious-hat-engine", titleColor);
	SDL_Texture* titleTexture = SDL_CreateTextureFromSurface(mainRenderer, title);
	SDL_Rect TitlePosition;
	TitlePosition.x = (Width / 2) - (title->w / 2);
	TitlePosition.y = 10;
	TitlePosition.w = title->w;
	TitlePosition.h = title->h;
	SDL_SetRenderDrawColor(mainRenderer, 255, 0, 0, 255);
	SDL_RenderCopy(mainRenderer, titleTexture, NULL, &TitlePosition);
	SDL_FreeSurface(title);
	SDL_DestroyTexture(titleTexture);
	SDL_Surface* logoImage;
	logoImage = IMG_Load("D:\\Documents\\Projects\\C++_Projects\\game_on_64bits_VS\\game_on_64bits\\resources\\Icon4k.png");
	SDL_Rect* logoPosition = new SDL_Rect;
	logoPosition->w = logoImage->w;
	logoPosition->h = logoImage->h;
	logoPosition->x = (Width / 2) - (logoImage->w / 2);
	logoPosition->y = 200;
	SDL_Texture* logoTexture = SDL_CreateTextureFromSurface(mainRenderer, logoImage);
	SDL_RenderCopy(mainRenderer, logoTexture, NULL, logoPosition);
	SDL_FreeSurface(logoImage);
	SDL_DestroyTexture(logoTexture);
}