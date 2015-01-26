
#ifndef _FONTHOLDER_H_
# define _FONTHOLDER_H_

#include "resourceholder.h"

namespace	Fonts
{
	enum 	ID
	{
		Main,
	};
}

typedef ResourceHolder<sf::Font, Fonts::ID>	FontHolder;


#endif /* !_FONTHOLDER_H_ */
