#ifndef CLEAN_H
#define CLEAN_H

////User Defined Header File Included
#include "constants.h"
#include "sound.h"

//Destroying the window and the renderer
void Clean(SDL_Window *win, SDL_Renderer *render)
{
    soundclose();
    //Clearing All The Textures
    SDL_DestroyTexture(fpage);
    SDL_DestroyTexture(bg);
    SDL_DestroyTexture(con);
    SDL_DestroyTexture(conp);
    SDL_DestroyTexture(newg);
    SDL_DestroyTexture(newgp);
    SDL_DestroyTexture(his);
    SDL_DestroyTexture(hisp);
    SDL_DestroyTexture(settings);
    SDL_DestroyTexture(settingsp);
    SDL_DestroyTexture(story);
    SDL_DestroyTexture(storyp);
    SDL_DestroyTexture(nextlevel);
    SDL_DestroyTexture(nextlevelp);
    SDL_DestroyTexture(son);
    SDL_DestroyTexture(sonp);
    SDL_DestroyTexture(soff);
    SDL_DestroyTexture(mainmenu);
    SDL_DestroyTexture(mainmenup);
    SDL_DestroyTexture(ppt);
    SDL_DestroyTexture(exi);
    SDL_DestroyTexture(exip);
    SDL_DestroyTexture(gbg);
    SDL_DestroyTexture(p1t);
    SDL_DestroyTexture(e1t);
    SDL_DestroyTexture(e2t);
    SDL_DestroyTexture(i1t);
    SDL_DestroyTexture(t1t);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(bu);
    SDL_DestroyTexture(bu1);
    SDL_DestroyTexture(storyback);
    SDL_DestroyTexture(shie);
    SDL_DestroyRenderer(render); //Destroying Renderer
    SDL_DestroyWindow(win);      //Destroying Window
    TTF_Quit();                  //Quiting SDL_ttf
    Mix_Quit();                  //Quiting SDL_mixer
    IMG_Quit();                  //Quiting SDL Image
    SDL_Quit();                  //Quiting SDL
}

#endif