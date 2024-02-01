#include "GameEngine.h"

int main(int argc, char* argv[]) {
	GameEngine* gameEngine = nullptr;
	const int FRAMES_PER_SECOND = 60;
	const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;
	Uint32 frameStart;
	Uint32 frameTime;

	gameEngine = new GameEngine();
	gameEngine->init("Frame",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,600,600,false);

	int frameCount = 0;
	while (gameEngine->running()) {
		frameCount++;
		if (frameCount > FRAMES_PER_SECOND) frameCount = 0;
		std::cout << "FPS: " << frameCount << "\n";

		frameStart = SDL_GetTicks();

		gameEngine->handleEvents();
		gameEngine->update();
		gameEngine->render();	

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < FRAME_DELAY) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
		//std::cout << "hehehehe";
	}

	gameEngine->~GameEngine();
	return 0;
}