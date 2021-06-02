#include "Game.h"
#include "constants.h"
#include"TextureManager.h"
Game *Game::s_pInstance = 0;
//Constructor
Game::Game()
{
}
//Destructor
Game::~Game()
{
}

//SDL game initialization
bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
    /*#define SDL_INIT_EVERYTHING ( SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO |
SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMECONTROLLER | SDL_INIT_SENSOR )*/
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        m_bRunning = FALSE;
        return FALSE;
    } //end if
      /*
SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags)
Create a window with the specified position, dimensions, and flags.

Parameters:
title – The title of the window, in UTF-8 encoding.
x – The x position of the window, ::SDL_WINDOWPOS_CENTERED, or ::SDL_WINDOWPOS_UNDEFINED.
y – The y position of the window, ::SDL_WINDOWPOS_CENTERED, or ::SDL_WINDOWPOS_UNDEFINED.
w – The width of the window, in screen coordinates.
h – The height of the window, in screen coordinates.
flags – The flags for the window, a mask of any of the following: ::SDL_WINDOW_FULLSCREEN, ::SDL_WINDOW_OPENGL, ::SDL_WINDOW_HIDDEN, ::SDL_WINDOW_BORDERLESS, ::SDL_WINDOW_RESIZABLE, ::SDL_WINDOW_MAXIMIZED, ::SDL_WINDOW_MINIMIZED, ::SDL_WINDOW_INPUT_GRABBED, ::SDL_WINDOW_ALLOW_HIGHDPI, ::SDL_WINDOW_VULKAN ::SDL_WINDOW_METAL.

Returns:
The created window, or NULL if window creation failed
*/
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_RESIZABLE);
    if (!m_pWindow)
    {
        fprintf(stderr, "Error creating SDL Window.\n");
        m_bRunning = FALSE;
        return FALSE;
    } //end if
      /*
SDL_Renderer *SDL_CreateRenderer(SDL_Window *window, int index, Uint32 flags)
Create a 2D rendering context for a window.

Parameters:
window – The window where rendering is displayed.
index – The index of the rendering driver to initialize, or -1 to initialize the first one supporting the requested flags.
flags – ::SDL_RendererFlags.

Returns:
A valid rendering context or NULL if there was an error.
*/
    m_pRenderer = SDL_CreateRenderer(
        m_pWindow,
        -1,
        0);

    if (!m_pRenderer)
    {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        m_bRunning = FALSE;
        return FALSE;
    } //end if

    //Loading All Images
    if (!TextureManager::Instance()->load("assets/woihomepage.png", "homepage", m_pRenderer))
    {
        m_bRunning = FALSE;
        return FALSE;
    }
    // if (!TextureManager::Instance()->load("assets/enemy1.png", "enemy1", m_pRenderer))
    // {
    //     m_bRunning = FALSE;
    //     return FALSE;
    // }
    if (!TextureManager::Instance()->load("assets/apage.png", "apage", m_pRenderer))
    {
        m_bRunning = FALSE;
        return FALSE;
    }
    if (!TextureManager::Instance()->load("assets/logo.png", "logo", m_pRenderer))
    {
        m_bRunning = FALSE;
        return FALSE;
    }
    m_bRunning = TRUE;
    return TRUE;

} //end funtion

//Hadling all events namely inputs
void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        m_bRunning = FALSE;
        break;

    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
            m_bRunning = FALSE;
        break;
    }
}
//Updating according to input
void Game::update()
{
}
//Render or display object/text etc
void Game::render()
{
    // set to black
    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
    // clear the window to black
    SDL_RenderClear(m_pRenderer);

    //Using Texture Manager to Draw a picture as it is
    TextureManager::Instance()->drawsame("homepage", 0,0,m_pRenderer);
    TextureManager::Instance()->drawsame ("logo", 40, 200,m_pRenderer);
    
    // show the window
    SDL_RenderPresent(m_pRenderer);
}

//Clean or destroy all the work and freeing up memory
void Game::clean()
{
    SDL_DestroyRenderer(m_pRenderer); //destroying renderer in memory
    SDL_DestroyWindow(m_pWindow);     //destroying widow in memory
    SDL_Quit();                       //Quit SDL
}

// a function to access the private running variable which checks game is running or not
bool Game::running()
{
    return m_bRunning;
}
