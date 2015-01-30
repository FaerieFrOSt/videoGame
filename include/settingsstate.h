
#ifndef _SETTINGSSTATE_H_
# define _SETTINGSSTATE_H_

#include "state.h"
#include "statestack.h"
#include "gui/container.h"
#include <SFML/Graphics.hpp>
#include "gui/button.h"
#include "gui/label.h"
#include "player.h"
#include <memory>
#include <array>

class	SettingsState : public State
{
	public:
		SettingsState(StateStack& stack, Context context);

		virtual void	draw();
		virtual bool	update(sf::Time dt);
		virtual bool	handleEvent(const sf::Event& event);

	private:
		void	updateLabels();

	private:
		GUI::Container													mContainer;
		sf::Sprite														mBackgroundSprite;
		std::array<std::shared_ptr<GUI::Button>, Player::ActionCount>	mBindingButtons;
		std::array<std::shared_ptr<GUI::Label>, Player::ActionCount>	mBindingLabels;
};

#endif /* !_SETTINGSSTATE_H_ */
