#ifndef LASTPAGE_H
#define LASTPAGE_H

#include "constants.h"
#include "texturemanager.h"

int lkeypressed = 0; //variable to keep track which key pressed

TextureManager TM5; //declared texture manager
FILE *fr;           //File handling

void lastpageinit()
{
    //Playing the music  according to the state of Sound System
    if (sound_state)
    {
        Mix_Music *bMusic2 = Mix_LoadMUS("assets/secondpage.mp3");
        Mix_PlayMusic(bMusic2, -1);
    }
}
void lastpagerender()
{
    TM5.drawsame(0, 0, bg, renderer); //drawing background

    //doing according to the key pressed
    if (lkeypressed == 11)
        TM5.drawsame(405, 95, rep, renderer);
    else
        TM5.drawsame(405, 95, re, renderer);
    if (lkeypressed == 12)
    {
        //When One level is passed it is pressed to goto next
        TM5.drawsame(405, 217, nextlevelp, renderer); //start gameplay
        if (phealth > 0)
        {
            gamelevel++;     //game level increase
            shieldnumber++;  //shield number increase
            sn = 0;          //current shield
            phealth += 10;   //player health increase
            SPEED += 10;     //Player speed increase
            pinterval -= 30; //Player firing interval decreased
            gameover = 0;    //gameover is 0
        }
    }
    else
        TM5.drawsame(405, 217, nextlevel, renderer);

    if (lkeypressed == 13)
    {

        //Saving score
        TM5.drawsame(405, 339, sap, renderer);

        char name[50];
        extern int pscore;

        //instruction and input
        printf(":::::::SAVE SCORE::::::::\n");
        printf("Type Your Name and Press Enter to Save Your Score:\n");
        scanf("%[^\n]", name);
        printf("Score Saved Successfully!");

        //file handling
        fr = fopen("Score.txt", "a");
        if (fr == NULL)
        {
            printf("File Can't Write\n");
        }
        else
        {
            fprintf(fr, "%s %d\n", name, pscore);
        }

        fclose(fr); //closing file
    }
    else
        TM5.drawsame(405, 339, sa, renderer);
    if (lkeypressed == 14)
    {
        game_running = 0;
        TM5.drawsame(405, 461, exip, renderer);
    }
    else
        TM5.drawsame(405, 461, exi, renderer);

    lkeypressed = 0;
}
//lastpage update
void lupdate()
{

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {

        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 95 && mousey <= 95 + 91)
        {
            lkeypressed = 11;
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 217 && mousey <= 217 + 91)
        {
            lkeypressed = 12;
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 339 && mousey <= 339 + 91)
        {
            lkeypressed = 13;
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 461 && mousey <= 461 + 91)
        {
            Mix_HaltMusic();
            lkeypressed = 14;
        }
    }
}
#endif