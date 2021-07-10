#ifndef GAMEPLAY_H
#define GAMEPLAY_H

//Used defined header files included
#include "constants.h"
#include "texturemanager.h"
#include "player.h"
#include "enemy.h"
#include "tank.h"
#include "innocent.h"
#include "bullet.h"
#include "lastpage.h"
#include "pause.h"
#include "instructions.h"

//declared player bullet
Bullet b1[10000];
//declared texture manager
TextureManager TM2;

int keeptrack = 0;
bool ff = 0;

//Displaying Score info
SDL_Texture *score_tex = NULL;
SDL_Color score_color = {255, 255, 255, 255};
Font fscore;
//Displaying Shield info
SDL_Texture *shieldtex = NULL;
SDL_Color sn_color = {255, 255, 255, 255};
Font fsheild;
//Displaying level info
SDL_Texture *leveltex = NULL;
SDL_Color level_color = {255, 255, 255, 255};
Font flevel;
//Displaying level info
SDL_Texture *healthtex = NULL;
SDL_Color health_color = {255, 255, 255, 255};
Font fhealth;

void gameplayinit()
{
}
void gameplayrender()
{
    if (gameover == 1)
    {
        lastpagerender();
    }
    else
    {

        if (!ff)
        {

            keeptrack = SDL_GetTicks();
            ff = 1;
        }

        TM2.drawsame(0, 0, gbg, renderer);
        p1.playerrender(160 * 0.75, 180 * 0.75, p1t, renderer, SDL_FLIP_NONE);
        if (gamelevel == 1 && pscore < 50)
        {
            e1[0].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            if (pscore > 20)
                i1[0].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
        }
        else if (gamelevel == 1 && pscore == 50)
        {

            message(100, 325, "assets/fare.ttf", 50, "Congratulations");
            message(100, 425, "assets/fare.ttf", 40, "Sector-1 is Successfully Liberted.");
            message(100, 525, "assets/fare.ttf", 30, "Continue the War of Independence!");
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
            gameover = 1;
        }
        else if (gamelevel == 2 && pscore < 200)
        {
            e1[1].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            if (pscore > 80)
            {
                e1[2].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
                e1[3].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            }
            if (pscore > 70)
                i1[1].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
            if (pscore > 120)
                i1[2].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
        }
        else if (gamelevel == 2 && pscore == 200)
        {
            message(100, 325, "assets/fare.ttf", 50, "Congratulations");
            message(100, 425, "assets/fare.ttf", 40, "Sector-2 is Successfully Liberted.");
            message(100, 525, "assets/fare.ttf", 30, "Continue the War of Independence!");
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
            gameover = 1;
        }

        else if (gamelevel == 3 && pscore < 450)
        {
            e1[4].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            if (pscore > 230)
                e1[5].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            if (pscore > 290)
                e1[6].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);

            if (pscore > 300)
            {
                e1[7].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
                e1[8].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            }
            if (pscore > 240)
                i1[3].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
            if (pscore > 280)
                i1[4].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
        }
        else if (gamelevel == 3 && pscore == 450)
        {
            message(100, 325, "assets/fare.ttf", 50, "Congratulations");
            message(100, 425, "assets/fare.ttf", 40, "Sector-3 is Successfully Liberted.");
            message(100, 525, "assets/fare.ttf", 30, "Continue the War of Independence!");
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
            gameover = 1;
        }
        //level 4 Render
        else if (gamelevel == 4 && pscore < 1000)
        {
            e1[9].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            if (pscore > 470)
                e1[10].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            if (pscore > 490)
                e1[11].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            if (pscore > 510)
                e1[12].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);

            if (pscore > 600)
            {
                t1[0].TankRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 300 * 0.8, 180 * 0.8, t1t, renderer, SDL_FLIP_NONE);
                e1[14].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
                e1[15].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            }
            if (pscore > 480)
                i1[5].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
            if (pscore > 600)
                i1[6].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
            if (pscore > 700)
                i1[7].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
        }
        else if (gamelevel == 4 && pscore == 1000)
        {
            message(100, 325, "assets/fare.ttf", 50, "Congratulations");
            message(100, 425, "assets/fare.ttf", 40, "Sector-4 is Successfully Liberted.");
            message(100, 525, "assets/fare.ttf", 30, "Continue the War of Independence!");
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
            gameover = 1;
        }
        //level 5
        else if (gamelevel == 5 && pscore < 1900)
        {
            e1[16].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            
            e1[17].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            t1[1].TankRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 300 * 0.8, 180 * 0.8, t1t, renderer, SDL_FLIP_NONE);
                
            if (pscore > 1020)
                e1[18].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            if (pscore > 1030)
                e1[19].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            if (pscore > 1080)
                e1[20].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);

            if (pscore > 1200)
            {
                t1[2].TankRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 300 * 0.8, 180 * 0.8, t1t, renderer, SDL_FLIP_NONE);
                e1[21].EnemyRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row3, 160 * 0.8, 180 * 0.8, e1t, renderer, SDL_FLIP_NONE);
            }
            if (pscore > 1300)
                i1[8].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
            if (pscore > 1400)
                i1[9].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row2, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
            if (pscore > 1500)
                i1[10].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
            if (pscore > 1600)
                i1[11].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
            if (pscore > 1700)
                i1[12].InnocentRender(WINDOW_WIDTH - 160, WINDOW_HEIGHT - 180 - row1, 100 * 0.8, 180 * 0.8, i1t, renderer, SDL_FLIP_NONE);
        }
        else if (gamelevel == 5 && pscore == 1900)
        {
            message(100, 325, "assets/fare.ttf", 50, "Congratulations");
            message(100, 425, "assets/fare.ttf", 40, "Sector-5 is Successfully Liberted.");
            message(100, 525, "assets/fare.ttf", 30, "Continue the War of Independence!");
            SDL_RenderPresent(renderer);
            SDL_Delay(5000);
            gameover = 1;
        }

        //Bullet Firing
        if (shot == 1 && (int)(SDL_GetTicks() - keeptrack) >= pinterval)
        {
            bn++;
            keeptrack = SDL_GetTicks();
        }
        shot = 0;
        for (int i = 0; i < bn; i++)
        {
            b1[i].Bulletfire(p1.ReturnPositionx() + 160 * 0.75, p1.ReturnPositiony() + 34 * 0.75, bu, renderer, SDL_FLIP_NONE);
        }
        //Displaying Scores, health, shield
        score_tex = fscore.Loadfont(renderer, "assets/fare.ttf", 40, SDL_itoa(pscore, scorestr, 10), score_color);
        fscore.display(540, 38, renderer, score_tex);
        shieldtex = fsheild.Loadfont(renderer, "assets/fare.ttf", 50, SDL_itoa(shieldnumber - sn, scorestr, 10), sn_color);
        fsheild.display(317, 38, renderer, shieldtex);
        leveltex = flevel.Loadfont(renderer, "assets/fare.ttf", 50, SDL_itoa(gamelevel, scorestr, 10), level_color);
        fsheild.display(85, 38, renderer, leveltex);
        healthtex = fhealth.Loadfont(renderer, "assets/fare.ttf", 40, SDL_itoa(phealth, healthstr, 10), health_color);
        fhealth.display(785, 38, renderer, healthtex);
    }
}
void gameplayinputhandle()
{
}
void gameplayupdate()
{
    if (gameover == 1)
    {
        lupdate();
    }
    else
    {

        int mousex, mousey;
        int buttons = SDL_GetMouseState(&mousex, &mousey);
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {

            if (mousex >=WINDOW_WIDTH-135 && mousex <= WINDOW_WIDTH-55 && mousey >=37 && mousey <= 124)
            {
                pause = 1;
            }
        }
        p1.playerupdate();
        if (gamelevel == 1 && pscore < 50)
        {
            e1[0].enemyupdate(row1, 40);
            if (pscore > 20)
                i1[0].Innocentupdate(row1, 70);
        }
        //Level 2
        if (gamelevel == 2 && pscore < 200)
        {
            e1[1].enemyupdate(row3, 40);
            if (pscore > 90)
            {
                e1[2].enemyupdate(row1, 50);
                e1[3].enemyupdate(row2, 40);
            }
            if (pscore > 70)
                i1[1].Innocentupdate(row1, 70);
            if (pscore > 120)
                i1[2].Innocentupdate(row2, 60);
        }
        //level 3
        else if (gamelevel == 3 && pscore < 450)
        {
            e1[4].enemyupdate(row1, 40);
            if (pscore > 230)
                e1[5].enemyupdate(row2, 45);
            if (pscore > 290)
                e1[6].enemyupdate(row3, 60);
            if (pscore > 300)
            {
                e1[7].enemyupdate(row3, 65);
                e1[8].enemyupdate(row1, 60);
            }
            if (pscore > 240)
                i1[3].Innocentupdate(row1, 50);
            if (pscore > 280)
                i1[4].Innocentupdate(row2, 65);
        }
        //level 4
        else if (gamelevel == 4 && pscore < 1000)
        {
            e1[9].enemyupdate(row3, 65);
            if (pscore > 470)
                e1[10].enemyupdate(row2, 50);
            if (pscore > 490)
                e1[11].enemyupdate(row3, 65);
            if (pscore > 510)
                e1[12].enemyupdate(row1, 60);
            if (pscore > 600)
            {
                e1[14].enemyupdate(row2, 65);
                e1[15].enemyupdate(row1, 65);
                t1[0].tankupdate(row3, 40);
            }
            if (pscore > 480)
                i1[5].Innocentupdate(row1, 60);
            if (pscore > 600)
                i1[6].Innocentupdate(row2, 60);
            if (pscore > 700)
                i1[7].Innocentupdate(row3, 60);
        }
        //level 5
        else if (gamelevel == 5 && pscore < 1900)
        {
            e1[16].enemyupdate(row1, 45);
            e1[17].enemyupdate(row2, 55);
            t1[1].tankupdate(row3, 44);
            if (pscore > 1020)
                e1[18].enemyupdate(row3, 70);
            if (pscore > 1030)
                e1[19].enemyupdate(row1, 75);
            if (pscore > 1080)
                e1[20].enemyupdate(row2, 65);
            if (pscore > 1200)
            {
                
                t1[2].tankupdate(row1, 54);
                e1[21].enemyupdate(row2, 45);
            }
            if (pscore > 1300)
                i1[8].Innocentupdate(row1, 40);
            if (pscore > 1400)
                i1[9].Innocentupdate(row2, 50);
            if (pscore > 1500)
                i1[10].Innocentupdate(row3, 45);
            if (pscore > 1600)
                i1[11].Innocentupdate(row1, 65);
            if (pscore > 1700)
                i1[12].Innocentupdate(row2, 65);
        }
        //Player Bullet Update
        for (int i = 0; i < bn; i++)
        {
            b1[i].update(+1);
        }
    }
}

#endif