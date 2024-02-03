#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include "GameEngine.h"

class TextureManager {
public:
	static SDL_Texture* loadAssest(const char* filePath, SDL_Renderer* renderer);
private:

};


#endif