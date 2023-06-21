#include "Ball.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>

Ball::Ball(
	double x, 
	double y, 
	double radius, 
	const char* path_to_sprite, 
	SDL_Renderer* renderer
) {
	this->sprite = new Sprite(path_to_sprite, renderer);
	this->sprite->rect.w = (int)(radius * 2);
	this->sprite->rect.h = (int)(radius * 2);
	this->x = x;
	this->y = y;
	this->radius = radius;

	this->vx = 0;
	this->vy = 0;
}

void Ball::SetVelocity(double x, double y) {
	this->vx = x;
	this->vy = y;
}

void Ball::UpdatePosition(double dt) {
	this->x += this->vx * dt;
	this->y += this->vy * dt;

	if (this->x + 2 * this->radius >= 480) {
		this->vx *= -1;
	} else if (this->x <= 0) {
		this->vx *= -1;
	}

	if (this->y + 2 * this->radius >= 480) {
		this->vy *= -1;
	} else if (this->y <= 0) {
		this->vy *= -1;
	}
}

void Ball::Draw() {
	this->sprite->Draw(this->x, this->y);
}

Ball::~Ball() {
	delete this->sprite;
}

bool BallsOverlap(Ball* ball1, Ball* ball2) {
	double dx = ball1->x + ball1->radius - ball2->x - ball2->radius;
	double dy = ball1->y + ball1->radius - ball2->y - ball2->radius;

	return (ball1->radius + ball2->radius) >= std::sqrt(dx * dx + dy * dy);
}

void BallsReflect(Ball* ball1, Ball* ball2) {
	ball1->vx = std::fabs(std::rand() % 15 + 10);
	ball1->vy = std::fabs(std::rand() % 15 + 10);
	if (ball1->x < ball2->x) {
		ball1->vx *= -1;
	}
	if (ball1->y < ball2->y) {
		ball2->vy *= -1;
	}
	
	ball2->vx = -ball1->vx;
	ball2->vy = -ball1->vy;
}
