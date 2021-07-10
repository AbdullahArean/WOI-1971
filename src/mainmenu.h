#ifndef MAINMENU_H
#define MAINMENU_H

#include "constants.h"
#include "highscore.h"
#include "texturemanager.h"

TextureManager TM;
void mainmenuinit()
{
    bg = TM.ReturnTexture("assets/buttonbackground.png", renderer);
    con = TM.ReturnTexture("assets/continue.png", renderer);
    newg = TM.ReturnTexture("assets/newgame.png", renderer);
    his = TM.ReturnTexture("assets/highscore.png", renderer);
    settings = TM.ReturnTexture("assets/settings.png", renderer);
    story = TM.ReturnTexture("assets/story.png", renderer);
    conp = TM.ReturnTexture("assets/continuepressed.png", renderer);
    newgp = TM.ReturnTexture("assets/newgamepressed.png", renderer);
    hisp = TM.ReturnTexture("assets/highscorep.png", renderer);
    settingsp = TM.ReturnTexture("assets/settingsp.png", renderer);
    storyp = TM.ReturnTexture("assets/storyp.png", renderer);
    storyback = TM.ReturnTexture("assets/storyb.png", renderer);
    nextlevel = TM.ReturnTexture("assets/nextlevel.png", renderer);
    nextlevelp = TM.ReturnTexture("assets/nextlevelp.png", renderer);
    gbg = TM.ReturnTexture("assets/gameback.png", renderer);
    p1t = TM.ReturnTexture("assets/hero.png", renderer);
    e1t = TM.ReturnTexture("assets/enemy2.png", renderer);
    e2t = TM.ReturnTexture("assets/enemy1.png", renderer);
    i1t = TM.ReturnTexture("assets/innocent.png", renderer);
    t1t = TM.ReturnTexture("assets/tank1.png", renderer);
    bu = TM.ReturnTexture("assets/bu.png", renderer);
    bu1 = TM.ReturnTexture("assets/bu1.png", renderer);
    shie = TM.ReturnTexture("assets/shield.png", renderer);
    exi = TM.ReturnTexture("assets/exit.png", renderer);
    exip = TM.ReturnTexture("assets/exitp.png", renderer);
    mainmenu = TM.ReturnTexture("assets/mainmenu.png", renderer);
    mainmenup = TM.ReturnTexture("assets/mainmenup.png", renderer);
    re = TM.ReturnTexture("assets/replay.png", renderer);
    sa = TM.ReturnTexture("assets/savescore.png", renderer);
    rep = TM.ReturnTexture("assets/replayp.png", renderer);
    sap = TM.ReturnTexture("assets/savescorep.png", renderer);
    son = TM.ReturnTexture("assets/son.png", renderer);
    sonp = TM.ReturnTexture("assets/sonp.png", renderer);
    soff = TM.ReturnTexture("assets/soff.png", renderer);
    soffp = TM.ReturnTexture("assets/soffp.png", renderer);
    mainmenu = TM.ReturnTexture("assets/mainmenu.png", renderer);
    mainmenup = TM.ReturnTexture("assets/mainmenup.png", renderer);

    //Playing the music for 1st page according to the state of Sound System

    Mix_Music *bMusic1 = Mix_LoadMUS("assets/firstpage.mp3");
    Mix_PlayMusic(bMusic1, -1);

    //First Page Load
    fpage = TM.ReturnTexture("assets/woinewhomepage.png", renderer);
    TM.draw(0, 0, 1080, 720, fpage, renderer, SDL_FLIP_NONE);
    SDL_RenderPresent(renderer);
    SDL_Delay(9000);
    Mix_HaltMusic(); //Stopping the 1st page music

    //Playing the music for 1st page according to the state of Sound System
    if (sound_state)
    {
        Mix_Music *bMusic2 = Mix_LoadMUS("assets/secondpage.mp3");
        Mix_PlayMusic(bMusic2, -1);
    }
}
void mainmenurender()
{
    TM.drawsame(0, 0, bg, renderer);

    if (keypressed == 11)
        TM.drawsame(405, 95, conp, renderer);
    else
        TM.drawsame(405, 95, con, renderer);
    if (keypressed == 12)
        TM.drawsame(405, 217, newgp, renderer);
    else
        TM.drawsame(405, 217, newg, renderer);
    if (keypressed == 13)
    {
        TM.drawsame(405, 339, hisp, renderer);
    } //highscoreshow();}
    else
        TM.drawsame(405, 339, his, renderer);
    if (keypressed == 20)
        TM.drawsame(405, 461, settingsp, renderer);
    else
        TM.drawsame(405, 461, settings, renderer);
    if (keypressed == 15)
    {
        TM.drawsame(405, 583, storyp, renderer);
        StoryScript = 1;
    }
    else
        TM.drawsame(405, 583, story, renderer);

    if (keypressed == 11 || keypressed == 12)
        {gameplay = 1;if (sound_state )
        {
            Mix_Music *bMusic3 = Mix_LoadMUS("assets/gameplay.mp3");
            Mix_PlayMusic(bMusic3, -1);
        }
        }

    keypressed = 0;
}

