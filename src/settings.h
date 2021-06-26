#ifndef SETTINGS_H
#define SETTINGS_H

#include "constants.h"
#include "texturemanager.h"

TextureManager TM3;
void settingsinit()
{
    
    //Playing the music for 1st page according to the state of Sound System
    if (sound_state)
    {
        Mix_Music *bMusic2 = Mix_LoadMUS("assets/secondpage.mp3");
        Mix_PlayMusic(bMusic2, -1);
    }
}
void settingsrender()
{
    TM3.drawsame(0, 0, bg, renderer);

    if (keypressed == 21)
        TM3.drawsame(405, 95, sonp, renderer);
    else
        TM3.drawsame(405, 95, son, renderer);
    if (keypressed == 22)
        TM3.drawsame(405, 217, soffp, renderer);
    else
        TM3.drawsame(405, 217, soff, renderer);
    if (keypressed == 18)
        TM3.drawsame(405, 339, mainmenup, renderer);
    else
        TM3.drawsame(405, 339, mainmenu, renderer);
    keypressed = 19;
}

void settingsupdate()
{

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {

        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 95 && mousey <= 95 + 91)
        {
            keypressed = 21;
            sound_state = 1;
            if (sound_state)
            {
                Mix_Chunk *click = Mix_LoadWAV("assets/button.wav");
                Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            }
            if (sound_state)
            {
                Mix_Music *bMusic2 = Mix_LoadMUS("assets/secondpage.mp3");
                Mix_PlayMusic(bMusic2, -1);
            }

        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 217 && mousey <= 217 + 91)
        {
            Mix_HaltMusic();
            keypressed = 22;
            sound_state = 0;
            if (sound_state)
            {
                Mix_Chunk *click = Mix_LoadWAV("assets/button.wav");
                Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            }
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 339 && mousey <= 339 + 91)
        {
            keypressed = 18;
            if (sound_state)
            {
                Mix_Chunk *click = Mix_LoadWAV("assets/button.wav");
                Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            }
        }
        
    }
}
#endif