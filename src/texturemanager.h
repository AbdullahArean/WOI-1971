#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

//Preprocessors
#include "constants.h"

typedef struct TextureManager
{

    SDL_Texture *ReturnTexture( const char *fileName, SDL_Renderer *pRenderer)
    {
        SDL_Surface *surface = IMG_Load(fileName); //Loading image as SDL Surface
        if (!surface)
        {
            printf("Error Creating Surface\n");
            return NULL;
        }
        // load the image data into the graphics hardware's memory
        SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, surface);
        SDL_FreeSurface(surface);
        if (!texture)
        {
            printf("Error Creating Texture: %s\n", SDL_GetError());
            return NULL;
        }
        return texture;
    }
    //Draw
    void draw(int x, int y, int width, int height, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {

        //Two SDL Rectangle
        SDL_Rect srcRect;
        SDL_Rect desRect;

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
    //Draw
    void drawsame(int x, int y, SDL_Texture *pTexture, SDL_Renderer *pRenderer)
    {
        //Two SDL Rectangle
        SDL_Rect srcRect;
        SDL_Rect desRect;
        SDL_QueryTexture(pTexture, NULL, NULL, &srcRect.w, &srcRect.h);
        // Simple dimension calculation
        srcRect.x = 0;
        srcRect.y = 0;
        desRect.w = srcRect.w;
        desRect.h = srcRect.h;
        desRect.x = x;
        desRect.y = y;
        SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &desRect, 0, 0, SDL_FLIP_NONE);
    }

    void drawFrame(int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Texture *pTexture, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
    {
        SDL_Rect srcRect;
        SDL_Rect destRect;

        //Simple Dimension Calculation
        //We need to update currentFrame and CurrentRow for animation in update function
        srcRect.x = width * currentFrame;
        srcRect.y = height * (currentRow - 1);

        srcRect.w = destRect.w = width;
        srcRect.h = destRect.h = height;
        destRect.x = x;
        destRect.y = y;

        SDL_RenderCopyEx(pRenderer, pTexture, &srcRect, &destRect, 0, 0, flip);
    }
    

} TextureManager;
#endif