#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "constants.h"

#include "texturemanager.h"
#include "player.h"
#include "enemy.h"
#include "tank.h"
#include "innocent.h"
#include "bullet.h"
#include "lastpage.h"

TextureManager TM2;
Player p1;
Enemy e1[10];
// Enemy e2;
// Enemy e3;
Innocent i1[10];
//Innocent i2;
Tank t1[10];
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
    bu1= TM2.ReturnTexture("assets/bu1.png", renderer);
}
void gameplayrender()
{
    if(gameover==1)
    {
        lastpagerender();

    }
    else{

    TM2.drawsame(0, 0, gbg, renderer);
    p1.playerrender(160, 180, p1t, renderer, SDL_FLIP_NONE);
    if(pscore>=100) t1[0].TankRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 300, 180, t1t, renderer, SDL_FLIP_NONE);
    if(pscore>=300) t1[1].TankRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 300, 180, t1t, renderer, SDL_FLIP_NONE);
    e1[0].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160, 180, e1t, renderer, SDL_FLIP_NONE);
    e1[1].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 160, 180, e2t, renderer, SDL_FLIP_NONE);
    //e3.EnemyRender(WINDOW_WIDTH-160,WINDOW_HEIGHT-180-row1,160,180,e2t,renderer, SDL_FLIP_NONE);
    i1[0].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160, 180, i1t, renderer, SDL_FLIP_NONE);
    i1[1].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160, 180, i1t, renderer, SDL_FLIP_NONE);
    //bullet
    if(shot==1) bn++;
    shot=0;
    for(int i=0; i<bn; i++)
    {
        b1[i].Bulletfire(p1.ReturnPlayerPositionx()+160,p1.ReturnPlayerPositiony()+34, bu, renderer, SDL_FLIP_NONE);
    }
    }
    
}
void gameplayinputhandle()
{

}
void gameplayupdate()
{
    if(phealth<=0 || pscore>=1100) gameover=1;
    if(gameover==1)
    {
        lupdate();

    }
    else{
    
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
    
    e1[0].enemyupdate(row1, 40);
    e1[1].enemyupdate(row2, 50);
    //e3.enemyupdate(row3,60);
    i1[0].Innocentupdate(row1, 70);
    i1[1].Innocentupdate(row2, 80);
    if(pscore>=100) t1[0].tankupdate(row3, 30);

    if(pscore>=300) t1[1].tankupdate(row3, 30);
    for(int i=0; i<bn; i++)
    {
        b1[i].update(+1);
    }
    }
    
}

#endif