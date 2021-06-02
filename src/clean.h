#ifndef CLEAN_H
#define CLEAN_H

//Preprocessors
#include"constants.h"

//Destroying the window and the renderer
void Clean(SDL_Window* win, SDL_Renderer* render);
//Code Implementation
void Clean(SDL_Window* win, SDL_Renderer* render)
{

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
}

#endif 