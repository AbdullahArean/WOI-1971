#ifndef ENEMY_H
#define ENEMY_H

#include "constants.h"
#include "ebullet.h"

typedef struct Enemy //enemy structure
{

EBullet b2[10000];
    //Rectangle to keep track
    SDL_Rect srcRect;
    SDL_Rect desRect;

    
    int health = 100; //denoting enemy health
    bool dead = 0;    //denoting enemy is dead or not

    double psi_x = WINDOW_WIDTH - 160;         //position of x axis
    double psi_y = WINDOW_HEIGHT - 180 - row3; //position of x axis

    double x_vel = 0.0; //velocity of x axis
    double y_vel = 0.0; //velocity of y axis

    int keeptrack = 0;
    bool ft = 0, ff=0; 
    int enemybulletno = 0;

    //bool ft = 0; //used in update function to check if this is the first update or not

    //render or draw 
    void EnemyRender(int x, int y, int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        if (!dead) //checking if dead or not
        {
             if (!ff)
            {
            
                keeptrack = SDL_GetTicks();
                ff = 1;
            }
            // source y position
            srcRect.x = 0; //source x position
            srcRect.y = 0;// source y position

            //getting source height and width
            SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);

            //destination rectangle 
            desRect.x = psi_x;
            desRect.y = psi_y;

            desRect.w = width;
            desRect.h = height;


            SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
            if ((int)(SDL_GetTicks() - keeptrack) >= einterval)
            {
                enemybulletno++;
                keeptrack = SDL_GetTicks();
            }
            for (int i = 0; i < enemybulletno; i++)
            {
                b2[i].Bulletfire(psi_x, psi_y + 34*0.80, bu1, renderer, SDL_FLIP_NONE);
            }
        }
        //SDL_RenderPresent(pRenderer);
    }
    void enemyupdate(double row, double v_vel)
    {
        // update positions
        if (!dead)
        {
            if (ft == 0)
            {
                x_vel = v_vel;
                ft = 1;
            }
            psi_x -= x_vel * delta_time; 
            psi_y -= y_vel * delta_time; 

            // collision detection with bounds
            if (psi_x >= WINDOW_WIDTH - desRect.w)
            {
                psi_x = WINDOW_WIDTH - desRect.w;
                x_vel = (-1) * x_vel;
            }
            if (psi_y > WINDOW_HEIGHT - desRect.h)
                psi_y = WINDOW_HEIGHT - desRect.h;
            if (psi_x < WINDOW_WIDTH / 2 - desRect.w)
            {
                psi_x = WINDOW_WIDTH / 2 - desRect.w;
                x_vel = (-1) * x_vel;
            }
            if (psi_y < WINDOW_HEIGHT - desRect.h - row)
                psi_y = WINDOW_HEIGHT - desRect.h - row;

            // set the positions in the struct
            desRect.x = (int)psi_x;
            desRect.y = (int)psi_y;
            
            //Bullet Firing
            for (int i = 0; i < enemybulletno; i++)
            {
                b2[i].update(-1,10);
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
        else
            return -1;
    }
    int ReturnPositiony()
    {
        if (!dead)
        {
            return psi_y;
        }
        else
            return -1;
    }
} Enemy;

#endif