void mainmenuupdate()
{

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {

        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 95 && mousey <= 95 + 91)
        {
            Mix_HaltMusic();
            keypressed = 11;
            //TM.drawsame(405, 95, conp, renderer);
            if (sound_state)
            {
                Mix_Chunk *click = Mix_LoadWAV("assets/button.wav");
                Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            }
            if (sound_state)
            {
                Mix_Chunk *horn = Mix_LoadWAV("assets/HornAmbience.wav");
                Mix_PlayChannel(-1, horn, 0); //Playing Sound Effect
            }
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 217 && mousey <= 217 + 91)
        {
            Mix_HaltMusic();
            keypressed = 12;
            // TM.drawsame(405, 217, newgp, renderer);
            if (sound_state)
            {
                Mix_Chunk *click = Mix_LoadWAV("assets/button.wav");
                Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            }
            //gameplay= 1; //change
            int duration = 1500; //Timespare per milisecond
            SDL_RenderClear(renderer);
            TM.drawsame(0, 0, bg, renderer);
            instruction(340, 10, "assets/fare.ttf", 40, "***INSTRUCTIONS***");
            SDL_RenderPresent(renderer);
            SDL_Delay(duration);
            instruction(10, 100, "assets/fare.ttf", 28, "Use 'Up', 'Down', 'Right', 'Left' arrow key to move the player");
            SDL_RenderPresent(renderer);
            SDL_Delay(duration);
            instruction(10, 175, "assets/fare.ttf", 28, "Press 'Space' to fire and 'S' to activate Sheild");
            SDL_RenderPresent(renderer);
            SDL_Delay(duration);
            instruction(10, 250, "assets/fare.ttf", 28, "Killing Unarmed innocent People will decrease the health");
            SDL_RenderPresent(renderer);
            SDL_Delay(duration);
            instruction(10, 325, "assets/fare.ttf", 28, "Killing any armed enemy will increase the score");
            SDL_RenderPresent(renderer);
            SDL_Delay(duration);
            instruction(10, 400, "assets/fare.ttf", 28, "Leveling up will increase your shield number");
            SDL_RenderPresent(renderer);
            SDL_Delay(duration);
            instruction(10, 475, "assets/fare.ttf", 28, "Sheild will protect from any bullet firing");
            SDL_RenderPresent(renderer);
            SDL_Delay(2 * duration);
            if (sound_state)
            {
                Mix_Chunk *horn = Mix_LoadWAV("assets/HornAmbience.wav");
                Mix_PlayChannel(-1, horn, 0); //Playing Sound Effect
            }
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 339 && mousey <= 339 + 91)
        {
            //Mix_HaltMusic();
            keypressed = 13;
            if (sound_state)
            {
                Mix_Chunk *click = Mix_LoadWAV("assets/button.wav");
                Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            }
            SDL_RenderClear(renderer);
            TM.drawsame(0, 0, bg, renderer);
            highscoreshow();
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 461 && mousey <= 461 + 91)
        {
            //Mix_HaltMusic();
            keypressed = 20;
            //TM.drawsame(405, 461, settingsp, renderer);
            if (sound_state)
            {
                Mix_Chunk *click = Mix_LoadWAV("assets/button.wav");
                Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            }
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 583 && mousey <= 583 + 91)
        {
            //Mix_HaltMusic();
            keypressed = 15;
            //TM.drawsame(405, 583, storyp, renderer);
            if (sound_state)
            {
                Mix_Chunk *click = Mix_LoadWAV("assets/button.wav");
                Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            }
        }
    }
}
#endif