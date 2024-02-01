#include "GameEngine.h"

int main(int argc, char* argv[]) {
	GameEngine* gameEngine = nullptr;

	gameEngine = new GameEngine();
	gameEngine->init("Frame",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,600,600,false);

	while (gameEngine->running()) {
		gameEngine->handleEvents();
		gameEngine->update();
		gameEngine->render();	
		std::cout << "hehehehe";
	}

	gameEngine->~GameEngine();
	return 0;
}