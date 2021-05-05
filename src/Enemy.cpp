#include"Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{}
void Enemy::draw()
{
SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
m_x -= 1;
m_CurrentFrame = int(((SDL_GetTicks() / 100) % 1));
}
void Enemy::clean()
{
}