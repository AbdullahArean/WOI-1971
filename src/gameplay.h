#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "constants.h"

#include "texturemanager.h"
#include "player.h"
#include "enemy.h"
#include "tank.h"
#include "innocent.h"
#include "pbullet.h"

TextureManager TM2;
Player p1;
Enemy e1;
Enemy e2;
Enemy e3;
Innocent i1;
Innocent i2;
Tank t1;
Bullet b1[10000];
Bullet test;

void gameplayinit()
{
    gbg = TM2.ReturnTexture("assets/gameback.png", renderer);
    p1t = TM2.ReturnTexture("assets/hero.png", renderer);
    e1t = TM2.ReturnTexture("assets/enemy2.png", renderer);
    e2t = TM2.ReturnTexture("assets/enemy2.png", renderer);
    i1t = TM2.ReturnTexture("assets/innocent.png", renderer);
    t1t = TM2.ReturnTexture("assets/tank1.png", renderer);
    ppt = TM2.ReturnTexture("assets/pp.png", renderer);
    bu  = TM2.ReturnTexture("assets/bu.png", renderer);
}
void gameplayrender()
{

    TM2.drawsame(0, 0, gbg, renderer);
    p1.playerrender(160, 180, p1t, renderer, SDL_FLIP_NONE);
    t1.TankRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 300, 180, t1t, renderer, SDL_FLIP_NONE);
    
    e1.EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160, 180, e1t, renderer, SDL_FLIP_NONE);
    e2.EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 160, 180, e2t, renderer, SDL_FLIP_NONE);
    //e3.EnemyRender(WINDOW_WIDTH-160,WINDOW_HEIGHT-180-row1,160,180,e2t,renderer, SDL_FLIP_NONE);
    i1.InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160, 180, i1t, renderer, SDL_FLIP_NONE);
    i2.InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160, 180, i1t, renderer, SDL_FLIP_NONE);
    //bullet
    if(shot==1) bn++;
    shot=0;
    // {bn++;
    // b1[bn].Bulletfire(30, 10, bu, renderer, SDL_FLIP_NONE);}
    // shot=0;
    // for(int i=1; i<bn; i++)
    // {
    //     b1[bn].update( bu, renderer, SDL_FLIP_NONE);
        
    // }
    for(int i=0; i<bn; i++)
    {
        b1[i].Bulletfire(24, 8, bu, renderer, SDL_FLIP_NONE);
    }
    
    
}
void gameplayinputhandle()
{
    // SDL_Event e;
    // while (SDL_PollEvent(&e) != 0)
    // {
    //     //User requests quit
    //     if (e.type == SDL_QUIT)
    //     {
    //         game_running = 0;
    //     }
    //     //User presses a key
    //     else if (e.type == SDL_KEYDOWN)
    //     {
    //         //Select surfaces based on key press
    //         switch (e.key.keysym.sym)
    //         {
    //         case SDLK_UP:
    //             //printf("Up\n");
    //             up = 1;
    //             break;

    //         case SDLK_DOWN:
    //             //printf("Down\n");
    //             down = 1;
    //             break;

    //         case SDLK_LEFT:
    //             //printf("left\n");
    //             left = 1;
    //             break;

    //         case SDLK_RIGHT:
    //             //printf("right\n");
    //             right = 1;
    //             break;

    //         default:
    //             //printf("Default\n");
    //             break;
    //         }
    //     }
    // }
}
void gameplayupdate()
{
    
    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {

        if (mousex >= 1005 && mousex <= 1060 && mousey >= 21 && mousey <= 86)
        {
            TM2.drawsame(1005, 21, ppt, renderer);
            pause = 1;
        }
    }
    //b1.Bulletupdate(row1, 40);
    p1.playerupdate();
    
    e1.enemyupdate(row1, 40);
    e2.enemyupdate(row2, 50);
    //e3.enemyupdate(row3,60);
    i1.Innocentupdate(row1, 70);
    i2.Innocentupdate(row2, 80);
    t1.tankupdate(row3, 30);
    for(int i=0; i<bn; i++)
    {
        b1[i].update();
    }
    
    
}

#endif