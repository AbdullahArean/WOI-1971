//User Defined Header File
#include "constants.h"
#include "game.h"


//Main Function
int main(int argc, char *args[])
{
    //Making Game Structure
    Game myfirstgame;

    //Initializing Game  
    myfirstgame.init();

    //Making a loop when game is running
    while(myfirstgame.running())
    {
        //Handling Events like input
        myfirstgame.handleEvents();
        //Updating the screen accordingly
        myfirstgame.update();
        //Displaying 
        myfirstgame.render();
    }
    //Exit from the game 
    myfirstgame.destroy_window();

    //Successfully Executed 
    return 0;
}

