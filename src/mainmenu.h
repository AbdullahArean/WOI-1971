#ifndef MAINMENU_H
#define MAINMENU_H

#include "constants.h"
#include"texturemanager.h"

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

    
    //Playing the music for 1st page according to the state of Sound System
   
        Mix_Music *bMusic1 = Mix_LoadMUS("assets/firstpage.mp3");
        Mix_PlayMusic(bMusic1, -1);
    

    //First Page Load
    fpage = TM.ReturnTexture("assets/woinewhomepage.png", renderer);
    TM.draw(0, 0, 1080, 720, fpage, renderer, SDL_FLIP_NONE);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(9000);
    Mix_HaltMusic();//Stopping the 1st page music

    //Playing the music for 1st page according to the state of Sound System
    if(sound_state)
    {
        Mix_Music *bMusic2 = Mix_LoadMUS("assets/secondpage.mp3");
        Mix_PlayMusic(bMusic2, -1);
    }
    
}
void mainmenurender()
{
    TM.drawsame(0, 0, bg, renderer);
    
    if(keypressed==11) TM.drawsame(405, 95, con, renderer);
    else TM.drawsame(405, 95, conp, renderer);
    if(keypressed==12) TM.drawsame(405, 217, newg, renderer);
    else TM.drawsame(405, 217, newgp, renderer);
    if(keypressed==13) TM.drawsame(405, 339, his, renderer);
    else TM.drawsame(405, 339, hisp, renderer);
    if(keypressed==20) TM.drawsame(405, 461, settings, renderer);
    else TM.drawsame(405, 461, settingsp, renderer);
    if(keypressed==15) TM.drawsame(405, 583, story, renderer);
    else TM.drawsame(405, 583, storyp, renderer);
    
     if(keypressed==11 || keypressed==12) gameplay=1;

   

    keypressed=0;
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
            keypressed=11;
            //TM.drawsame(405, 95, conp, renderer);
            //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            if(sound_state)
            {
                Mix_Chunk *horn = Mix_LoadWAV("assets/HornAmbience.wav");
                Mix_PlayChannel(-1, horn ,0);//Playing Sound Effect
            }
           
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 217 && mousey <= 217 + 91)
        {
            Mix_HaltMusic();
            keypressed=12;
            // TM.drawsame(405, 217, newgp, renderer);
            //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            //gameplay= 1; //change
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 339 && mousey <= 339 + 91)
        {
            //Mix_HaltMusic();
            keypressed=13;
            //TM.drawsame(405, 339, hisp, renderer);
            //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 461 && mousey <= 461 + 91)
        {
            //Mix_HaltMusic();
            keypressed=20;
            //TM.drawsame(405, 461, settingsp, renderer);
            //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 583 && mousey <= 583 + 91)
        {
            //Mix_HaltMusic();
            keypressed=15;
            //TM.drawsame(405, 583, storyp, renderer);
            //Mix_PlayChannel(-1, click ,0);//Playing Sound Effect
            StoryScript = 1;
        }
    }
}
#endif