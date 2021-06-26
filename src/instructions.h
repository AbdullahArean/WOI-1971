#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
 
#include "constants.h"


extern SDL_Renderer *renderer; 
 
void instruction(int x, int y, const char *pfont, int fsize, const char *message)
{
   SDL_Texture *instruct_tex = NULL;
   SDL_Color ins_color = {255, 0 , 0 , 255};
   Font instr;
   instruct_tex = instr.Loadfont(renderer, pfont , fsize, message, ins_color);
   instr.display(x, y, renderer, instruct_tex);
}

#endif