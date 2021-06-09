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
typedef struct Player
{

    //Global Variables
    SDL_Rect srcRect;
    SDL_Rect desRect;
    double psi_x = 0;
    double psi_y = 520;
    double x_vel = 0;
    double y_vel = 0;

    //Draw
    void playerrender(int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        // Simple dimension calculation
        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);
        desRect.w = width;
        desRect.h = height;
        desRect.x =psi_x;
        desRect.y =psi_y;
        SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
        
    }
    //SDL_RenderPresent(pRenderer);
    void playerinput()
    {

        // keep track of which inputs are given
        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;

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
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    up = 1;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left = 1;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    down = 1;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right = 1;
                    break;
                default:
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    up = 0;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left = 0;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    down = 0;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right = 0;
                    break;
                default:
                    break;
                }
                break;
            }
        }

        // determine velocity
        x_vel = y_vel = 0;
        if (up && !down)
            y_vel = -SPEED/60;
        if (down && !up)
            y_vel = SPEED/60;
        if (left && !right)
            x_vel = -SPEED/60;
        if (right && !left)
            x_vel = SPEED/60;
    }
    void playerupdate()
    {
        // update positions
        psi_x += x_vel ;// 60;
        psi_y += y_vel ;// 60;

        // collision detection with bounds
        if (psi_x <= 0)
            psi_x = 0;
        if (psi_y <= 0)
            psi_y = 0;
        if (psi_x >= WINDOW_WIDTH - desRect.w)
            psi_x = WINDOW_WIDTH - desRect.w;
        if (psi_y >= WINDOW_HEIGHT - desRect.h)
            psi_y = WINDOW_HEIGHT - desRect.h;

        // set the positions in the struct
        desRect.x = (int)psi_x;
        desRect.y = (int)psi_y;
    }
} Player;

#endif