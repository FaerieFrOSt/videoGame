
#ifndef _PLAYER_H_
# define _PLAYER_H_

#include <SFML/System.hpp>
#include "command.h"

class	Player
{
	public:
		enum	Action
		{
			MoveLeft,
			MoveRight,
			MoveUp,
			MoveDown,
			Debug,
		};

		Player();
		void	handleEvent(const sf::Event& event, CommandQueue& commands);
		void	handleRealtimeInput(CommandQueue& commands);

		void				assignKey(Action action, sf::Keyboard::Key key);
		sf::Keyboard::Key	getAssignedKey(Action action) const;

		bool	isRealtimeAction(Action action) const;

	private:
		static bool	isRealTimeAction(Action action);

	private:
		std::map<sf::Keyboard::Key, Action>	mKeyBinding;
		std::map<Action, Command>	mActionBinding;
};

#endif /* !_PLAYER_H_ */
