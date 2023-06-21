#include <cstdio>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Ball.hpp"
#include "SDL_events.h"
#include "app.hpp"
#include "Sprite.hpp"

int main() {
    App app;
    Ball ball1(0, 0, 25, "images/ball.png", app.renderer);
    Ball ball2(70, 70, 55, "images/ball.png", app.renderer);
    ball1.SetVelocity(15, 15);
    ball2.SetVelocity(2, 2);

    int i = 0;
    while (!app.quit_requested) {
        app.Update();
        ball1.UpdatePosition(0.15);
        ball2.UpdatePosition(0.15);
        if (BallsOverlap(&ball1, &ball2)) {
            BallsReflect(&ball1, &ball2);
        }
        
        ball1.Draw();
        ball2.Draw();
        app.LateUpdate();
    }

   return EXIT_SUCCESS;
}
