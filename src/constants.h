#ifndef CONSTANTS_H
#define CONSTANTS_H

//Preprocessors
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>


#include"texturemanager.h"
#include "clean.h"
//#include"game.h"

bool game_running=1;

SDL_Window *window;
SDL_Renderer *renderer;
// speed in pixels/second

//Defining Macro
#define FALSE 0
#define TRUE 1
//Window Height Width
#define WINDOW_WIDTH 1080 
#define WINDOW_HEIGHT 720

//frame rate per Second
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)
SDL_Texture *fpage = NULL;
TextureManager menu;
TextureManager TM;
SDL_Texture *bg = NULL;
SDL_Texture *con = NULL;
SDL_Texture *newg = NULL;
SDL_Texture *his = NULL;
SDL_Texture *settings = NULL;
SDL_Texture *story = NULL;

SDL_Texture *conp = NULL;
SDL_Texture *newgp = NULL;
SDL_Texture *hisp = NULL;
SDL_Texture *settingsp = NULL;
SDL_Texture *storyp = NULL;


#define SPEED (300)

#endif