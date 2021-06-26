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
        L[i]= arr[l + i];
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
int highscoreshow()
{
    FILE *fptr;
//FILE *fp;
    Entry arr[1000];
    int i = 0;
    fptr = fopen("Score.txt", "r");
    if(fptr == NULL)
    {
        printf("Score File Can't be Read\n");
    }
    for (; i <= EOF; i++)
    {
        fscanf(fptr, "%s", arr[i].name);
    }
     for (int j=0; j <= i; j++)
    {
        printf("p%s\n", arr[j].name);
    }
    // for (i; i <= 4; i++)
    // {
    //     scanf("%s %d", arr[i].name, &arr[i].score);
    // }
    // mergeSort(arr, 0, i - 1);
    //  for (int j=0; j <= i; j++)
    // {
    //     printf("a %s %d\n", arr[j].name, arr[j].score);
    // }
    // fp = fopen("HighScore.txt", "w");
    // if(fp == NULL)
    // {
    //     printf("File Can't Write\n");
    // }
    // else{
    //     for (int j=0; j <= i; j++)
    // {
    //     fprintf(fp,"%s %d\n", arr[j].name, arr[j].score);
    // }

    // }
    
    return 0;
}
#endif