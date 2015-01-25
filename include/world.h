
#ifndef _WORLD_H_
# define _WORLD_H_

#include <SFML/Graphics.hpp>
#include "texturesholder.h"
#include "scenenode.h"
#include "aircraft.h"
#include "command.h"
#include <array>

class	World : private sf::NonCopyable
{
	public:
		explicit	World(sf::RenderWindow& window);

		void			update(sf::Time dt);
		void			draw();
		CommandQueue&	getCommandQueue();

	private:
		void	loadTextures();
		void	buildScene();

	private:
		enum	Layer
		{
			Background,
			Air,
			LayerCount
		};

	private:
		sf::RenderWindow&					mWindow;
		sf::View							mWorldView;
		TextureHolder						mTextures;
		SceneNode							mSceneGraph;
		CommandQueue						mCommandQueue;

		std::array<SceneNode*, LayerCount>	mSceneLayers;
		sf::FloatRect						mWorldBounds;
		sf::Vector2f						mSpwanPosition;
		float								mScrollSpeed;
		Aircraft							*mPlayerAircraft;
};

#endif /* !_WORLD_H_ */
