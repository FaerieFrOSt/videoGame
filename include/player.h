
#ifndef _PLAYER_H_
# define _PLAYER_H_

#include <SFML/System.hpp>
#include "command.h"

class	Player
{
	public:
		void	handleEvent(const sf::Event& event, CommandQueue& commands);
		void	handleRealtimeInput(CommandQueue& commands);
};

#endif /* !_PLAYER_H_ */
