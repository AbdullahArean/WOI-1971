#ifndef LASTPAGE_H
#define LASTPAGE_H

#include "constants.h"
#include "texturemanager.h"
int lkeypressed = 0;
TextureManager TM5;
void lastpageinit()
{
    re = TM5.ReturnTexture("assets/replay.png", renderer);
    sa = TM5.ReturnTexture("assets/savescore.png", renderer);
    rep = TM5.ReturnTexture("assets/replayp.png", renderer);
    sap = TM5.ReturnTexture("assets/savescorep.png", renderer);

    //Playing the music for 1st page according to the state of Sound System
    if (sound_state)
    {
        Mix_Music *bMusic2 = Mix_LoadMUS("assets/secondpage.mp3");
        Mix_PlayMusic(bMusic2, -1);
    }
}
void lastpagerender()
{
    TM5.drawsame(0, 0, bg, renderer);

    if (lkeypressed == 11)
        TM5.drawsame(405, 95, rep, renderer);
    else
        TM5.drawsame(405, 95, re, renderer);
    if (lkeypressed == 12)
    {
        TM5.drawsame(405, 217, nextlevelp, renderer); //start gameplay
        gamelevel++;
        shieldnumber++;
        sn=0;
        phealth+=10;
        gameover=0;
    }
    else
        TM5.drawsame(405, 217, nextlevel, renderer);
        
    if (lkeypressed == 13)
        TM5.drawsame(405, 339, sap, renderer);
    else
        TM5.drawsame(405, 339, sa, renderer);
    if (lkeypressed == 14)
    {
        game_running = 0;
        TM5.drawsame(405, 461, exip, renderer);
    }
    else
        TM5.drawsame(405, 461, exi, renderer);

    lkeypressed = 0;
}

void lupdate()
{

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {

        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 95 && mousey <= 95 + 91)
        {
            Mix_HaltMusic();
            lkeypressed = 11;
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 217 && mousey <= 217 + 91)
        {
            Mix_HaltMusic();
            lkeypressed = 12;
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 339 && mousey <= 339 + 91)
        {
            //Mix_HaltMusic();
            lkeypressed = 13;
            //TM.drawsame(405, 339, hisp, renderer);
            //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 461 && mousey <= 461 + 91)
        {
            Mix_HaltMusic();
            lkeypressed = 14;
            //TM.drawsame(405, 461, settingsp, renderer);
            //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
        }
    }
}
#endif