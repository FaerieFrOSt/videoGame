
#ifndef _GAME_H_
# define _GAME_H_

#include <SFML/Graphics.hpp>
#include "world.h"
#include "player.h"

class	Game
{
	public:
		Game();
		void	run();

	private:
		void	processInput();
		void	update(sf::Time dt);
		void	render();

		void	updateStatistics(sf::Time elapsedTime);

	private:
		sf::RenderWindow	mWindow;
		sf::Font			mFont;
		sf::Text			mStatisticsText;
		sf::Time			mStatisticsUpdateTime;
		std::size_t			mStatisticsNumFrames;
		World				mWorld;
		Player				mPlayer;
};

#endif /* !_GAME_H_ */
