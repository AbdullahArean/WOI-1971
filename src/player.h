#ifndef PLAYER_H
#define PLAYER_H

#include "constants.h"
#include "texturemanager.h"

TextureManager sh;
typedef struct Player
{

    //Global Variables
    SDL_Rect srcRect;
    SDL_Rect desRect;

    //Scoring Variable
    int health = 100;
    bool dead = 0;

    double psi_x = 0;
    double psi_y = 520;

    double x_vel = 0;
    double y_vel = 0;

    int keeptracksh = 0;
    bool fs;

    //Draw
    void playerrender(int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        if (!dead)
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

            if (shield && fs == 0)
            {
                fs = 1;
                keeptracksh = SDL_GetTicks();
                sn++;
                printf("Shield remaining==>%d\n ", shieldnumber - sn);
            }
            if (shield && keeptracksh && (SDL_GetTicks() - keeptracksh) >= 5000)
            {
                keeptracksh = 0;
                shield = 0;
                fs = 0;
            }
            if (shield == 1)
            {
                sh.draw(psi_x + 180, psi_y, 20, 180, newg, renderer, SDL_FLIP_HORIZONTAL);
            }
        }
    }

    void playerupdate()
    {
        if (!dead)
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
            psi_x += x_vel * delta_time; //x_vel ;// 60;
            psi_y += y_vel * delta_time; //y_vel;// 60;

            if (psi_x <= 0)
                psi_x = 0;
            if (psi_y <= 0)
                psi_y = 0;
            if (psi_x >= WINDOW_WIDTH / 2 - desRect.w)
                psi_x = WINDOW_WIDTH / 2 - desRect.w;
            if (psi_y <= WINDOW_HEIGHT - desRect.h - row3 - 50)
                psi_y = WINDOW_HEIGHT - desRect.h - row3 - 50;
            if (psi_y >= WINDOW_HEIGHT - desRect.h - row1)
                psi_y = WINDOW_HEIGHT - desRect.h - row1;

            // set the positions in the struct
            desRect.x = (int)psi_x;
            desRect.y = (int)psi_y;
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
} Player;

#endif