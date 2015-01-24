
#ifndef _SPRITENODE_H_
# define _SPRITENODE_H_

#include "scenenode.h"

class	SpriteNode : public SceneNode
{
	public:
		explicit	SpriteNode(const sf::Texture& texture);

		SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);

	private:
		virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Sprite	mSprite;
};

#endif /* !_SPRITENODE_H_ */
