#ifndef CONSTANTS_H
#define CONSTANTS_H

//Preprocessors
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

//Defining Macro
#define FALSE 0
#define TRUE 1
//Window Height Width
#define WINDOW_WIDTH 1280 
#define WINDOW_HEIGHT 720

//frame rate per Second
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

bool game_running=1;

// speed in pixels/second
#define SPEED (300)

#endif