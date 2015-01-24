
#ifndef _SCENENODE_H_
# define _SCENENODE_H_

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class	SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
	public:
		typedef	std::unique_ptr<SceneNode>	Ptr;

	public:
		SceneNode();

		void	attachChild(Ptr child);
		Ptr		detachChild(const SceneNode& node);

	private:
		virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		std::vector<Ptr>	mChildren;
		SceneNode			*mParent;
};

#endif /* !_SCENENODE_H_ */
