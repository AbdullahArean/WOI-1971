#ifndef BULLET_H
#define BULLET_H

#include "constants.h"
//#include "player.h"

typedef struct Bullet
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
    void update(int dir)
    {
        playerornot = dir; //if 1 then player otherwise not player
        if (bulletactive)
        {
            psi_x += (dir)*bvelocity * delta_time;
            desRect.x = (int)psi_x;
            for (int i = 0; i < EnemyNumber && playerornot == 1; i++)
            {
                int eposx = e1[i].ReturnPositionx();
                int eposy = e1[i].ReturnPositiony();

                if (psi_x >= eposx && psi_x <= eposx + 160 * 0.80 && psi_y >= eposy && psi_y <= eposy + 180 * 0.80)
                {
                    bulletactive = 0;
                    pscore += 10;
                    e1[i].updatehealth(-1);
                    printf("Score=>%d Health=>%d\n", pscore, phealth);
                    return;
                }
            }
            for (int i = 0; i < TankNumber && playerornot == 1; i++)
            {
                int tposx = t1[i].ReturnPositionx();
                int tposy = t1[i].ReturnPositiony();

                if (psi_x >= tposx && psi_x <= tposx + 300 * 0.80 && psi_y >= tposy && psi_y <= tposy + 180 * 0.80)
                {
                    bulletactive = 0;
                    pscore += 20;
                    t1[i].updatehealth(-1);
                    printf("Score=>%d Health=>%d\n", pscore, phealth);
                    return;
                }
            }
            for (int i = 0; i < InnocentNumber && playerornot == 1; i++)
            {
                int iposx = i1[i].ReturnPositionx();
                int iposy = i1[i].ReturnPositiony();

                if (psi_x >= iposx && psi_x <= iposx + 160 * 0.80 && psi_y >= iposy && psi_y <= iposy + 180 * 0.80)
                {
                    bulletactive = 0;
                    phealth -= 25;
                    i1[i].updatehealth(-1);
                    printf("Score=>%d Health=>%d\n", pscore, phealth);
                    return;
                }
            }
        }
    }

} Bullet;

#endif