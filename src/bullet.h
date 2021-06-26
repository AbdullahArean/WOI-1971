#ifndef BULLET_H
#define BULLET_H

//User Defined Header File Included
#include "constants.h"

typedef struct Bullet //Player Bullet structure
{
    //Rectangle to keep track
    SDL_Rect srcRect; //Source rectangle
    SDL_Rect desRect; //Destination rectangle

    //Scoring Variable
    double psi_x = 0.00;   //position in x axis
    double psi_y = 0.00;   //position in y axis
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
            if (sound_state)
            {
                Mix_Chunk *bullet = Mix_LoadWAV("assets/gunshot.wav");
                Mix_PlayChannel(-1, bullet, 0); //Playing Sound Effect
            }
            firsttime = 1;
        }
        //Updating Position
        desRect.x = psi_x;
        desRect.y = psi_y;

        //Rendering or display
        if (bulletactive)
            SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
    }
    void update(int dir) //Updating Bullet Position
    {

        if (bulletactive)
        {
            psi_x += (dir)*bvelocity * delta_time; //x position updated
            desRect.x = (int)psi_x;

            psi_y += 0 * bvelocity * delta_time; //updating y position
            desRect.y = (int)psi_y;

            //Checking if any Enemy Hit
            for (int i = 0; i < EnemyNumber; i++) //Checking Every Enemy one by one
            {
                int eposx = e1[i].ReturnPositionx(); //Getting x position of enemy
                int eposy = e1[i].ReturnPositiony(); //Getting y position of enemy

                //Checking if the bullet hit or not
                if (psi_x >= eposx && psi_x <= eposx + 160 * 0.80 && psi_y >= eposy && psi_y <= eposy + 180 * 0.80)
                {
                    bulletactive = 0;       //if hit then deactivate the bullet
                    pscore += 10;           //player score increase
                    e1[i].updatehealth(-1); //enemy health decrease
                    return;
                }
            }
            //Checking if any Tank Hit
            for (int i = 0; i < TankNumber; i++) //Checking Every Tank one by one
            {
                int tposx = t1[i].ReturnPositionx(); //Getting x position
                int tposy = t1[i].ReturnPositiony(); //Getting y position
                //Checking if the bullet hit or not
                if (psi_x >= tposx && psi_x <= tposx + 300 * 0.80 && psi_y >= tposy && psi_y <= tposy + 180 * 0.80)
                {
                    bulletactive = 0;       //if hit then deactivate the bullet
                    pscore += 20;           //player score increase
                    t1[i].updatehealth(-1); //enemy health decrease
                    return;
                }
            }
            for (int i = 0; i < InnocentNumber; i++) //Checking Every Innocent one by one
            {
                int iposx = i1[i].ReturnPositionx(); //Getting x position
                int iposy = i1[i].ReturnPositiony(); //Getting y position
                //Checking if the bullet hit or not
                if (psi_x >= iposx && psi_x <= iposx + 160 * 0.80 && psi_y >= iposy && psi_y <= iposy + 180 * 0.80)
                {
                    bulletactive = 0;       //if hit then deactivate the bullet
                    phealth -= 10;          //Player Health Decrease
                    i1[i].updatehealth(-1); //Enemy Health Decrease
                    return;
                }
            }
        }
    }

} Bullet;

#endif