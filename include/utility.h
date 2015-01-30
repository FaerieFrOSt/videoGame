
#ifndef _UTILITY_H_
# define _UTILITY_H_

#include <SFML/Graphics.hpp>

template <typename T>
void	centerOrigin(T& t)
{
	sf::FloatRect bounds = t.getLocalBounds();
	t.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

const char *getKeyName( const sf::Keyboard::Key key );

#endif /* !_UTILITY_H_ */
