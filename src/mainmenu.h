#include "constants.h"

void mainmenuinit()
{
    // SDL_Texture *bg = menu.ReturnTexture("assets/buttonbackground.png", renderer);
    // SDL_Texture *con = menu.ReturnTexture("assets/continue.png", renderer);
    // SDL_Texture *newg = menu.ReturnTexture("assets/newgame.png", renderer);
    // SDL_Texture *his = menu.ReturnTexture("assets/highscore.png", renderer);
    // SDL_Texture *settings = menu.ReturnTexture("assets/settings.png", renderer);
    // SDL_Texture *story = menu.ReturnTexture("assets/story.png", renderer);

    // SDL_Texture *conp = menu.ReturnTexture("assets/continuepressed.png", renderer);
    // SDL_Texture *newgp = menu.ReturnTexture("assets/newgamepressed.png", renderer);
    // SDL_Texture *hisp = menu.ReturnTexture("assets/highscorep.png", renderer);
    // SDL_Texture *settingsp = menu.ReturnTexture("assets/settingsp.png", renderer);
    // SDL_Texture *storyp = menu.ReturnTexture("assets/storyp.png", renderer);
    
    bg = menu.ReturnTexture("assets/buttonbackground.png", renderer);
    con = menu.ReturnTexture("assets/continue.png", renderer);
    newg = menu.ReturnTexture("assets/newgame.png", renderer);
    his = menu.ReturnTexture("assets/highscore.png", renderer);
    settings = menu.ReturnTexture("assets/settings.png", renderer);
    story = menu.ReturnTexture("assets/story.png", renderer);
    conp = menu.ReturnTexture("assets/continuepressed.png", renderer);
    newgp = menu.ReturnTexture("assets/newgamepressed.png", renderer);
    hisp = menu.ReturnTexture("assets/highscorep.png", renderer);
    settingsp = menu.ReturnTexture("assets/settingsp.png", renderer);
    storyp = menu.ReturnTexture("assets/storyp.png", renderer);
}
void mainmenurender()
{

    menu.drawsame(0, 0, bg, renderer);
    menu.drawsame(405, 95, con, renderer);
    menu.drawsame(405, 217, newg, renderer);
    menu.drawsame(405, 339, his, renderer);
    menu.drawsame(405, 461, settings, renderer);
    menu.drawsame(405, 583, story, renderer);
}
void mainmenuupdate()
{

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {

        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 95 && mousey <= 95 + 91)
        {
            // printf("%d %d\n", mousex, mousey);
            menu.drawsame(405, 95, conp, renderer);
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 217 && mousey <= 217 + 91)
        {
            // printf("%d %d\n", mousex, mousey);
            menu.drawsame(405, 217, newgp, renderer);
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 339 && mousey <= 339 + 91)
        {
            // printf("%d %d\n", mousex, mousey);
            menu.drawsame(405, 339, hisp, renderer);
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 461 && mousey <= 461 + 91)
        {
            // printf("%d %d\n", mousex, mousey);
            menu.drawsame(405, 461, settingsp, renderer);
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 583 && mousey <= 583 + 91)
        {
            // printf("%d %d\n", mousex, mousey);
            menu.drawsame(405, 583, storyp, renderer);
        }
    }
}