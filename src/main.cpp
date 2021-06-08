#include "constants.h"
#include "game.h"
#include "player.h"



int main(int argc, char *args[])
{
    
    Game myfirstgame;
    myfirstgame.init();
    //mainmenu();
    while(myfirstgame.running())
    {
        myfirstgame.handleEvents();
        myfirstgame.update();
        myfirstgame.render();
    }
    close();
    myfirstgame.destroy_window();
    SDL_Delay(3000);
    return 0;
}

