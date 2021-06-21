#ifndef SETTINGS_H
#define SETTINGS_H

#include "constants.h"
#include "texturemanager.h"

TextureManager TM3;
void settingsinit()
{
    son = TM3.ReturnTexture("assets/son.png", renderer);
    sonp = TM3.ReturnTexture("assets/sonp.png", renderer);
    soff = TM3.ReturnTexture("assets/soff.png", renderer);
    soffp = TM3.ReturnTexture("assets/soffp.png", renderer);
    mainmenu = TM3.ReturnTexture("assets/mainmenu.png", renderer);
    mainmenup = TM3.ReturnTexture("assets/mainmenup.png", renderer);

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
        TM3.drawsame(405, 95, son, renderer);
    else
        TM3.drawsame(405, 95, sonp, renderer);
    if (keypressed == 22)
        TM3.drawsame(405, 217, soff, renderer);
    else
        TM3.drawsame(405, 217, soffp, renderer);
    if (keypressed == 18)
        TM3.drawsame(405, 339, mainmenu, renderer);
    else
        TM3.drawsame(405, 339, mainmenup, renderer);
    // if(keypressed==14) TM.drawsame(405, 461, settings, renderer);
    // else TM.drawsame(405, 461, settingsp, renderer);
    // if(keypressed==15) TM.drawsame(405, 583, story, renderer);
    // else TM.drawsame(405, 583, storyp, renderer);

    //  if(keypressed==11 || keypressed==12) gameplay=1;

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
                Mix_Music *bMusic2 = Mix_LoadMUS("assets/secondpage.mp3");
                Mix_PlayMusic(bMusic2, -1);
            }
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 217 && mousey <= 217 + 91)
        {
            Mix_HaltMusic();
            keypressed = 22;
            sound_state = 0;
            // TM.drawsame(405, 217, newgp, renderer);
            //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            //gameplay= 1; //change
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 339 && mousey <= 339 + 91)
        {
            keypressed = 18;
            //TM.drawsame(405, 339, hisp, renderer);
            //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
        }
        // if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 461 && mousey <= 461 + 91)
        // {
        //     Mix_HaltMusic();
        //     keypressed=14;
        //     //TM.drawsame(405, 461, settingsp, renderer);
        //     //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
        // }
        // if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 583 && mousey <= 583 + 91)
        // {
        //     Mix_HaltMusic();
        //     keypressed=15;
        //     //TM.drawsame(405, 583, storyp, renderer);
        //     //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
        //     StoryScript = 1;
        // }
    }
}
#endif