#ifndef GAME_H
#define GAME_H

#include "constants.h"
#include "player.h"
#include"enemy.h"
#include "mainmenu.h"
#include "initialization.h"
Player p1;
Enemy e1;
TextureManager TM1;
typedef struct Game
{

    void init()
    {
        if (gameinitialization("WOI-1971", 100, 200, WINDOW_WIDTH, WINDOW_HEIGHT) == FALSE)
        {
            Clean(window, renderer);
            game_running = 0;
        };
        //mainmenuinit();
    }
    void render()
    {
        SDL_RenderPresent(renderer);
        // clear the window to black
        SDL_RenderClear(renderer);
        //First Page Loading
        //mainmenurender();
        e1.draw(0,0,100,200,TM1.ReturnTexture("assets/storyp.png", renderer),renderer, SDL_FLIP_NONE);
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
    }
    void update()
    {
        mainmenuupdate();
        
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
        }
        return game_running;
    }

} Game;
#endif /* defined(__Game__) */