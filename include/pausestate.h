
#ifndef _PAUSESTATE_H_
# define _PAUSESTATE_H_

#include "state.h"
#include "gui/container.h"

class	PauseState : public State
{
	public:
		PauseState(StateStack& stack, Context context);

		virtual void	draw();
		virtual bool	update(sf::Time dt);
		virtual bool	handleEvent(const sf::Event& event);

	private:
		GUI::Container	mContainer;
};

#endif /* !_PAUSESTATE_H_ */
