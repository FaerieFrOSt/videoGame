
#ifndef _GAMESTATE_H_
# define _GAMESTATE_H_

#include "state.h"
#include "statestack.h"
#include "world.h"
#include "player.h"

class	GameState : public State
{
	public:
		GameState(StateStack& stack, Context context);

		virtual void	draw();
		virtual bool	update(sf::Time dt);
		virtual bool	handleEvent(const sf::Event& event);

	private:
		World	mWorld;
		Player	&mPlayer;
};

#endif /* !_GAMESTATE_H_ */
