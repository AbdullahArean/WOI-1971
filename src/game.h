#ifndef GAME_H
#define GAME_H

#include "constants.h"
#include "gameplay.h"
#include "mainmenu.h"
#include "initialization.h"
#include "settings.h"
#include "pause.h"


typedef struct Game
{

    void init()
    {
        if (gameinitialization("WOI-1971", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT) == FALSE)
        {
            Clean(window, renderer);
            game_running = 0;
        };
        //Play the music.....
    Mix_Music *bMusic1 = Mix_LoadMUS("assets/firstpage.mp3");
    Mix_PlayMusic(bMusic1, -1);
     mainmenuinit();
    gameplayinit();
    settingsinit();
    painit();

       
   
    }
    void render()
    {
        SDL_RenderPresent(renderer);
        // clear the window to black
        SDL_RenderClear(renderer);
        if(gameplay==0 && keypressed<19) mainmenurender();
        if(gameplay==0 && keypressed>=19) settingsrender();
        if(gameplay==1) {(pause==1)?parender():gameplayrender();}

        SDL_RenderPresent(renderer);
        //SDL_Delay(5000);
    }
    void handleEvents()
    {
        SDL_Event event;
        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            game_running = FALSE;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                game_running = FALSE;
            break;
        }
        if(gameplay) gameplayinputhandle();
    }
    void update()
    {
        while(!SDL_TICKS_PASSED(SDL_GetTicks(),last_frame_time+ FRAME_TARGET_TIME));
        delta_time = (SDL_GetTicks()-last_frame_time)/1000.0f;
        last_frame_time=SDL_GetTicks();
        if(gameplay==0 && keypressed<19) mainmenuupdate();
        if(gameplay==0 && keypressed>=19) settingsupdate();
        if(gameplay==1) {(pause==1)?paupdate():gameplayupdate();}
        
    }

    void destroy_window()
    {
        Clean(window, renderer);
    }

    // a function to access the private running variable
    bool running()
    {
        if (game_running == 0)
        {
            //Clearing All The Textures
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
            SDL_DestroyTexture(fpage);
            SDL_DestroyTexture(gbg);
            SDL_DestroyTexture(p1t);
            SDL_DestroyTexture(e1t);
            SDL_DestroyTexture(e2t);
            SDL_DestroyTexture(i1t);
            SDL_DestroyTexture(t1t);
        }
        return game_running;
    }

} Game;
#endif