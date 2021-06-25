#ifndef EBULLET_H
#define EBULLET_H

#include "constants.h"


typedef struct EBullet
{
    //Global Variables
    SDL_Rect srcRect;
    SDL_Rect desRect;

    //Scoring Variable
    double psi_x = 0.00;
    double psi_y = 0.00;
    double bvelocity = 300;
    bool firsttime = 0;
    bool bulletactive = 1;
    int playerornot = 0;

    //Draw
    void Bulletfire(int x, int y, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        // Simple dimension calculation
        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);
        desRect.w = 24;
        desRect.h = 8;
        if (firsttime == 0)
        {
            psi_x = x;
            psi_y = y;
            firsttime = 1;
        }
        desRect.x = psi_x;
        desRect.y = psi_y;
        if (bulletactive)
            SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
        //SDL_RenderPresent(pRenderer);
    }
    void update(int dir, int damage)
    {
        playerornot = dir; //if 1 then player otherwise not player
        if (bulletactive)
        {
            psi_x += (dir)*bvelocity * delta_time;
            desRect.x = (int)psi_x;
            
                int posx = p1.ReturnPositionx();
                int posy = p1.ReturnPositiony();

                if (psi_x >= posx && psi_x <= posx + 160* 0.75 && psi_y >= posy && psi_y <= posy + 180*0.75)
                {
                    bulletactive = 0;
                    if(!shield) phealth -= damage;
                    printf("Score=>%d Health=>%d\n", pscore, phealth);
                    return;
                }
            
            
        }
    }

} EBullet;

#endif