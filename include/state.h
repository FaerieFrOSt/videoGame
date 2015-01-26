
#ifndef _STATE_H_
# define _STATE_H_

#include <memory>
#include <SFML/Graphics.hpp>
#include "stateidentifiers.h"
#include "texturesholder.h"
#include "fontholder.h"
#include "player.h"

class	StateStack;

class	State
{
	public:
		typedef std::unique_ptr<State>	Ptr;

		struct	Context
		{
			Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player) :
				window(&window), textures(&textures), fonts(&fonts), player(&player)
			{}

			sf::RenderWindow*	window;
			TextureHolder*		textures;
			FontHolder*			fonts;
			Player*				player;
		};

	public:
		State(StateStack& stack, Context context);
		virtual ~State();

		virtual void	draw() = 0;
		virtual bool	update(sf::Time dt) = 0;
		virtual bool	handleEvent(const sf::Event& event) = 0;

	protected:
		void	requestStackPush(States::ID stateID);
		void	requestStackPop();
		void	requestStackClear();

		Context	getContext() const;

	private:
		StateStack	*mStack;
		Context		mContext;
};

#endif /* !_STATE_H_ */
