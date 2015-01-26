
#ifndef _TITLESTATE_H_
# define _TITLESTATE_H_

#include "state.h"
#include <SFML/Graphics.hpp>

class	TitleState : public State
{
	public:
		TitleState(StateStack& stack, Context context);

		virtual void	draw();
		virtual bool	update(sf::Time dt);
		virtual bool	handleEvent(const sf::Event& event);

	private:
		sf::Sprite	mBackgroundSprite;
		sf::Text	mText;
		bool		mShowText;
		sf::Time	mTextEffectTime;
};

#endif /* !_TITLESTATE_H_ */
