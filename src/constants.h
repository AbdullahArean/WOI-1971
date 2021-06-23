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
#include "clean.h"
#include "sound.h"
#include "font.h"
//#include "player.h"

//Defining Macro
#define FALSE 0
#define TRUE 1

//Window Height Width
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720
#define SPEED (300) //Player Speed

//To give same experience in every device
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

// Global Declaration of Player
//Player p1;
//Regarding Frame Time
double last_frame_time;
double delta_time;

//variable to keep game state
bool game_running = 1;

//variable to state if game is played or not
int gameplay = 0;

//game over variable
int gameover =0;

//A variable for Story Showing
int StoryScript = 0;

//MainMenu Variable to keep track something pressed or not
int keypressed = 0;

//If Game is paused
int pause = 0;

//Indicating Three Rows
int row1 = 0;
int row2 = 63;
int row3 = 117;

// keep track of which inputs are given
int up = 0, down = 0, left = 0, right = 0;

//Variables for keeping the sound state
bool sound_state = 1;

//bullet number
int bn=0;

//player shot or not
int shot=0;

//EnemyNumber
int EnemyNumber=2;
int TankNumber= 2;
int InnocentNumber=2;

//Variables for keeping the health and score state
int phealth = 100;
int pscore = 0;

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

//SDL Textures for settings
SDL_Texture *son = NULL;
SDL_Texture *sonp = NULL;
SDL_Texture *soff = NULL;
SDL_Texture *soffp = NULL;
SDL_Texture *mainmenu = NULL;
SDL_Texture *mainmenup = NULL;
SDL_Texture *ppt = NULL;
SDL_Texture *exi = NULL;
SDL_Texture *exip = NULL;

//Game Texture for Last Page
SDL_Texture *re = NULL;
SDL_Texture *rep = NULL;
SDL_Texture *sap = NULL;
SDL_Texture *sa = NULL;

//SDL Textures for gameplay
SDL_Texture *background = NULL;
SDL_Texture *gbg = NULL;
SDL_Texture *p1t = NULL;
SDL_Texture *e1t = NULL;
SDL_Texture *e2t = NULL;
SDL_Texture *i1t = NULL;
SDL_Texture *t1t = NULL;
SDL_Texture *bu = NULL;
SDL_Texture *bu1 = NULL;

#endif