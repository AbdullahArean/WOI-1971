#include "constants.h"
#include "game.h"
#include "player.h"



int main(int argc, char *args[])
{
    
    Game myfirstgame;
    myfirstgame.init();
    while(myfirstgame.running())
    {
        myfirstgame.handleEvents();
        myfirstgame.update();
        myfirstgame.render();
    }
    myfirstgame.destroy_window();
    return 0;
}

