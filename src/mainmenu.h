#include "constants.h"

void mainmenuinit()
{    
    bg = TM.ReturnTexture("assets/buttonbackground.png", renderer);
    con = TM.ReturnTexture("assets/continue.png", renderer);
    newg = TM.ReturnTexture("assets/newgame.png", renderer);
    his = TM.ReturnTexture("assets/highscore.png", renderer);
    settings = TM.ReturnTexture("assets/settings.png", renderer);
    story = TM.ReturnTexture("assets/story.png", renderer);
    conp = TM.ReturnTexture("assets/continuepressed.png", renderer);
    newgp = TM.ReturnTexture("assets/newgamepressed.png", renderer);
    hisp = TM.ReturnTexture("assets/highscorep.png", renderer);
    settingsp = TM.ReturnTexture("assets/settingsp.png", renderer);
    storyp = TM.ReturnTexture("assets/storyp.png", renderer);
}
void mainmenurender()
{

    TM.drawsame(0, 0, bg, renderer);
    TM.drawsame(405, 95, con, renderer);
    TM.drawsame(405, 217, newg, renderer);
    TM.drawsame(405, 339, his, renderer);
    TM.drawsame(405, 461, settings, renderer);
    TM.drawsame(405, 583, story, renderer);
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
            TM.drawsame(405, 95, conp, renderer);
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 217 && mousey <= 217 + 91)
        {
            // printf("%d %d\n", mousex, mousey);
            TM.drawsame(405, 217, newgp, renderer);
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 339 && mousey <= 339 + 91)
        {
            // printf("%d %d\n", mousex, mousey);
            TM.drawsame(405, 339, hisp, renderer);
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 461 && mousey <= 461 + 91)
        {
            // printf("%d %d\n", mousex, mousey);
            TM.drawsame(405, 461, settingsp, renderer);
        }
        if (mousex >= 405 && mousex <= 405 + 278 && mousey >= 583 && mousey <= 583 + 91)
        {
            // printf("%d %d\n", mousex, mousey);
            TM.drawsame(405, 583, storyp, renderer);
        }
    }
}