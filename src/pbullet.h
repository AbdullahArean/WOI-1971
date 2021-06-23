#ifndef PBULLET_H
#define PBULLET_H

#include "constants.h"
#include "player.h"
extern Player p1;
typedef struct Bullet
{
    //Global Variables
    SDL_Rect srcRect;
    SDL_Rect desRect;
    
    //Scoring Variable
    double psi_x = 0.00;
    double psi_y =0.00;
    double bvelocity = 300;
    bool firsttime=0;



    //Draw
    void Bulletfire(int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        // Simple dimension calculation
        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);
        desRect.w = width;
        desRect.h = height;
        if(firsttime==0) {psi_x = p1.ReturnPlayerPositionx()+160;psi_y =p1.ReturnPlayerPositiony()+34;firsttime=1;}
        desRect.x = psi_x;
        desRect.y = psi_y;
        SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
        //SDL_RenderPresent(pRenderer);
    }
    void update()
    {    
        psi_x += bvelocity*delta_time;
        desRect.x = (int)psi_x;
        desRect.y = (int)psi_y;
    }

} Bullet;

#endif