#ifndef CONSTANTS_H
#define CONSTANTS_H

//Preprocessors
#include <stdio.h>

//SDL Related Libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

//Important files to linked
#include"texturemanager.h"
#include "clean.h"

//Defining Macro
#define FALSE 0
#define TRUE 1

//Window Height Width
// #define WINDOW_WIDTH 1080 
// #define WINDOW_HEIGHT 720

//frame rate per Second
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)


//ALL The Global Varaiables Declared Here
//variable to keep game state
bool game_running=1;

//SDL Window & Renderer
SDL_Window *window;
SDL_Renderer *renderer;

//Texture Manager
TextureManager TM;

//SDL Textures
SDL_Texture *fpage = NULL;
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


//#define SPEED (300)

#endif