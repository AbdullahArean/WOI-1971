#ifndef SCORING_H
#define SCORING_H

#include "constants.h"


extern int pscore;
char name[50];
int score = pscore;
static int check = 1;
FILE *fr;
void data()
{
    // when game over  take Input
    scanf("%[\n]", name);
    //Write
    if (check == 1)
    {
        fr = fopen("Score.txt", "w");
        if (fr == NULL)
        {
            printf("File Can't Write\n");
        }
        else
        {
            fprintf(fr, "%s %d\n", name, score);
            printf("%s %d\n", name, score);
        }
        check = 0;
        fclose(fr);
    }
    else
    {
        // when game over  take Input
        scanf("%[\n]", name);
        //append
        fr = fopen("Score.txt", "a");
        if (fr == NULL)
        {
            printf("File Can't Append\n");
        }
        else
        {
            fprintf(fr, "%s %d\n", name, score);
            printf("%s %d\n", name, score);
        }
    }
}

//---------------------------------------------------
//For displaying Remaining sheild number
// SDL_Texture *shieldtex = NULL;
// SDL_Color sn_color = {255, 0 , 0 , 255};
// Font fsheild;
// shieldtex = fsheild.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(shieldnumber, scorestr, 10), sn_color);
// fsheild.display(350, 350, renderer, shieldtex);





#endif