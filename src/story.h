#ifndef STORY_H
#define STORY_H

#include "constants.h"
#include"texturemanager.h"

//Key tracker variable
int sp=0;

TextureManager TMstory;
void sinit()
{
    
}
void srender()
{
    TMstory.drawsame(0, 0, storyback, renderer);
    if(sp==15) {TMstory.drawsame(405, 20, mainmenup, renderer); StoryScript = 0;}
    else TMstory.drawsame(405, 20, mainmenu, renderer);
    sp=0;
}

void supdate()
{

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {

        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 10 && mousey <= 20 + 91)
        {
            sp=15;

            
        }
    }
}
#endif