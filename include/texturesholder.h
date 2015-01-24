
#ifndef _TEXTURESHOLDER_H_
# define _TEXTURESHOLDER_H_

#include "resourceholder.h"

namespace	Textures
{
	enum 	ID
	{
		Eagle,
		Raptor,
	};
}

typedef ResourceHolder<sf::Texture, Textures::ID>	TextureHolder;


#endif /* !_TEXTURESHOLDER_H_ */
