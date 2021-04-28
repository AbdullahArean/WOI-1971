#include "TextureManager.h"

TextureManager *TextureManager::s_pInstance = 0;

//Load
bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *pRenderer)
{
    SDL_Surface *pTempSurface = IMG_Load(fileName.c_str()); //Loading image as SDL Surface

    if (pTempSurface == NULL)
    {
        return FALSE;
    }

    //Creating Texture From Surface
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

    //Freeing Up the memory by freeing Surface
    SDL_FreeSurface(pTempSurface);

    //everything went ok, add the texture to our list/map
    if (pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return TRUE;
    }

    //reaching here means something went wrong
    return false;
}

//Draw
void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    //Two SDL Rectangle
    SDL_Rect srcRect;
    SDL_Rect desRect;

    // Simple dimension calculation
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = desRect.w = width;
    srcRect.h = desRect.h = height;
    desRect.x = x;
    desRect.y = y;

/*int SDL_RenderCopyEx(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect, double angle, const SDL_Point *center, SDL_RendererFlip flip)
Copy a portion of the source texture to the current rendering target, rotating it by angle around the given center

Parameters:
renderer – The renderer which should copy parts of a texture.
texture – The source texture.
srcrect – A pointer to the source rectangle, or NULL for the entire texture.
dstrect – A pointer to the destination rectangle, or NULL for the entire rendering target.
angle – An angle in degrees that indicates the rotation that will be applied to dstrect, rotating it in a clockwise direction
center – A pointer to a point indicating the point around which dstrect will be rotated (if NULL, rotation will be done around dstrect.w/2, dstrect.h/2).
flip – An SDL_RendererFlip value stating which flipping actions should be performed on the texture

Returns:
0 on success, or -1 on error
*/
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &desRect, 0, 0, flip);
}
//Draw
void TextureManager::drawsame(std::string id, int x, int y, SDL_Renderer *pRenderer)
{
    //Two SDL Rectangle
    SDL_Rect srcRect;
    SDL_Rect desRect;
    SDL_QueryTexture( getTexture(id), NULL, NULL, &srcRect.w, &srcRect.h);
    // Simple dimension calculation
    srcRect.x = 0;
    srcRect.y = 0;
    desRect.w=srcRect.w ;
    desRect.h=srcRect.h;
    desRect.x = x;
    desRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &desRect, 0, 0, SDL_FLIP_NONE);
}
void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;

    //Simple Dimension Calculation
    //We need to update currentFrame and CurrentRow for animation in update function
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);

    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id)
{
    m_textureMap.erase(id);
}