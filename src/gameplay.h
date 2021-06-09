#ifndef GAMEPLAY_H
#define GAMEPLAY_H



#include "constants.h"

#include"texturemanager.h"
#include "player.h"
#include "enemy.h"
#include "innocent.h"

TextureManager TM2;
Player p1;
Enemy e1;
Enemy e2;
Enemy e3;
Innocent i1;
Innocent i2;


SDL_Texture *gbg = NULL;
SDL_Texture *p1t = NULL;
SDL_Texture *e1t = NULL;
SDL_Texture *e2t = NULL;
SDL_Texture *i1t = NULL;



void gameplayinit()
{
    gbg = TM2.ReturnTexture("assets/gameback.png", renderer);
    p1t=TM2.ReturnTexture("assets/hero.png", renderer);
    e1t = TM2.ReturnTexture("assets/enemy2.png", renderer);
    e2t = TM2.ReturnTexture("assets/enemy2.png", renderer);
    i1t = TM2.ReturnTexture("assets/innocent.png", renderer);
    
}
void gameplayrender()
{

    TM2.drawsame(0, 0, gbg, renderer);
    p1.playerrender(160,180,p1t,renderer, SDL_FLIP_NONE);
    e1.EnemyRender(WINDOW_WIDTH-160,WINDOW_HEIGHT-180-row3,160,180,e1t,renderer, SDL_FLIP_NONE);
    e2.EnemyRender(WINDOW_WIDTH-160,WINDOW_HEIGHT-180-row2,160,180,e2t,renderer, SDL_FLIP_NONE);
    e3.EnemyRender(WINDOW_WIDTH-160,WINDOW_HEIGHT-180-row1,160,180,e2t,renderer, SDL_FLIP_NONE);
    i1.InnocentRender(WINDOW_WIDTH-160,WINDOW_HEIGHT-180-row1,160,180,i1t,renderer, SDL_FLIP_NONE);
    i2.InnocentRender(WINDOW_WIDTH-160,WINDOW_HEIGHT-180-row1,160,180,i1t,renderer, SDL_FLIP_NONE);
    


}
void gameplayinputhandle()
{
    p1.playerinput();

}
void gameplayupdate()
{
    p1.playerupdate();
    e1.enemyupdate(row1,40);
    e2.enemyupdate(row2,50);
    e3.enemyupdate(row3,60);
    i1.Innocentupdate(row1, 70);
    i2.Innocentupdate(row2, 80);

}

#endif