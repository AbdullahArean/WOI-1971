#ifndef ENEMY_H
#define enemy_H

#include "constants.h"





// //Defining a function to find out the maximum of 2 numbers(i.e. positions)
// double max(double a, double b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }

// //Defining a function to find out the minimum of 2 numbers(i.e. positions)
// double min(double a, double b)
// {
//     if (a < b)
//         return a;
//     else
//         return b;
// }
typedef struct Enemy{
    //Global Variables
SDL_Rect srcRect;
SDL_Rect desRect;
double psi_x;
double psi_y;
    //Draw
    void draw(int x, int y, int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        // Simple dimension calculation
        srcRect.x = 0;
        srcRect.y = 0;
        SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);
        desRect.w = width;
        desRect.h = height;
        desRect.x = x;
        desRect.y = y;
        SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
        //SDL_RenderPresent(pRenderer);
    }
    
    // //Creating a rectangle shape and Event Handling for a Enemy object
    // void EnemyMoves(int rect_Height, int rect_Width, int rect_x, int rect_y, SDL_Event event)
    // {
    //     SDL_Rect e_rect;

    //     // struct to hold the size of the sprite
    //     //SDL_Rect e_rect;
    //     e_rect.w = desRect.w;
    //     e_rect.h = desRect.h;
    //     e_rect.x = desRect.x;
    //     e_rect.y = desRect.y;

    //     //Defining the velocity with which the enemy will move
    //     float vel_x = FPS / 12;
    //     float vel_y = FPS / 12;

    //     //defining the position(current) of the sprite which is changable according to some conditions
    //     double posi_x = e_rect.x;
    //     double posi_y = e_rect.y;

    //     int gameover = 0;
    //     while (game_running) //game_running = 1 [initially (from constant.h)]
    //     {
    //         if (gameover == 0)
    //         {
    //             e_rect.x = (int)posi_x;
    //             e_rect.y = (int)posi_y;

    //             //Lower boundary to the left which the enemy won't cross
    //             if (posi_x <= 940)
    //             {
    //                 posi_x = 940;
    //                 vel_x = -vel_x;
    //             }

    //             //Lower boundary to the up/above which the enemy won't cross
    //             if (posi_y <= 600)
    //             {
    //                 posi_y = 600;
    //                 vel_y = -vel_y;
    //             }

    //             //Higher boundary to the right which the enemy won't cross
    //             if (posi_x >= WINDOW_WIDTH - e_rect.w)
    //             {
    //                 posi_x = WINDOW_WIDTH - e_rect.w;
    //                 vel_x = -vel_x;
    //             }

    //             ////Higher boundary to the bottom/down which the enemy won't cross
    //             if (posi_y >= WINDOW_HEIGHT - e_rect.h)
    //             {
    //                 posi_y = WINDOW_HEIGHT - e_rect.h;
    //                 vel_y = -vel_y;
    //             }
    //         }
    //     }
    // }

} Enemy;

#endif