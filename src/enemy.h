#ifndef ENEMY_H
#define ENEMY_H


#include "constants.h"



typedef struct EnemyObject
{

    // // loading the image of the player
    // void EnemyLoad(SDL_Surface* surface, const char* path, SDL_Texture* texture, SDL_Renderer* rend);

    // //Creating a rectangle shape and Event Handling for a Player object
    // void EnemyMoves(int rect_height, int rect_width, int rect_x_pos, int rect_y_pos, SDL_Event event);

    // loading the image of the player
    void EnemyLoad(SDL_Surface *surface, const char *path, SDL_Texture *texture, SDL_Renderer *rend)
    {
        //Loading the image by using IMG_Load
        surface = IMG_Load(path);

        //Checking whether we are successful to create a surface to load an image
        if (!surface)
        {
            printf("Surface Error: %s\n", SDL_GetError()); //Printing a error message with specification
            Clean(window, rend);
            return;
        }

        // loading the image data into the graphics hardware's memory from the RAM
        texture = SDL_CreateTextureFromSurface(rend, surface);
        SDL_FreeSurface(surface); //Freeing the surface

        //Checking whether we are successful to create a texture or not
        if (!texture)
        {
            printf("Texture Error: %s\n", SDL_GetError()); //Printing a error message with specification
            Clean(window, rend);
            return;
        }
    }

    //Creating a rectangle shape and Event Handling for a Enemy object
    void EnemyMoves(int rect_Height, int rect_Width, int rect_x, int rect_y, SDL_Event event)
    {
        SDL_Rect e_rect;

        // struct to hold the size of the sprite
        //SDL_Rect e_rect;
        e_rect.w = rect_Width;
        e_rect.h = rect_Height;
        e_rect.x = rect_x;
        e_rect.y = rect_y;

        //Defining the velocity with which the enemy will move
        float vel_x = FPS / 12;
        float vel_y = FPS / 12;

        //defining the position(current) of the sprite which is changable according to some conditions
        double posi_x = e_rect.x;
        double posi_y = e_rect.y;

        int gameover = 0;
        while (game_running) //game_running = 1 [initially (from constant.h)]
        {
            if (gameover == 0)
            {
                e_rect.x = (int)posi_x;
                e_rect.y = (int)posi_y;

                //Lower boundary to the left which the enemy won't cross
                if (posi_x <= 940)
                {
                    posi_x = 940;
                    vel_x = -vel_x;
                }

                //Lower boundary to the up/above which the enemy won't cross
                if (posi_y <= 600)
                {
                    posi_y = 600;
                    vel_y = -vel_y;
                }

                //Higher boundary to the right which the enemy won't cross
                if (posi_x >= WINDOW_WIDTH - e_rect.w)
                {
                    posi_x = WINDOW_WIDTH - e_rect.w;
                    vel_x = -vel_x;
                }

                ////Higher boundary to the bottom/down which the enemy won't cross
                if (posi_y >= WINDOW_HEIGHT - e_rect.h)
                {
                    posi_y = WINDOW_HEIGHT - e_rect.h;
                    vel_y = -vel_y;
                }
            }
        }
    }

} Enemy;

#endif