#include "GameEngine.h"

GameEngine::GameEngine()
{
	std::cout << "[GameEngine.cpp]: GameEngine is created! \n";
}

GameEngine::~GameEngine()
{
	std::cout << "[GameEngine.cpp]: GameEngine is destroyed! \n";
}

void GameEngine::init(const char* title, int xPos, int yPos, int width, int height, int flag){
	window = nullptr;
	renderer = nullptr;

	window = SDL_CreateWindow(title, xPos, yPos, width, height, flag);


}

void GameEngine::update()
{
}

void GameEngine::handleEvents()
{
}

void GameEngine::render()
{
}

bool GameEngine::running()
{
	return false;
}
