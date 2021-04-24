//Controlling redefinition
#ifndef Game_hpp
#define Game_hpp

//All The header file included and other global variable declared
#include "constants.h"

//Game class initialization
class Game
{
public:
    Game();  // Constructor
    ~Game(); // Destructor

    //SDL game initialization
    void init(const char *title, int xpos, int ypos, int width, int height, int flags);
    //Hadling all events namely inputs
    void handleEvents();
    //Updating according to input
    void update();
    //Render or display object/text etc
    void render();
    //Clean or destroy all the work and freeing up memory
    void clean();
    //function to check if the game is over or not
    bool running();

private:
    //Creating a SDL_Window Pointer to display a window
    SDL_Window *m_pWindow;
    //Creating a SDL_Renderer Pointer to render everything
    SDL_Renderer *m_pRenderer;
    //A bool variable soring if the game is running or not
    bool m_bRunning = FALSE;
};
#endif