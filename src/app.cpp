#include "app.hpp"
#include "SDL_cpuinfo.h"
#include "SDL_events.h"
#include "SDL_image.h"
#include "SDL_render.h"
#include "SDL_video.h"

App::App() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      printf("Failed initialising video! Reason: %s\n", SDL_GetError());
      exit(1);
  }

	this->quit_requested = false;
	this->window = SDL_CreateWindow(
		"r", 
		0, 0, 
		480, 480, 
		SDL_WINDOW_SHOWN
	);
	this->renderer = SDL_CreateRenderer(
		this->window, 
		-1, 
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

  int img_flags = IMG_INIT_PNG;
  if (!(IMG_Init(img_flags) & img_flags)) {
      printf("Failed png routine! Reason: %s\n", IMG_GetError());
      exit(1);
  }
}

void App::Update() {
  while(SDL_PollEvent(&this->e) != 0) {
    if(e.type == SDL_QUIT || e.type == SDL_KEYDOWN) 
			this->quit_requested = true;
  }

  SDL_RenderClear(renderer);
}

void App::LateUpdate() {
  SDL_RenderPresent(renderer);
}

App::~App() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	IMG_Quit();
	SDL_Quit();
}
