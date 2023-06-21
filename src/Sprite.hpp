#pragma once
#include "SDL.h"

class Sprite {
private:
	SDL_Texture* texture;
	SDL_Renderer* context;

	int width;
	int height;
public:
	SDL_Rect rect;
	
	Sprite(const char* path_to_texture, SDL_Renderer* context);
	void Draw(int x, int y);
	~Sprite();
};
