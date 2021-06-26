#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "constants.h"
#include <stdio.h> 
#include <string.h>

int h[5] = {25, 35, 100, 110, 115};
char str1[20] = "C programming";
char str2[20];

  // copying str1 to str2
  
// char *name1[11];
// char *name2;
// char *name3;
// char *name4; 
// char *name5; 
// name1= strcpy(name1,"Arean");
// strcpy(name1,"Santo");
// strcpy(name1,"Tahian");
// strcpy(name1,"Rhino");
// strcpy(name1,"Estona");

//Problem in highscore displaying
//Should be fixed
Font fhigh;
SDL_Texture *ht1 = NULL;
SDL_Texture *ht2 = NULL;
SDL_Texture *ht3 = NULL;
SDL_Texture *ht4 = NULL;
SDL_Texture *ht5 = NULL;
SDL_Texture *nt1 = NULL;
SDL_Texture *nt2 = NULL;
SDL_Texture *nt3 = NULL;
SDL_Texture *nt4 = NULL;
SDL_Texture *nt5 = NULL;
SDL_Texture *htex = NULL;

SDL_Color hcolor = {255, 255, 255, 255};
char str[11];
void high()
{
    htex = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, "Highest Score", hcolor);
    fhigh.display(50, 50, renderer, htex);
    nt1 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, "Arean", hcolor);
    fhigh.display(50, 150, renderer, nt1);
    ht1 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(h[0], str, 10), hcolor);
    fhigh.display(350, 150, renderer, ht1);
    nt2 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, "Santo", hcolor);
    fhigh.display(50, 250, renderer, nt2);
    ht2 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(h[1], str, 10), hcolor);
    fhigh.display(350, 250, renderer, ht2);
    nt3 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, "Tahian", hcolor);
    fhigh.display(50, 350, renderer, nt3);
    ht3 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(h[2], str, 10), hcolor);
    fhigh.display(350, 350, renderer, ht3);
    nt4 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, "Rhino", hcolor);
    fhigh.display(50, 450, renderer, nt4);
    ht4 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(h[3], str, 10), hcolor);
    fhigh.display(350, 450, renderer, ht4);
    nt5 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, "Estona", hcolor);
    fhigh.display(50, 550, renderer, nt5);
    ht5 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(h[4], str, 10), hcolor);
    fhigh.display(350, 550, renderer, ht5);
}

#endif