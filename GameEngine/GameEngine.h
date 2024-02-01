#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <SDL.h>
#include "Header.h"

class GameEngine {
public:
	GameEngine();
	~GameEngine();

	void init(const char* title, int xPos, int yPos, int width, int height, int flag);
	void update();
	void handleEvents();
	void render();
	bool running();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
};





#endif