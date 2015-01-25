
#ifndef _ENTITY_H_
# define _ENTITY_H_

#include "scenenode.h"
#include <cassert>

class	Entity : public SceneNode
{
	public:
		void				setVelocity(sf::Vector2f velocity);
		void				setVelocity(float vx, float vy);
		sf::Vector2f		getVelocity() const;

		void				accelerate(sf::Vector2f velocity);
		void				accelerate(float vx, float vy);

	private:
		virtual void	updateCurrent(sf::Time dt);

	private:
		sf::Vector2f		mVelocity;
};

template<typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)>	derivedAction(Function fn)
{
	return [=] (SceneNode& node, sf::Time dt)
	{
		assert(dynamic_cast<GameObject*>(&node) != nullptr);
		fn(static_cast<GameObject&>(node), dt);
	};
}

#endif /* !_ENTITY_H_ */
