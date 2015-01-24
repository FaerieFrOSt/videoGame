#include "aircraft.h"

Aircraft::Aircraft(Type type, const TextureHolder& textures) : mType(type), mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect	bounds = mSprite.getLocalBounds();

	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void	Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
