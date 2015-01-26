
#ifndef _PAUSESTATE_H_
# define _PAUSESTATE_H_

#include "state.h"

class	PauseState : public State
{
	public:
		PauseState(StateStack& stack, Context context);

		virtual void	draw();
		virtual bool	update(sf::Time dt);
		virtual bool	handleEvent(const sf::Event& event);

	private:
		sf::Text	mPausedText;
		sf::Text	mInstructionText;
};

#endif /* !_PAUSESTATE_H_ */
