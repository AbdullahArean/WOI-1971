//It includes All the Header File
#include "constants.h"

//Game class containing header file
#include "Game.h"

//Creating my first game class object
Game *my_first_game = 0;

//Main Function
int main(int argc, char *argv[])
{

    //initializing game
    if (TheGame::Instance()->init("WOI", 100, 100, 1280, 720, FALSE))
    {
        //game init successful message
        printf("\nWW      WW  OOOOO  IIIII         1          7777777  1\nWW      WW OO   OO  III         111  99999      777 111\nWW   W  WW OO   OO  III  _____   11 99   99    777   11\n WW WWW WW OO   OO  III          11  999999   777    11\n  WW   WW   OOOO0  IIIII        111     99   777    111\n                                      999\n              \n");
        printf("Started Successfully! Enjoy!\n");

        //Checking if the game is running
        while (TheGame::Instance()->running())
        {
            //Render my objects onto screen
            TheGame::Instance()->handleEvents();
            //Handles all the Events
            TheGame::Instance()->update();
            //Display content or Update the screen after handling event
            TheGame::Instance()->render();
        }
    }
     //Cleaning my memory by deleting all the memory related stuff
    TheGame::Instance()->clean();
    //Successfully done and retrun 0
    return 0;
}