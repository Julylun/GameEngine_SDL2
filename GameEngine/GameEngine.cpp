#include "GameEngine.h"




SDL_Renderer* GameEngine::renderer = nullptr;
GameObject* player;
GameObject* enermy;

GameEngine::GameEngine()
{
	setDebug(true);
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
		player = new GameObject("assest/player.png");
		enermy = new GameObject("assest/enermy.png");
		enermy->setPosition(30, 30);


		std::cout << "[GameEngine.cpp]<init>: Initialized\n";
		debug();
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
	player->update();
	enermy->update();
	std::cout << cnt <<"\n";
}

void GameEngine::render()
{
	//std::cout << "Rendered!\n";
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	player->render();
	enermy->render();

	SDL_RenderPresent(GameEngine::renderer);
	//SDL_Delay(100);
}

bool GameEngine::running()
{	
	return isRunning;
}

void GameEngine::setDebug(bool isTrue) {
	isDebugging = isTrue;
}

void GameEngine::debug() {
	if (isDebugging) {
		player->setDebug(true);
		enermy->setDebug(true);
	}
}

void GameEngine::printDebugging() {
	std::cout << "Player position: (" << player->getDstRect().x << "," << player->getDstRect().y << ")\n";
}
