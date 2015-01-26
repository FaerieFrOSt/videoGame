
#ifndef _APPLICATION_H_
# define _APPLICATION_H_

#include "statestack.h"

class	Application
{
	public:
		Application();
		void	run();

	private:
		void	registerStates();
		void	processInput();

		void	update(sf::Time dt);
		void	render();

	private:
		static const sf::Time	TimePerFrame;

		void	updateStatistics(sf::Time elapsedTime);

		sf::RenderWindow		mWindow;
		TextureHolder			mTextures;
		FontHolder				mFonts;
		Player					mPlayer;

		StateStack				mStateStack;

		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t				mStatisticsNumFrames;
};

#endif /* !_APPLICATION_H_ */
