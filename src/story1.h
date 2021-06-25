#ifndef STORY_H
#define STORY_H

#include "constants.h"
#include "texturemanager.h"
TextureManager TM7;
int mm=0;
void srender()
{
    TM7.drawsame(0, 0, storyback, renderer);

    
    if (mm == 1)
        {TM7.drawsame(405, 95, mainmenup, renderer); StoryScript=0;}
    else
        TM7.drawsame(405, 95, mainmenu, renderer);
    mm=0;
}

void supdate()
{

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {

        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= WINDOW_HEIGHT-95 && mousey <= WINDOW_HEIGHT-95 - 91)
        {
            printf("Pressed\n");
          mm=1;
        }
        
    }
}
#endif