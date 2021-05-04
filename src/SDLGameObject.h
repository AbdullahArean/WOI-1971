#ifndef __SDLGameObject__
#define __SDLGameObject__
#include "Gameobject.h"

//Inherited class of GameObject 
class SDLGameObject : public GameObject
{
public:
    //Constructor using Loader Params
    SDLGameObject(const LoaderParams *pParams);
    //draw
    virtual void draw();
    //update
    virtual void update();
    //clean
    virtual void clean();

protected:
    //Private Variable
    int m_x;//x position
    int m_y;//y position

    int m_height; //height
    int m_width;//width

    std::string m_textureID; //Texture ID

    int m_CurrentFrame; //Current Frame
    int m_CurrentRow; //Current Row
};
#endif