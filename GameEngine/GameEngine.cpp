#include "GameEngine.h"



SDL_Texture* playerTexture;
SDL_Rect* playerMargin;

GameEngine::GameEngine()
{
	std::cout << "[GameEngine.cpp]: GameEngine is created! \n";
}

GameEngine::~GameEngine()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "[GameEngine.cpp]: GameEngine is kiiled! \n";
}

void GameEngine::init(const char* title, int xPos, int yPos, int width, int height, bool isFullScreen){
	std::cout << "[GameEngine.cpp]<init>: Initializing...\n";
	window = nullptr;
	renderer = nullptr;
	cnt = 0;
	xPosOfPen = 0;
	yPosOfPen = 0;
	int flag = 0;
	playerMargin = new SDL_Rect();
	playerMargin->x = 0;
	playerMargin->y = 0;
	playerMargin->w = 100;
	playerMargin->h = 100;

	if (isFullScreen == true) flag = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flag);
		if (!window) {
			std::cout << "[GameEngine.cpp]<init>: window creating is failed!\n";
			GameEngine::isRunning = false;
			return;
		}
		std::cout << "[GameEngine.cpp]<init> window is created\n";


		renderer = SDL_CreateRenderer(window, -1, 0);
		if (!renderer) {
			std::cout << "[GameEngine.cpp]<init>: renderer creating is failed\n";
			GameEngine::isRunning = false;
			return;
		}
		
		std::cout << "[GameEngine.cpp]<init>: renderer is created\n";
		
		std::cout << "[GameEngine.cpp]<init>: Adding texture into window\n";
		SDL_Surface* tempSurface = IMG_Load("assest/player.png");
		if (tempSurface == NULL) {
			std::cout << "[GameEngine.cpp]<init>: Loading image from file path to tempSurface is failed! - " << SDL_GetError() << "\n";
			GameEngine::isRunning = false;
			return;
		}
		playerTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);

		std::cout << "[GameEngine.cpp]<init>: Initialized\n";
		GameEngine::isRunning = true;
		return;
	}

	

	
	GameEngine::isRunning = false;
	return;
}

void GameEngine::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT: {
		GameEngine::isRunning = false;
		std::cout << "[GameEngine.cpp]<handleEvents> An Event is caught - GameEngine.isRunning = false\n";
	}
	default:
		break;
	}
}

void GameEngine::update()
{
	//std::cout << "updated!\n";
	cnt++;
	xPosOfPen++;
	yPosOfPen++;

	playerMargin->x++;
	playerMargin->y++;

	std::cout << cnt <<"\n";
}

void GameEngine::render()
{
	//std::cout << "Rendered!\n";
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	
	SDL_RenderCopy(renderer, playerTexture, NULL, playerMargin);
	SDL_RenderPresent(renderer);
	//SDL_Delay(100);
}

bool GameEngine::running()
{	
	
	return isRunning;
}
