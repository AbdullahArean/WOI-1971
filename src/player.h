#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"




//Defining a function to find out the maximum of 2 numbers(i.e. positions)
double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

//Defining a function to find out the minimum of 2 numbers(i.e. positions)
double min(double a, double b)
{
    if (a < b)
        return a;
    else
        return b;
}
typedef struct Player{

    //Global Variables
SDL_Rect srcRect;
SDL_Rect desRect;
double psi_x;
double psi_y;
    //Draw
    void draw(int x, int y, int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        // Simple dimension calculation
        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);
        desRect.w = width;
        desRect.h = height;
        desRect.x = x;
        desRect.y = y;
        SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
        //SDL_RenderPresent(pRenderer);
    }
    //SDL_RenderPresent(pRenderer);
    void PlayerUpdate()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                game_running = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_LEFT:
                    psi_x = max(0, psi_x - FPS / 10);
                    break;
                case SDL_SCANCODE_RIGHT:
                    psi_x = min(940 - desRect.x, psi_x + FPS / 10);
                    break;
                case SDL_SCANCODE_UP:
                    psi_y = max(400, psi_y - FPS / 10);
                    break;
                case SDL_SCANCODE_DOWN:
                    psi_y = min(600, psi_y + FPS / 10);
                    break;
                default:
                    break;
                }
            }
        }
        desRect.x = (int)psi_x;
        desRect.y = (int)psi_y;
    }
}Player;

#endif