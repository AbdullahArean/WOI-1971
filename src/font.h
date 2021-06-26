//Using Guards
#ifndef FONT_H
#define FONT_H

//User Defined Header File Included
#include "constants.h"

//True Type Font structure(Built-in) variable declared
TTF_Font *font;

//A Structure is made for managing the font
typedef struct FontManager
{

    //Loading the font
    SDL_Texture *Loadfont(SDL_Renderer *txt_render, const char *font_path, int font_size, const char *txt_msg, SDL_Color txt_color)
    {
        font = TTF_OpenFont(font_path, font_size); //Opening the font
        if (!font)
        {
            printf("Font Error: %s\n", TTF_GetError()); //Printing the Error message if the font can't be opened
            return NULL;                                //Returning NULL if the font can't be opened
        }

        //Loading the message according to the font along with color in RAM
        SDL_Surface *txt_surface = TTF_RenderText_Solid(font, txt_msg, txt_color);
        if (!txt_surface)
        {
            printf("Surface Error: %s\n", TTF_GetError()); //Printing the Error message if the surface can't be loaded
            return NULL;                                   //Returning NULL if the surface can't be loaded
        }
        //Loading the surface to the graphics memory
        SDL_Texture *txt_texture = SDL_CreateTextureFromSurface(txt_render, txt_surface);
        if (!txt_texture)
        {
            printf("Text Texture Error: %s\n", TTF_GetError()); //Printing the Error message if the texture can't be loaded
            return NULL;                                        //Returning NULL if the texture can't be loaded
        }
        //Freeing the surface
        SDL_FreeSurface(txt_surface);

        return txt_texture; //Returning the texture which has loaded the message along with the font in graphics memory
    }

    //A Function for Displaying the font
    void display(int x, int y, SDL_Renderer *txt_render, SDL_Texture *txt_texture)
    {
        SDL_Rect txt_rect;                                                   //Declaring SDL_Rect structure variable
        txt_rect.x = x;                                                      //x position of the rectange which contains the font
        txt_rect.y = y;                                                      //y position of the rectange which contains the font
        SDL_QueryTexture(txt_texture, NULL, NULL, &txt_rect.w, &txt_rect.h); //defining the auto hight and width of the rectangle
        SDL_RenderCopy(txt_render, txt_texture, NULL, &txt_rect);            //Copying the renderer
        TTF_CloseFont(font);                                                     //Closing the font
    }
} Font;

#endif