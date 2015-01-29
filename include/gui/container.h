
#ifndef _CONTAINER_H_
# define _CONTAINER_H_

#include "gui/component.h"
#include <vector>

namespace	GUI
{
	class	Container : public Component
	{
		public:
			Container();

			void			pack(Component::Ptr component);
			virtual bool	isSelectable() const;
			virtual void	handleEvent(const sf::Event& event);

		private:
			virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
			void			select_private(std::size_t index);
			void			selectPrevious();
			void			selectNext();
			bool			hasSelection() const;

		private:
			std::vector<Component::Ptr>	mChildren;
			int							mSelectedChild;
	};
}

#endif /* !_CONTAINER_H_ */
