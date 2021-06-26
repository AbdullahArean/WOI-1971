#ifndef CLEAN_H
#define CLEAN_H

//Preprocessors
#include "constants.h"
#include "sound.h"

//Destroying the window and the renderer
void Clean(SDL_Window *win, SDL_Renderer *render)
{
    soundclose();
    SDL_DestroyRenderer(render); //Destroying Renderer
    SDL_DestroyWindow(win);      //Destroying Window
    TTF_Quit();                  //Quiting SDL_ttf
    Mix_Quit();                  //Quiting SDL_mixer
    IMG_Quit();                  //Quiting SDL Image
    SDL_Quit();                  //Quiting SDL
}

#endif