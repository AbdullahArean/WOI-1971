//Controlling redefinition
#ifndef Game_hpp
#define Game_hpp

//All The header file included and other global variable declared
#include "constants.h"
#include"Gameobject.h"

//Game class initialization
class Game
{
public:
    ~Game(); // Destructor

    //SDL game initialization
    bool init(const char *title, int xpos, int ypos, int width, int height, int flags);
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
    // create the public instance function
    static Game *Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
    //will return our SDL_Renderer object
    SDL_Renderer *getRenderer() const { return m_pRenderer; }

private:
    // make the constructor private
    Game();
    // create the s_pInstance member variable
    static Game *s_pInstance;
    //Creating a SDL_Window Pointer to display a window
    SDL_Window *m_pWindow;
    //Creating a SDL_Renderer Pointer to render everything
    SDL_Renderer *m_pRenderer;
    //For Time Calculaton
    int last_frame_time = 0;
    //A vector to store Game object
    std::vector<GameObject *> m_gameObjects;
    //A bool variable soring if the game is running or not
    bool m_bRunning = FALSE;
};

// create the typedef
typedef Game TheGame;
#endif