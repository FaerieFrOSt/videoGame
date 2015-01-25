#include "entity.h"


void	Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void	Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f	Entity::getVelocity() const
{
	return mVelocity;
}

void	Entity::updateCurrent(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}

void	Entity::accelerate(sf::Vector2f velocity)
{
	setVelocity(getVelocity() + velocity);
}

void	Entity::accelerate(float vx, float vy)
{
	setVelocity(getVelocity().x + vx, getVelocity().y + vy);
}
