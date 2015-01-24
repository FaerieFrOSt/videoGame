
#ifndef _ENTITY_H_
# define _ENTITY_H_

#include "scenenode.h"

class	Entity : public SceneNode
{
	public:
		void				setVelocity(sf::Vector2f velocity);
		void				setVelocity(float vx, float vy);
		sf::Vector2f		getVelocity() const;


	private:
		sf::Vector2f		mVelocity;
};


#endif /* !_ENTITY_H_ */
