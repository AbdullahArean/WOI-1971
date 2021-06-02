#include "Game.h"
#include "TextureManager.h"
#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams *pParams) : GameObject(pParams)
{
    //Getting All The Parameters LoaderParams Class Object pParams
    m_x = pParams->getX(); //getting x position
    m_y = pParams->getY(); //getting y position
    m_width = pParams->getWidth(); //getting width
    m_height = pParams->getHeight();//getting height
    m_textureID = pParams->getTextureID();//getting TextureID

    //We did not take any input for these two variable form Loader Params Class
    m_CurrentRow = 1;//Setting Current Frame to 1
    m_CurrentFrame = 1;//Setting Current Frame to 1
}
void SDLGameObject::draw()
{
    //Using Texture Manager to draw frame by frame
    TextureManager::Instance()->drawFrame(
        m_textureID, 
        m_x, 
        m_y, 
        m_width, 
        m_height, 
        m_CurrentRow, 
        m_CurrentFrame, 
        TheGame::Instance()->getRenderer(), 
        SDL_FLIP_NONE
        );
}

void SDLGameObject::update() {}

void SDLGameObject::clean() {}
