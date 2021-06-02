#include"Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{}
void Player::draw()
{
SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
m_x -= 1;
m_CurrentFrame = int(((SDL_GetTicks() / 100) % 1));
}
void Player::clean()
{
}