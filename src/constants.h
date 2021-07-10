#ifndef CONSTANTS_H
#define CONSTANTS_H

//Preprocessors
#include <stdio.h>
#include <stdlib.h>

//SDL Related Libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

//Header Files

#include "sound.h"
#include "font.h"



//Defining Macro
#define FALSE 0
#define TRUE 1

//Window Height Width
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

//To give same experience in every device
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

// Global Declaration of Player
//Player p1;
//Regarding Frame Time
double last_frame_time;
double delta_time;
int SPEED = 300;       //Player Speed
int pinterval = 500;   //player fire interval
int einterval = 5000;  //enemy fire interval
int shieldnumber = 3;  //Number of Shield
int sn = 0;            //Current Number of Shield
bool game_running = 1; //variable to keep game state
int gameplay = 0;      //variable to state if game is played or not
int gameover = 0;      //game over variable denoting level finish and die or not
int StoryScript = 0;   //A variable for Story Showing
int keypressed = 0;    //used in mainmenu.h and game.h to keep track something pressed or not
int pause = 0;         //Game is paused or not
bool shield = 0;       //shield activated or not
//Indicating Three Rows
int row1 = 0;
int row2 = 63;
int row3 = 117;
int up = 0, down = 0, left = 0, right = 0; // keep track of which inputs are given
bool sound_state = 1;                      //Variables for keeping the sound state
int bn = 0;                                //bullet number spent by player
int shot = 0;                              //player shot bullet or not
int EnemyNumber = 200;                     //Maximum EnemyNumber
int TankNumber = 100;                      //Maximum TankNumber
int InnocentNumber = 200;                  //Maximum EnemyNumber
int phealth = 100;                         //Player health
int pscore = 0;                            //Player Score
int gamelevel = 1;                         //variable denoting game level
int bvelocity = 300; //Player Bullet Velocity
int evelocity = 300;                      //Enemy Bullet Velocity
//string for showing the font
char scorestr[11];
char shieldstr[11];
char healthstr[11];

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
SDL_Texture *nextlevelp = NULL;
SDL_Texture *nextlevel = NULL;

//SDL Textures for settings
SDL_Texture *son = NULL;
SDL_Texture *sonp = NULL;
SDL_Texture *soff = NULL;
SDL_Texture *soffp = NULL;
SDL_Texture *mainmenu = NULL;
SDL_Texture *mainmenup = NULL;
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
SDL_Texture *storyback = NULL;
SDL_Texture *shie = NULL;

//Global Declaration of Player
#include "player.h"
Player p1;

//Global Declaration of Enemies
#include "enemy.h"
Enemy e1[200];

//Global Declaration of Tanks
#include "tank.h"
Tank t1[100];

//Global Declaration of Innocents
#include "innocent.h"
Innocent i1[200];


#include "clean.h"

#endif