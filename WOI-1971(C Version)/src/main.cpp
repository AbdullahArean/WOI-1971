//It includes All the Header File
#include "constants.h"

//Main Function
int main(int argc, char *argv[])
{
    /*#define SDL_INIT_EVERYTHING ( SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO |
SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMECONTROLLER | SDL_INIT_SENSOR )*/
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return 1;
    } //end if

    //Creating SDL_ Window
    SDL_Window *win = SDL_CreateWindow(
        "WOI-1971",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (!win)
    {
        fprintf(stderr, "Error creating SDL Window.\n");
        SDL_Quit();
        return 1;
    }

    // create a renderer, which sets up the graphics hardware
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    //Creating A SDL Renderer
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);
    if (!rend)
    {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    //game init successful message
    printf("\nWW      WW  OOOOO  IIIII         1          7777777  1\nWW      WW OO   OO  III         111  99999      777 111\nWW   W  WW OO   OO  III  _____   11 99   99    777   11\n WW WWW WW OO   OO  III          11  999999   777    11\n  WW   WW   OOOO0  IIIII        111     99   777    111\n                                      999\n              \n");
    printf("Game Started Successfully! Enjoy!\n");

//========================================================================================
// load the image into memory using SDL_image library function
//1st page Loading
    SDL_Surface *surface1 = IMG_Load("assets/apage.png");
    if (!surface1)
    {
        printf("error creating surface\n");
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    // load the image data into the graphics hardware's memory
    SDL_Texture *tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);
    if (!tex1)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // struct to hold the position and size of the sprite
    SDL_Rect dest1;
    dest1.h = 720;
    dest1.w = 1280;
    dest1.x = 0;
    dest1.y = 0;
    // clear the window
    SDL_RenderClear(rend);

    // draw the image to the window
    SDL_RenderCopy(rend, tex1, NULL, &dest1);
    SDL_RenderPresent(rend);
    SDL_Delay(5000);
    SDL_DestroyTexture(tex1);
//============================================================================================
//2nd Page Loading
    // load the image into memory using SDL_image library function
    surface1 = IMG_Load("assets/bpage.png");
    if (!surface1)
    {
        printf("error creating surface\n");
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    // load the image data into the graphics hardware's memory
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);
    if (!tex1)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // clear the window
    SDL_RenderClear(rend);

    // draw the image to the window
    SDL_RenderCopy(rend, tex1, NULL, &dest1);
    SDL_RenderPresent(rend);
    SDL_Delay(5000);
    SDL_DestroyTexture(tex1);
    //2nd Page Loading
    // load the image into memory using SDL_image library function
    surface1 = IMG_Load("assets/back.png");
    if (!surface1)
    {
        printf("error creating surface\n");
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    // load the image data into the graphics hardware's memory
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);
    if (!tex1)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
//==========================================================================================================
//Loading Enemy
    SDL_Surface *surface3 = IMG_Load("assets/enemy1.png");
    if (!surface3)
    {
        printf("error creating surface\n");
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // load the image data into the graphics hardware's memory
    SDL_Texture *tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);
    if (!tex3)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    // struct to hold the position and size of the sprite
    SDL_Rect dest3;

    // get and scale the dimensions of texture
    dest3.x = 1000;
    dest3.y = 300;
    dest3.w = 113;
    dest3.h = 160;

//================================================================================================
//Loading & Rendering Hero Picture
    SDL_Surface *surface = IMG_Load("assets/hero1.png");
    if (!surface)
    {
        printf("error creating surface\n");
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // load the image data into the graphics hardware's memory
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!tex)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // struct to hold the position and size of the sprite
    SDL_Rect dest;

    // get and scale the dimensions of texture
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);
    dest.w /= 7;
    dest.h /= 7;

    // start sprite in center of screen
    float x_pos = (WINDOW_WIDTH - dest.w) / 2;
    float y_pos = (WINDOW_HEIGHT - dest.h) / 2;
    float x_vel = 0;
    float y_vel = 0;

    // keep track of which inputs are given
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;

    // set to 1 when window close button is pressed
    int game_running = 1;

    // animation loop
    while (game_running)
    {
        // process events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                game_running = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    up = 1;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left = 1;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    down = 1;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right = 1;
                    break;
                default:
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    up = 0;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    left = 0;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    down = 0;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    right = 0;
                    break;
                default:
                    break;
                }
                break;
            }
        }

        // determine velocity
        x_vel = y_vel = 0;
        if (up && !down)
            y_vel = -SPEED;
        if (down && !up)
            y_vel = SPEED;
        if (left && !right)
            x_vel = -SPEED;
        if (right && !left)
            x_vel = SPEED;

        // update positions
        x_pos += x_vel / 60;
        y_pos += y_vel / 60;

        // collision detection with bounds
        if (x_pos <= 0)
            x_pos = 0;
        if (y_pos <= 0)
            y_pos = 0;
        if (x_pos >= WINDOW_WIDTH - dest.w)
            x_pos = WINDOW_WIDTH - dest.w;
        if (y_pos >= WINDOW_HEIGHT - dest.h)
            y_pos = WINDOW_HEIGHT - dest.h;

        // set the positions in the struct
        dest.y = (int)y_pos;
        dest.x = (int)x_pos;

        // clear the window
        SDL_RenderClear(rend);

        // draw the image to the window
        SDL_RenderCopy(rend, tex1, NULL, &dest1);
        SDL_RenderCopy(rend, tex, NULL, &dest);
        SDL_RenderCopy(rend, tex3, NULL, &dest3);
        SDL_RenderPresent(rend);

        // wait 1/60th of a second
        SDL_Delay(1000 / 60);
    }

    // clean up resources before exiting
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
}