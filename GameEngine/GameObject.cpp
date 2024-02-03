#include "GameObject.h"

GameObject::GameObject(const char* assetPath)
{
	isDebugging = false;
	objectTexture = TextureManager::loadAssest(assetPath, GameEngine::renderer);
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.w = 64;
	dstRect.h = 64;
	dstRect.x = 0;
	dstRect.y = 0;
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(objectTexture);
	
}

void GameObject::update()
{
	dstRect.x++;
	dstRect.y++;
}

void GameObject::render()
{
	SDL_RenderCopy(GameEngine::renderer, objectTexture, &srcRect, &dstRect);
	if (isDebugging) {
		SDL_SetRenderDrawColor(GameEngine::renderer, 255, 0, 0, 255);
		SDL_RenderDrawRect(GameEngine::renderer, &dstRect);
		SDL_SetRenderDrawColor(GameEngine::renderer, 0, 0, 0, 0);
	}
}

void GameObject::setDebug(bool isTrue) {
	isDebugging = isTrue;
}

void GameObject::setPosition(int x, int y) {
	dstRect.x = x;
	dstRect.y = y;
}

SDL_Rect GameObject::GameObject::getDstRect() {
	return dstRect;
}