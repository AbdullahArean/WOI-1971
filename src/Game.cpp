#include "Game.h"
#include "constants.h"
//Constructor
Game::Game()
{
}
//Destructor
Game::~Game()
{
}

//SDL game initialization
void Game::init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        m_bRunning = FALSE;
    } //end if
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_RESIZABLE);
    if (!m_pWindow)
    {
        fprintf(stderr, "Error creating SDL Window.\n");
        m_bRunning = FALSE;
    } //end if
    m_pRenderer = SDL_CreateRenderer(
        m_pWindow,
        -1,
        0);

    if (!m_pRenderer)
    {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        m_bRunning = FALSE;
    } //end if

    m_bRunning = TRUE;

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
