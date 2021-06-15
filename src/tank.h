#ifndef TANK_H
#define TANK_H

#include "constants.h"

typedef struct TANK{
//Global Variables
    SDL_Rect srcRect;
    SDL_Rect desRect;
    
    //Scoring Variable
    int thealth=500;
    int trunninghealth;
    int tcollision;


    double psi_x = WINDOW_WIDTH-160;
    double psi_y = WINDOW_HEIGHT-180-row3;
    double x_vel = 30;
    double y_vel = 30;
    bool ft=0;


    //Draw
    void TankRender(int x, int y, int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        // Simple dimension calculation
        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);
        desRect.w = width;
        desRect.h = height;
        desRect.x = psi_x;
        desRect.y = psi_y;
        SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
        //SDL_RenderPresent(pRenderer);
    }
    void tankupdate(double row, double v_vel)
    {
        // update positions
        
        if(ft==0) {x_vel=v_vel; ft=1;}
        psi_x -= x_vel*delta_time; //x_vel ;// 60;
        psi_y -=  y_vel*delta_time;//y_vel;// 60;
        
        // collision detection with bounds
        if (psi_x >= WINDOW_WIDTH-desRect.w)
            {psi_x = WINDOW_WIDTH-desRect.w;
            x_vel= (-1)*x_vel;}
        if (psi_y > WINDOW_HEIGHT-desRect.h)
            psi_y = WINDOW_HEIGHT-desRect.h;
        if (psi_x < WINDOW_WIDTH/2 - desRect.w)
            {psi_x = WINDOW_WIDTH/2 - desRect.w;
            x_vel= (-1)*x_vel;}
        if (psi_y < WINDOW_HEIGHT-desRect.h-row)
            psi_y =  WINDOW_HEIGHT-desRect.h-row;


        // set the positions in the struct
        desRect.x = (int)psi_x;
        desRect.y = (int)psi_y;
    }
    int returnehealth()
    {
        trunninghealth = thealth-tcollision*20;
        return trunninghealth;
    }
} Tank;

#endif