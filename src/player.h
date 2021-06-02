// #ifndef PLAYER_H
// #define PLAYER_H

// #include "constants.h"

// SDL_Rect dest_rect;

// extern SDL_Window* window;

// //Defining a function to find out the maximum of 2 numbers(i.e. positions)
// double max(double a, double b)
// {
//     if(a > b)
//         return a;
//     else
//         return b;
// }

// //Defining a function to find out the minimum of 2 numbers(i.e. positions)
// double min(double a, double b)
// {
//     if(a < b)
//         return a;
//     else
//         return b;
// }

// // //A function to find out the maximum of 2 numbers(i.e. positions)
// // double max(double a, double b);

// // //A function to find out the minimum of 2 numbers(i.e. positions)
// // double min(double a, double b);

// //Defining a structure for Player-Object
// typedef struct PlayerObject{

//     // // loading the image of the player
//     // void PlayerLoad(SDL_Surface* surface, const char* path, SDL_Texture* texture, SDL_Renderer* rend);

//     // //Creating a rectangle shape and Event Handling for a Player object
//     // void PlayerMoves(int rect_height, int rect_width, int rect_x_pos, int rect_y_pos, SDL_Event event);

//     // loading the image to the RAM
//     void load(SDL_Surface *surface, const char *path, SDL_Texture *texture, SDL_Renderer *rend)
//     {
//         //Loading the image by using IMG_Load
//         surface = IMG_Load(path);

//         //Checking whether we are successful to create a surface to load an image
//         if (!surface)
//         {
//             printf("Surface Error: %s\n", SDL_GetError());//Printing a error message with specification
//             Clean(window, rend);
//             return;
//         }

//         // loading the image data into the graphics hardware's memory from the RAM
//         texture = SDL_CreateTextureFromSurface(rend, surface);
//         SDL_FreeSurface(surface);//Freeing the surface

//         //Checking whether we are successful to create a texture or not
//         if (!texture)
//         {
//             printf("Texture Error: %s\n", SDL_GetError());//Printing a error message with specification
//             Clean(window, rend);
//             return;
//         }
//     }

//     //Drawing a rectangular shape of the Player object as well as Event Handling
//     void PlayerMoves(int rect_height, int rect_width, int rect_x_pos, int rect_y_pos, SDL_Event event)
//     {
//         // struct to hold the position and size of the sprite
//         //SDL_Rect dest_rect;
//         dest_rect.h = rect_height;
//         dest_rect.w = rect_width;
//         dest_rect.x = rect_x_pos;
//         dest_rect.y = rect_y_pos;
//         double psi_x;
//         double psi_y;

//         //Handling Event (i.e. Keyboard Event Handling)
//         while (SDL_PollEvent(&event))
//         {
//             switch (event.type)
//             {
//             case SDL_QUIT:
//                 //close = 1;
//                 break;
//             case SDL_KEYDOWN:
//                 switch (event.key.keysym.scancode)
//                 {
//                 case SDL_SCANCODE_LEFT:
//                     psi_x = max(0,psi_x - FPS/10);
//                     break;
//                 case SDL_SCANCODE_RIGHT:
//                     psi_x = min(940 - dest_rect.x, psi_x + FPS/10);
//                     break;
//                 case SDL_SCANCODE_UP:
//                     psi_y = max(400, psi_y - FPS/10);
//                     break;
//                 case SDL_SCANCODE_DOWN:
//                     psi_y = min(600, psi_y + FPS/10);
//                     break;
//                 default:
//                     break;
//                 }
//             }
//         }
//         dest_rect.x = (int) psi_x;
//         dest_rect.y = (int) psi_y;
//     }

// }Player;

// #endif

#ifndef PLAYER_H
#define PLAYER_H

//Preprocessors
#include "constants.h"
#include "clean.h"

//SDL_Rect dest_rect;
//Two SDL Rectangle
SDL_Rect srcRect;
SDL_Rect desRect;
double psi_x;
double psi_y;

//Defining a function to find out the maximum of 2 numbers(i.e. positions)
double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}

//Defining a function to find out the minimum of 2 numbers(i.e. positions)
double min(double a, double b)
{
    if (a < b)
        return a;
    else
        return b;
}

typedef struct PlayerObject
{

    SDL_Texture *ReturnPlayerTexture(const char *fileName, SDL_Renderer *pRenderer)
    {
        SDL_Surface *surface = IMG_Load(fileName); //Loading image as SDL Surface
        if (!surface)
        {
            printf("Error Creating Surface\n");
            return NULL;
        }
        // load the image data into the graphics hardware's memory
        SDL_Texture *playertexture = SDL_CreateTextureFromSurface(pRenderer, surface);
        SDL_FreeSurface(surface);
        if (!playertexture)
        {
            printf("Error Creating Texture: %s\n", SDL_GetError());
            return NULL;
        }
        return playertexture;
    }

    //Draw
    void draw(int x, int y, int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        // Simple dimension calculation
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = desRect.w = width;
        srcRect.h = desRect.h = height;
        desRect.x = x;
        desRect.y = y;
        SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, flip);
        //SDL_RenderPresent(pRenderer);
    }
    //SDL_RenderPresent(pRenderer);
    void PlayerUpdate()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                game_running = FALSE;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_LEFT:
                    psi_x = max(0, psi_x - FPS / 10);
                    break;
                case SDL_SCANCODE_RIGHT:
                    psi_x = min(940 - desRect.x, psi_x + FPS / 10);
                    break;
                case SDL_SCANCODE_UP:
                    psi_y = max(400, psi_y - FPS / 10);
                    break;
                case SDL_SCANCODE_DOWN:
                    psi_y = min(600, psi_y + FPS / 10);
                    break;
                default:
                    break;
                }
            }
        }
        desRect.x = (int)psi_x;
        desRect.y = (int)psi_y;
    }
    //Event handling(#Keyboard Event Handling)

} Player;

#endif