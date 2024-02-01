#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <SDL.h>
#include <SDL_image.h>
#include "Header.h"


class GameEngine {
public:
	GameEngine();
	~GameEngine();

	void init(const char* title, int xPos, int yPos, int width, int height, bool isFullScreen);
	void update();
	void handleEvents();
	void render();
	bool running();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning;
	int cnt;
	int xPosOfPen, yPosOfPen;
};





#endif