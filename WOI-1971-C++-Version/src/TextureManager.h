#ifndef __TextureManager__
#define __TextureManager__

#include "constants.h"


class TextureManager
{
    std::map<std::string, SDL_Texture *> m_textureMap; //A map to keep ID and SDL_Texture together

    static TextureManager *s_pInstance; //Making a TextureManager => Singleton Purpose

    TextureManager() {} //constructor
    ~TextureManager() {}//destructor

public:
    //Loading Image 
    bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer); 

    //draw
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    //drawFrame
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    //drawsame
    void drawsame(std::string id, int x, int y, SDL_Renderer *pRenderer);

    //Instance function=>Singleton
    static TextureManager *Instance()
    {
        if (s_pInstance == NULL)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }
    //will return our SDL_Texture
	SDL_Texture* getTexture(std::string id) { return m_textureMap[id]; }

    //function to remove a texture with specific texture ID
    void clearFromTextureMap(std::string id);
};

#endif /* defined(__TextureManager__)*/

/*Method to simply load , update and render with TextureManager

1.to load write it in init function
if (!TextureManager::Instance()->load("assets/a.png", "logo", m_pRenderer))
    {
        m_bRunning = FALSE;
    }
2. to Update
use update function in game.cpp to update 
3. to draw plce it in renderer function
TextureManager::Instance()->draw("a", 0,0, 120, 82,m_pRenderer);

*/