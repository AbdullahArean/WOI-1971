#ifndef EBULLET_H
#define EBULLET_H
//User Defined Header File Included
#include "constants.h"

typedef struct EBullet //Enemy Bullet structure
{
    //Rectangle to keep track
    SDL_Rect srcRect; //Source rectangle
    SDL_Rect desRect; //Destination rectangle

    //Scoring Variable
    double psi_x = 0.00; //position in x axis
    double psi_y = 0.00; //position in y axis

    bool firsttime = 0;    //Checking Bullet started rendering or not
    bool bulletactive = 1; //Checking Bullet is active or not

    //Draw the bullet on screen
    void Bulletfire(int x, int y, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        //source rectangle denoting the texture or image source
        srcRect.x = 0; //source x position
        srcRect.y = 0; // source y position

        //getting source height and width
        SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);

        //destination rectangle
        desRect.w = 24;
        desRect.h = 8;

        if (firsttime == 0) //Checking Firsttime bullet started rendering
        {
            psi_x = x;
            psi_y = y;
            firsttime = 1;
        }
        //Updating Position
        desRect.x = psi_x;
        desRect.y = psi_y;

        //Rendering or display
        if (bulletactive)
            SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
    }
    void update(int dir, int damage) //Updating Bullet Position
    {

        if (bulletactive)
        {
            psi_x += (dir)*bvelocity * delta_time; //x position updated
            desRect.x = (int)psi_x;

            psi_y += 0 * bvelocity * delta_time; //updating y position
            desRect.y = (int)psi_y;

            //Getting position of player
            int posx = p1.ReturnPositionx();
            int posy = p1.ReturnPositiony();

            //Checking if player hit
            if (psi_x >= posx && psi_x <= posx + 160 * 0.75 && psi_y >= posy && psi_y <= posy + 180 * 0.75)
            {
                bulletactive = 0;      //deactivate bullet
                if (!shield)           //Checking Shield active or not
                    phealth -= damage; //health decrease according to damage
                if (phealth <= 0)      //if player health less then 0
                    gameover = 1;      //gameover
                return;
            }
        }
    }

} EBullet;

#endif