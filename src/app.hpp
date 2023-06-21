#pragma once
#include <SDL.h>
#include <SDL_image.h>

class App {
private:
	SDL_Event e;
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* screen;
	bool quit_requested;

	App();
	void Clear();
	void Update();
	void LateUpdate();
	~App();
};
