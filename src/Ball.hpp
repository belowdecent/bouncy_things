#pragma once

#include "SDL_render.h"
#include "Sprite.hpp"
class Ball {
private:
	Sprite* sprite;
public:
	double x;
	double y;
	double vx;
	double vy;
	double radius;

	Ball(double x, double y, double radius, const char* path_to_sprite, SDL_Renderer* renderer);
	void UpdatePosition(double dt);
	void SetVelocity(double x, double y);
	void Draw();
	~Ball();
};

bool BallsOverlap(Ball* ball1, Ball* ball2);
void BallsReflect(Ball* ball1, Ball* ball2);

