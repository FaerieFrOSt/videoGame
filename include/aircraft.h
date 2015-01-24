
#ifndef _AIRCRAFT_H_
# define _AIRCRAFT_H_

#include "entity.h"
#include "texturesholder.h"

class	Aircraft : public Entity
{
	public:
		enum 	Type
		{
			Eagle,
			Raptor,
		};

		Aircraft(Type type, const TextureHolder& textures);

		virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		Type		mType;
		sf::Sprite	mSprite;
};

Textures::ID	toTextureID(Aircraft::Type type);

#endif /* !_AIRCRAFT_H_ */
