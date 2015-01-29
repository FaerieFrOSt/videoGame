
#ifndef _MENUSTATE_H_
# define _MENUSTATE_H_

#include "state.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "gui/container.h"

class	MenuState : public State
{
	public:
		MenuState(StateStack& stack, Context context);

		virtual void	draw();
		virtual bool	update(sf::Time dt);
		virtual bool	handleEvent(const sf::Event& event);

	private:
		GUI::Container	mContainer;
		sf::Sprite		mBackgroundSprite;
};

#endif /* !_MENUSTATE_H_ */
