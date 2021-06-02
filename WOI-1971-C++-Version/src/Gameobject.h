#ifndef __GameObject__
#define __GameObject__

#include "LoaderParams.cpp"
class GameObject //An Abstract Class to manage Game Object easily
{
public:
    virtual void draw() = 0;   //draw
    virtual void update() = 0; //update
    virtual void clean() = 0;  //clean

protected:
    //Constructor Using LoaderParams to Load game Object parameter
    GameObject(const LoaderParams *pParams) {}

    //virtaul destructor
    virtual ~GameObject() {}
};

#endif