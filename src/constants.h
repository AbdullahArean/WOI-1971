#ifndef CONSTANTS_H
#define CONSTANTS_H

//Preprocessors
#include <stdio.h>

//SDL Related Libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

//Defining Macro
#define FALSE 0
#define TRUE 1

//Window Height Width
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

//frame rate per Second
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

//ALL The Global Varaiables Declared Here
//variable to keep game state
bool game_running = 1;
int gameplay = 0;
int StoryScript = 0;
double last_frame_time;
double delta_time;
int keypressed=0;
int pause=0;
//Indicating Three Rows
int row1 = 0;
int row2 = 63;
int row3 = 117;

//Variables for keeping the sound state
bool sound_state = 1;

//Variables for keeping the health state
int phealth;
int pscore;

#include "clean.h"
#include "sound.h"
#include "font.h"

//SDL Window & Renderer
SDL_Window *window;
SDL_Renderer *renderer;

//SDL Textures for mainmenu
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

SDL_Texture *background = NULL;
SDL_Texture *gbg = NULL;
SDL_Texture *p1t = NULL;
SDL_Texture *e1t = NULL;
SDL_Texture *e2t = NULL;
SDL_Texture *i1t = NULL;
SDL_Texture *t1t = NULL;

SDL_Texture *son = NULL;
SDL_Texture *sonp = NULL;
SDL_Texture *soff = NULL;
SDL_Texture *soffp = NULL;
SDL_Texture *mainmenu = NULL;
SDL_Texture *mainmenup = NULL;
SDL_Texture *ppt = NULL;
SDL_Texture *exi = NULL;
SDL_Texture *exip= NULL;

#define SPEED (300)

//#define SPEED (300)

#endif