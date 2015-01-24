
#ifndef _GAME_H_
# define _GAME_H_

#include <SFML/Graphics.hpp>

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

	private:
		sf::RenderWindow	mWindow;
		sf::Sprite			mPlayer;
		sf::Texture			mTexture;
		bool				mIsMovingUp;
		bool				mIsMovingDown;
		bool				mIsMovingLeft;
		bool				mIsMovingRight;
};

#endif /* !_GAME_H_ */
