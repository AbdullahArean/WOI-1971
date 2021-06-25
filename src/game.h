#ifndef GAME_H
#define GAME_H

#include "constants.h"
#include "gameplay.h"
#include "mainmenu.h"
#include "initialization.h"
#include "settings.h"
#include "pause.h"
#include "lastpage.h"

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
        lastpageinit();
    }
    void render()
    {
        SDL_RenderPresent(renderer);
        // clear the window to black
        SDL_RenderClear(renderer);
        if (gameplay == 0 && keypressed < 19)
            mainmenurender();
        if (gameplay == 0 && keypressed >= 19)
            settingsrender();
        if (gameplay == 1)
        {
            (pause == 1) ? parender() : gameplayrender();
        }

        SDL_RenderPresent(renderer);
        //SDL_Delay(5000);
    }
    void handleEvents()
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                game_running=0;
            }
            //User presses a key
            else if (e.type == SDL_KEYDOWN)
            {
                //Select surfaces based on key press
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    //printf("Up\n");
                    up=1;
                    break;

                case SDLK_DOWN:
                    //printf("Down\n");
                    down=1;
                    break;

                case SDLK_LEFT:
                    //printf("left\n");
                    left=1;
                    break;

                case SDLK_RIGHT:
                    //printf("right\n");
                    right=1;
                    break;
                 case SDLK_SPACE:
                    shot=1;
                    break;
                case SDLK_s:
                    shield=1;
                    break;

                default:
                    //printf("Default\n");
                    break;
                }
            }
        }
    }
        void update()
        {
            while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME))
                ;
            delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
            last_frame_time = SDL_GetTicks();
            if (gameplay == 0 && keypressed < 19)
                mainmenuupdate();
            if (gameplay == 0 && keypressed >= 19)
                settingsupdate();
            if (gameplay == 1)
            {
                (pause == 1) ? paupdate() : gameplayupdate();
            }
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
            //if(phealth<=0) game_running=0;
            return game_running;
        }
    }
Game;
#endif