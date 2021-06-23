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
    
    void playerupdate()
    {
        x_vel = y_vel = 0;
        if (up && !down)
            y_vel = -SPEED;
        else if (down && !up)
            y_vel = SPEED;
        else if (left && !right)
            x_vel = -SPEED;
        else if (right && !left)
            x_vel = SPEED;
    // keep track of which inputs are given
        up = 0;
        down = 0;
        left = 0;
        right = 0;
        // update positions
        psi_x += x_vel*delta_time; //x_vel ;// 60;
        psi_y +=  y_vel*delta_time;//y_vel;// 60;

        if (psi_x <= 0)
            psi_x = 0;
        if (psi_y <= 0)
            psi_y = 0;
        if (psi_x >= WINDOW_WIDTH/2 - desRect.w)
            psi_x = WINDOW_WIDTH/2 - desRect.w;
        if (psi_y <= WINDOW_HEIGHT-desRect.h-row3)
            psi_y =  WINDOW_HEIGHT-desRect.h-row3;
        if (psi_y >= WINDOW_HEIGHT-desRect.h-row1)
            psi_y =  WINDOW_HEIGHT-desRect.h-row1;

        // set the positions in the struct
        desRect.x = (int)psi_x;
        desRect.y = (int)psi_y;
    }

    int ReturnPlayerPositionx()
    {
        return psi_x ;
    }
    int ReturnPlayerPositiony()
    {
        return psi_y ;
    }
} Player;

#endif