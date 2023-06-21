#include "Sprite.hpp"
#include "SDL_image.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include <cstdio>

Sprite::Sprite(const char* path_to_texture, SDL_Renderer* context) {
	SDL_Surface* loaded_image = IMG_Load(path_to_texture);
	if (loaded_image == nullptr) {
		fprintf(stderr, "Bad image path!\n");
		exit(1);
	}

	this->texture = SDL_CreateTextureFromSurface(context, loaded_image);
	this->context = context;
	this->width = loaded_image->w;
	this->height = loaded_image->h;
	this->rect = {
		.w = this->width,
		.h = this->height
	};
	
	SDL_FreeSurface(loaded_image);
	
	if (this->texture == nullptr) {
		fprintf(stderr, "Weird! Couldn't convert to texture!\n");
		exit(1);
	}
}

void Sprite::Draw(int x, int y) {
	this->rect.x = x;
	this->rect.y = y;

	SDL_RenderCopy(
		this->context, 
		this->texture, 
		nullptr, 
		&this->rect
	);
}

Sprite::~Sprite() {
	if (this->texture != nullptr)
		SDL_DestroyTexture(this->texture);
}
