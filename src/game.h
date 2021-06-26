#ifndef GAME_H
#define GAME_H
//User Defined Header File
#include "constants.h"
#include "gameplay.h"
#include "mainmenu.h"
#include "initialization.h"
#include "settings.h"
#include "pause.h"
#include "lastpage.h"
#include "story.h"

typedef struct Game
{
    //initializing Game structure
    void init()
    {
        if (gameinitialization("WOI-1971", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT) == FALSE)
        {
            Clean(window, renderer);
            game_running = 0;
        };

        //Playing the music
        Mix_Music *bMusic1 = Mix_LoadMUS("assets/firstpage.mp3");
        Mix_PlayMusic(bMusic1, -1);

        //Initializng
        mainmenuinit();
        gameplayinit();
        settingsinit();
        painit();
        lastpageinit();
    }
    //Rendering the game
    void render()
    {
        //Presenting Renderer
        SDL_RenderPresent(renderer);
        // clear the window to black
        SDL_RenderClear(renderer);
        //Checking and displaying accordingly
        if (gameplay == 0 && keypressed < 19)
        {
            (StoryScript == 1) ? srender() : mainmenurender();
        }
        if (gameplay == 0 && keypressed >= 19)
            settingsrender();
        if (gameplay == 1)
        {
            (pause == 1) ? parender() : gameplayrender();
        }
        SDL_RenderPresent(renderer);
    }
    //Handling Events in game structure
    void handleEvents()
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                game_running = 0;
            }
            //User presses a key
            else if (e.type == SDL_KEYDOWN)
            {
                //Select surfaces based on key press
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    //printf("Up\n");
                    up = 1;
                    break;
                case SDLK_DOWN:
                    //printf("Down\n");
                    down = 1;
                    break;
                case SDLK_LEFT:
                    //printf("left\n");
                    left = 1;
                    break;
                case SDLK_RIGHT:
                    //printf("right\n");
                    right = 1;
                    break;
                case SDLK_SPACE:
                    //printf("Shot\n");
                    shot = 1;
                    break;
                case SDLK_s:
                    //printf("Shield\n");
                    shield = 1;
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
        //Getting Timing and making game predefined frame per second
        while (!SDL_TICKS_PASSED(SDL_GetTicks(), last_frame_time + FRAME_TARGET_TIME))
            ;
        delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f; //Time to delay
        last_frame_time = SDL_GetTicks();                          //keeping last frame time

        //Checking what to execute
        if (gameplay == 0 && keypressed < 19)
        {
            (StoryScript == 1) ? supdate() : mainmenuupdate();
        }
        if (gameplay == 0 && keypressed >= 19)
            settingsupdate();
        if (gameplay == 1)
        {
            (pause == 1) ? paupdate() : gameplayupdate();
        }
    }
    //Destroying game window
    void destroy_window()
    {
        Clean(window, renderer); //calling function from clean.h
    }

    // a function to access the game running variable
    bool running()
    {
        return game_running;
    }
} Game;
#endif