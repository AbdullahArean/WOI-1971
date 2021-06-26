//Using Guards
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
 
//User Defined Header File Included 
#include "constants.h"

//only declaring the 
extern SDL_Renderer *renderer; 
 
//Function to show the instructions by using font
void instruction(int x, int y, const char *pfont, int fsize, const char *message)
{
   SDL_Texture *instruct_tex = NULL;//Initializing the texture by NULL
   SDL_Color ins_color = {219, 112 , 147 , 255};//defining a color
   Font instr;//defining a font structure variable
   instruct_tex = instr.Loadfont(renderer, pfont , fsize, message, ins_color);//loading the font to the texture
   instr.display(x, y, renderer, instruct_tex);//Desplaying the font
}

//Function to show the messages by using font when level will be completed individually
void message(int x, int y, const char *pfont, int fsize, const char *message)
{
   SDL_Texture *instruct_tex = NULL;//Initializing the texture by NULL
   SDL_Color ins_color = {255,0,0, 255};//defining a color
   Font instr;//defining a font structure variable
   instruct_tex = instr.Loadfont(renderer, pfont , fsize, message, ins_color);//loading the font to the texture
   instr.display(x, y, renderer, instruct_tex);//Desplaying the font
}
#endif