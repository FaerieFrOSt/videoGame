
#ifndef _MENUSTATE_H_
# define _MENUSTATE_H_

#include "state.h"
#include <SFML/Graphics.hpp>
#include <vector>

class	MenuState : public State
{
	public:
		MenuState(StateStack& stack, Context context);

		virtual void	draw();
		virtual bool	update(sf::Time dt);
		virtual bool	handleEvent(const sf::Event& event);

	private:
		void	updateOptionText();
		enum	OptionNames
		{
			Play,
			Exit,
		};

		std::vector<sf::Text>	mOptions;
		std::size_t				mOptionIndex;
};

#endif /* !_MENUSTATE_H_ */
