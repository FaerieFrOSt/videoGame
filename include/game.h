
#ifndef _GAME_H_
# define _GAME_H_

#include <SFML/Graphics.hpp>
#include "world.h"

class	Game
{
	public:
		Game();
		void	run();

	private:
		void	processEvents();
		void	update(sf::Time dt);
		void	render();
		void	handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

		void	updateStatistics(sf::Time elapsedTime);

	private:
		sf::RenderWindow	mWindow;
		sf::Font			mFont;
		sf::Text			mStatisticsText;
		sf::Time			mStatisticsUpdateTime;
		std::size_t			mStatisticsNumFrames;
		bool				mIsMovingUp;
		bool				mIsMovingDown;
		bool				mIsMovingLeft;
		bool				mIsMovingRight;
		World				mWorld;
};

#endif /* !_GAME_H_ */
