#ifndef __LoaderParams__
#define __LoaderParams__

#include"constants.h"

// A class to load the parameter for GameObject class
class LoaderParams
{
public:
    //Constructor of LoaderParam Function
    LoaderParams(int x, int y, int width, int height, std::string textureID)
    {
        m_x=x;
        m_y=y; 
        m_width=width;
        m_height =height;
        m_textureID=textureID;

    }

    int getX() const{ return m_x;} //return x position of object
    int getY() const{return m_y;}//return y position of object
    int getWidth() const {return m_width;}//return width of object
    int getHeight() const{ return m_height;}//return height of object
    std::string getTextureID() const {return m_textureID;} //return TextureID

private:
    //Private Variable
    int m_x;//x position
    int m_y;//y position

    int m_height; //height
    int m_width;//width

    std::string m_textureID; //Texture ID

    //Still not used in Loader Params
    int m_CurrentFrame; //Current Frame
    int m_CurrentRow; //Current Row

};
#endif

