#ifndef PAUSE_H
#define PAUSE_H

//User Defined Header File Included
#include "constants.h"
#include "texturemanager.h"

//Variable to track key pressed
int pkeypressed = 0;

//texture manager declared
TextureManager TM4;
void painit()
{
    //Playing the music for 1st page according to the state of Sound System
    if (sound_state)
    {
        Mix_Music *bMusic2 = Mix_LoadMUS("assets/secondpage.mp3");
        Mix_PlayMusic(bMusic2, -1);
    }
}
void parender()
{
    TM4.drawsame(0, 0, bg, renderer);

    if (pkeypressed == 31)
    {
        TM4.drawsame(405, 95, conp, renderer);
        pause = 0;
    }
    else
        TM4.drawsame(405, 95, con, renderer);
    if (pkeypressed == 32)
    {
        TM4.drawsame(405, 217, exip, renderer);
        game_running = 0;
    }
    else
        TM4.drawsame(405, 217, exi, renderer);
    if (pkeypressed == 33)
    {
        TM4.drawsame(405, 339, mainmenup, renderer);
        gameplay = 0;
        pause = 0;
    }
    else
        TM4.drawsame(405, 339, mainmenu, renderer);

    pkeypressed = 0;
}

void paupdate()
{

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {

        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 95 && mousey <= 95 + 91)
        {
            pkeypressed = 31;
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 217 && mousey <= 217 + 91)
        {
            pkeypressed = 32;
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 339 && mousey <= 339 + 91)
        {
            pkeypressed = 33;
        }
    }
}
#endif