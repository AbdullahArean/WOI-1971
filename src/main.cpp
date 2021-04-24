//It includes All the Header File
#include "constants.h"

//Game class containing header file
#include "Game.h"

//Creating my first game class object
Game *my_first_game = 0;

//Main Function
int main(int argc, char *argv[])
{
    //New Game Constructor
    my_first_game = new Game();

    //initializing game
    my_first_game->init("WOI-1971", 100, 100, 1280, 720, 0);
    printf("\nWW      WW  OOOOO  IIIII         1          7777777  1\nWW      WW OO   OO  III         111  99999      777 111\nWW   W  WW OO   OO  III  _____   11 99   99    777   11\n WW WWW WW OO   OO  III          11  999999   777    11\n  WW   WW   OOOO0  IIIII        111     99   777    111\n                                      999\n              \n");
    printf("Started Successfully! Enjoy!\n");
    //Checking if the game is running
    while (my_first_game->running())
    {
        //Render my objects onto screen
        my_first_game->render();

        //Handles all the Events
        my_first_game->handleEvents();

        //Updating after handling event
        my_first_game->update();
    }

    //Cleaning my memory by deleting all the memory related stuff
    my_first_game->clean();

    //Successfully done and retrun 0
    return 0;
}