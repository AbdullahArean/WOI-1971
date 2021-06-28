#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "constants.h"
typedef struct entry
{
    char name[100];
    int score;

} Entry;

void merge(Entry arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    Entry L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].score >= R[j].score)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(Entry arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */

/* Driver code */

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
//int check = 0;
int factor;

void highscoreshow()
{
    FILE *fptr;
    FILE *fp;
    Entry arr[1000],tempo;
    int i, j,m,n;
    //int cnt = 0;
    fptr = fopen("Score.txt", "r");
    if (fptr == NULL)
    {
        printf("Score File Can't be Read\n");
    }
    //printf("Hi!\n");
    for (i = 0; i != EOF; i++)
    {
        fscanf(fptr, "%s %d", arr[i].name, &arr[i].score);
        if (arr[i].name[0] == '\0')
        {
            break;
        }
        //cnt++;
    }
    fclose(fptr);
    //mergeSort(arr, 0, i - 1);
    //printf("%d\n", cnt);


    //Sorting (Bubble Sort)-------
    for(m=0 ; m<i ; m++)
    {
        for(n=m+1 ; n<i ; n++)
        {
            if(arr[m].score < arr[n].score)
            {
                tempo = arr[m];
                arr[m] = arr[n];
                arr[n] = tempo;
            }
        }
    }
    //------------------------


    if(i < 5)
        factor = i;
    else
        factor = 5;

    for (j = 0; j < factor; j++)
    {
        printf("%s %d\n", arr[j].name, arr[j].score);
        //printf("A");
    }
    //check++;
    //printf("%d\n",check);

    fp = fopen("HighScore.txt", "w");
    if (fp == NULL)
    {
        printf("File Can't Write\n");
    }
    else
    {
        for (int j = 0; j < factor; j++)
        {
            fprintf(fp, "%s %d\n", arr[j].name, arr[j].score);
        }
    }
    fclose(fp);

    htex = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, "Highest Score", hcolor);
    fhigh.display(50, 50, renderer, htex);

    switch(factor)
    {
        case 5:
            nt5 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[4].name, hcolor);
            fhigh.display(50, 550, renderer, nt5);
            ht5 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[4].score , str, 10), hcolor);
            fhigh.display(350, 550, renderer, ht5);
        case 4:
            nt4 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[3].name, hcolor);
            fhigh.display(50, 450, renderer, nt4);
            ht4 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[3].score , str, 10), hcolor);
            fhigh.display(350, 450, renderer, ht4);
        case 3:
            nt3 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[2].name, hcolor);
            fhigh.display(50, 350, renderer, nt3);
            ht3 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[2].score , str, 10), hcolor);
            fhigh.display(350, 350, renderer, ht3);
        case 2:
            nt2 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[1].name, hcolor);
            fhigh.display(50, 250, renderer, nt2);
            ht2 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[1].score , str, 10), hcolor);
            fhigh.display(350, 250, renderer, ht2);
        case 1:
            nt1 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[0].name, hcolor);
            fhigh.display(50, 150, renderer, nt1);
            ht1 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[0].score, str, 10), hcolor);
            fhigh.display(350, 150, renderer, ht1);
    }
    // nt1 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[0].name, hcolor);
    // fhigh.display(50, 150, renderer, nt1);
    // ht1 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[0].score, str, 10), hcolor);
    // fhigh.display(350, 150, renderer, ht1);
    // nt2 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[1].name, hcolor);
    // fhigh.display(50, 250, renderer, nt2);
    // ht2 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[1].score , str, 10), hcolor);
    // fhigh.display(350, 250, renderer, ht2);
    // nt3 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[2].name, hcolor);
    // fhigh.display(50, 350, renderer, nt3);
    // ht3 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[2].score , str, 10), hcolor);
    // fhigh.display(350, 350, renderer, ht3);
    // nt4 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[3].name, hcolor);
    // fhigh.display(50, 450, renderer, nt4);
    // ht4 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[3].score , str, 10), hcolor);
    // fhigh.display(350, 450, renderer, ht4);
    // nt5 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, arr[4].name, hcolor);
    // fhigh.display(50, 550, renderer, nt5);
    // ht5 = fhigh.Loadfont(renderer, "assets/DancingScript.ttf", 50, SDL_itoa(arr[4].score , str, 10), hcolor);
    // fhigh.display(350, 550, renderer, ht5);
}
#endif