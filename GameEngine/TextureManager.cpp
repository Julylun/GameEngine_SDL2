#include "TextureManager.h"

SDL_Texture* TextureManager::loadAssest(const char* filePath, SDL_Renderer* renderer)
{
	SDL_Texture* texture;
	SDL_Surface* tempSurface = IMG_Load(filePath);
	if (tempSurface == NULL) {
		std::cout << "[TextureManager.cpp]<loadAssest>: IMG_Load is failed! - " << SDL_GetError() << "\n";
		return NULL;
	}
	
	texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return texture;
}
