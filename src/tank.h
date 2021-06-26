#ifndef TANK_H
#define TANK_H

#include "constants.h"

typedef struct TANK{
//Global Variables
    EBullet b2[10000];
    SDL_Rect srcRect;
    SDL_Rect desRect;
    
    //Scoring Variable
    int health=200;
    bool dead=0;

    double psi_x = WINDOW_WIDTH-160;
    double psi_y = WINDOW_HEIGHT-180-row3;
    double x_vel = 30;
    double y_vel = 30;

    int keeptrack = 0;
    bool ft = 0, ff=0; 
    int enemybulletno = 0;


    //Draw
    void TankRender(int x, int y, int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        if(!dead){
        // Simple dimension calculation
        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);
        desRect.w = width;
        desRect.h = height;
        desRect.x = psi_x;
        desRect.y = psi_y;
        SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
        if ((int)(SDL_GetTicks() - keeptrack) >= einterval)
            {
                enemybulletno++;
                keeptrack = SDL_GetTicks();
            }
            for (int i = 0; i < enemybulletno; i++)
            {
                b2[i].Bulletfire(psi_x, psi_y + 24, bu1, renderer, SDL_FLIP_NONE);
            }
        }
    }
    void tankupdate(double row, double v_vel)
    {
        // update positions
        if(!dead){
        if(ft==0) {x_vel=v_vel; ft=1;}
        psi_x -= x_vel*delta_time; //x_vel ;// 60;
        psi_y -=  y_vel*delta_time;//y_vel;// 60;
        
        // collision detection with bounds
        if (psi_x >= WINDOW_WIDTH-desRect.w)
            {psi_x = WINDOW_WIDTH-desRect.w;
            x_vel= (-1)*x_vel;}
        if (psi_y > WINDOW_HEIGHT-desRect.h)
            psi_y = WINDOW_HEIGHT-desRect.h;
        if (psi_x < WINDOW_WIDTH/2)
            {psi_x = WINDOW_WIDTH/2;
            x_vel= (-1)*x_vel;}
        if (psi_y < WINDOW_HEIGHT-desRect.h-row)
            psi_y =  WINDOW_HEIGHT-desRect.h-row;


        // set the positions in the struct
        desRect.x = (int)psi_x;
        desRect.y = (int)psi_y;

        for (int i = 0; i < enemybulletno; i++)
            {
                b2[i].update(-1,20);
            }
        }
    }
   void updatehealth(int command)
    {
        if (!dead)
        {
        if (command == -1)
            health -= 20;
        if (health <= 0)
            dead = 1;
        }
    }
    int ReturnPositionx()
    {
        if (!dead)
        {
        return psi_x;
        }
        else return -1;
    }
    int ReturnPositiony()
    {
        if (!dead)
        {
        return psi_y;
        }
        else return -1;
    }
} Tank;

#endif