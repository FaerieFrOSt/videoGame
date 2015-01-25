
#ifndef _COMMAND_H_
# define _COMMAND_H_

#include "scenenode.h"
#include <SFML/System.hpp>
#include <functional>
#include <queue>

class	SceneNode;

namespace	Category
{
	enum	Type
	{
		None = 0,
		Scene = 1 << 0,
		PlayerAircraft = 1 << 1,
		AlliedAircraft = 1 << 2,
		EnemyAircraft = 1 << 3
	};
}

struct	Command
{
	Command();

	std::function<void(SceneNode&, sf::Time)>	action;
	unsigned int	category;
};

class	CommandQueue
{
	public:
		void	push(const Command& command);
		Command	pop();
		bool	isEmpty() const;

	private:
		std::queue<Command>	mQueue;
};

#endif /* !_COMMAND_H_ */
