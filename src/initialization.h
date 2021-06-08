#ifndef INITIALIZATION_H
#define INITIALIZATION_H

//Preprocessors
#include "constants.h"

bool gameinitialization(const char *title, int xpos, int ypos, int width, int height)
{

    /*#define SDL_INIT_EVERYTHING ( SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO |
SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMECONTROLLER | SDL_INIT_SENSOR )*/
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return 0;
    } //end if

    //Creating SDL_ Window
    window = SDL_CreateWindow(
        title,
        xpos,
        ypos,
        width, height,
        SDL_WINDOW_SHOWN);
    if (!window)
    {
        fprintf(stderr, "Error creating SDL Window.\n");
        SDL_Quit();
        return 0;
    }

    // create a renderer, which sets up the graphics hardware
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    //Creating A SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, render_flags);
    if (!renderer)
    {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        return 1;
    }

    //Initializing Image-Subsystem
    if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
    {
        printf("Image Initialization Error: %s\n", SDL_GetError());
        SDL_Quit();
        IMG_Quit();
        return false;
    }
    //Initializing Sound system
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }

    //Initializing font
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    //game init successful message
    printf("\nWW      WW  OOOOO  IIIII         1          7777777  1\nWW      WW OO   OO  III         111  99999      777 111\nWW   W  WW OO   OO  III  _____   11 99   99    777   11\n WW WWW WW OO   OO  III          11  999999   777    11\n  WW   WW   OOOO0  IIIII        111     99   777    111\n                                      999\n              \n");
    printf("Game Started Successfully! Enjoy!\n");

    return TRUE;
}

#endif