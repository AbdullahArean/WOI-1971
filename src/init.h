#ifndef INIT_H
#define INIT_H

//Preprocessors
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>


//Initializing the subsystems
int intialization();


#include "init.h"

//Initializing the subsystems
int intialization()
{
    //Initializing all the subsystems(i.e. Video, Audio, Joystick etc.)
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        printf("Subsystem Initialization Error: %s\n",SDL_GetError());
        SDL_Quit();
        return 1;
    }

    //Initializing Image-Subsystem
    if(!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
    {
        printf("Image Initialization Error: %s\n",SDL_GetError());
        SDL_Quit();
        return 1;
    }

    //Printing a message whether we could successfully initialize the system
    printf("\nWW      WW  OOOOO  IIIII         1          7777777  1\nWW      WW OO   OO  III         111  99999      777 111\nWW   W  WW OO   OO  III  _____   11 99   99    777   11\n WW WWW WW OO   OO  III          11  999999   777    11\n  WW   WW   OOOO0  IIIII        111     99   777    111\n                                      999\n              \n");
    printf("Game Started Successfully! Enjoy!\n");
    return 0;
}

#endif