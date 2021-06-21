#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "constants.h"

#include "texturemanager.h"
#include "player.h"
#include "enemy.h"
#include "tank.h"
#include "innocent.h"

TextureManager TM2;
Player p1;
Enemy e1;
Enemy e2;
Enemy e3;
Innocent i1;
Innocent i2;
Tank t1;

void gameplayinit()
{
    gbg = TM2.ReturnTexture("assets/gameback.png", renderer);
    p1t = TM2.ReturnTexture("assets/hero.png", renderer);
    e1t = TM2.ReturnTexture("assets/enemy2.png", renderer);
    e2t = TM2.ReturnTexture("assets/enemy2.png", renderer);
    i1t = TM2.ReturnTexture("assets/innocent.png", renderer);
    t1t = TM2.ReturnTexture("assets/tank1.png", renderer);
    ppt = TM2.ReturnTexture("assets/pp.png", renderer);
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
}
void gameplayinputhandle()
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
    p1.playerinput();
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
            pause=1;
        }
    }
    p1.playerupdate();
    e1.enemyupdate(row1, 40);
    e2.enemyupdate(row2, 50);
    //e3.enemyupdate(row3,60);
    i1.Innocentupdate(row1, 70);
    i2.Innocentupdate(row2, 80);
    t1.tankupdate(row3, 30);
}

#endif