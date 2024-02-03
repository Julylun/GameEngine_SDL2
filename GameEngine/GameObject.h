#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "GameEngine.h"

class GameObject {
public:
	GameObject(const char* assetPath);
	~GameObject();

	void update();
	void render();
	void setDebug(bool isTrue);
	void setPosition(int x, int y);
	SDL_Rect getDstRect();
private:
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, dstRect;
	bool isDebugging;
};

#endif // GAME_OBJECT_H
