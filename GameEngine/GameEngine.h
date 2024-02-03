#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "Header.h"
#include "GameObject.h"


class GameEngine {
public:
	GameEngine();
	~GameEngine();

	void init(const char* title, int xPos, int yPos, int width, int height, bool isFullScreen);
	void update();
	void handleEvents();
	void render();
	bool running();
	void setDebug(bool isTrue);
	void debug();
	void printDebugging();
	

	static SDL_Renderer* renderer;

private:
	SDL_Window* window;

	bool isDebugging;
	bool isRunning;
	int cnt;
	int xPosOfPen, yPosOfPen;
};





#endif