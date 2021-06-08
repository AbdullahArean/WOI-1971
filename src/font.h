#ifndef FONT_H
#define FONT_H
 
#include "constants.h"
 
TTF_Font *font;
 
typedef struct FontManager{
 
   //Loading the font
   SDL_Texture *Loadfont(SDL_Renderer *txt_render, const char* font_path, int font_size, const char* txt_msg, SDL_Color txt_color)
   {
       font = TTF_OpenFont(font_path, font_size);
       if(!font)
       {
           printf("Font Error: %s\n", TTF_GetError());
           return NULL;
       }
 
       SDL_Surface* txt_surface = TTF_RenderText_Solid(font, txt_msg, txt_color);
       if(!txt_surface)
       {
           printf("Text Surface Error: %s\n", TTF_GetError());
           return NULL;
       }
 
       SDL_Texture* txt_texture = SDL_CreateTextureFromSurface(txt_render, txt_surface);
       if(!txt_texture)
       {
           printf("Text Texture Error: %s\n",TTF_GetError());
           return NULL;    
       }
 
       SDL_FreeSurface(txt_surface);
 
       return txt_texture;
   }
 
   //Displaying the font
   void display(int x, int y, SDL_Renderer* txt_render, SDL_Texture* txt_texture)
   {
       SDL_Rect txt_rect;
       txt_rect.x = x;
       txt_rect.y = y;
       SDL_QueryTexture(txt_texture, NULL, NULL, &txt_rect.w, &txt_rect.h);
       SDL_RenderCopy(txt_render, txt_texture, NULL, &txt_rect);
   }
}Font;
 
 
#endif
