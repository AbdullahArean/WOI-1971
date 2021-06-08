#ifndef GAMEPLAY_H
#define GAMEPLAY_H



#include "constants.h"

#include"texturemanager.h"
#include "player.h"
#include "enemy.h"

TextureManager TM2;
Player p1;
Enemy e1;
Enemy e2;


SDL_Texture *gbg = NULL;
SDL_Texture *p1t = NULL;
SDL_Texture *e1t = NULL;
SDL_Texture *e2t = NULL;
SDL_Texture *innocent = NULL;



void gameplayinit()
{
    gbg = TM2.ReturnTexture("assets/gameback.png", renderer);
    p1t=TM2.ReturnTexture("assets/hero.png", renderer);
    e1t = TM2.ReturnTexture("assets/enemy2.png", renderer);
    e2t = TM2.ReturnTexture("assets/enemy2.png", renderer);
    
}
void gameplayrender()
{

    TM2.drawsame(0, 0, gbg, renderer);
    p1.draw(0,0,160,180,p1t,renderer, SDL_FLIP_NONE);
    e1.draw(100,200,160,180,e1t,renderer, SDL_FLIP_NONE);
    e2.draw(500,200,160,180,e2t,renderer, SDL_FLIP_NONE);
    


}

void gameplayupdate()
{
    p1.PlayerUpdate();

}

#endif